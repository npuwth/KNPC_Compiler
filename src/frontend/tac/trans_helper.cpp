/*****************************************************
 *  Implementation of the "TransHelper" class.
 *
 */

#include "trans_helper.hpp"
#include "tac.hpp"
#include "../../backend/asm/mach_desc.hpp"
#include "../../backend/asm/offset_counter.hpp"
#include "../../util/config.hpp"
#include "../scope/scope.hpp"
#include "../scope/scope_stack.hpp"
#include "../symb/symbol.hpp"

#include <cstdio>
#include <cstring>
#include <sstream>

using namespace knpc;
using namespace knpc::tac;
using namespace knpc::symb;
using namespace knpc::scope;
using namespace knpc::assembly;

/* Appends a Tac node to the current TAC list.
 *
 * PARAMETERS:
 *   t    - the Tac node
 * NOTE:
 *   a private function
 */
void TransHelper::chainUp(Tac *t) {
    t->prev = tacs_tail;

    if (NULL == tacs) // tacs is head , tacs_tail is tail
        tacs_tail = tacs = t;
    else
        tacs_tail = tacs_tail->next = t;
}

/******************** public methods *********************/

/* Constructs a tranlsation helper.
 *
 */
TransHelper::TransHelper(MachineDesc *md) { // init piece list and tac list 
    knpc_assert(NULL != md);

    mach = md;
    ptail = &head;
    head.next = NULL;
    tacs = tacs_tail = NULL;
    current = NULL;
    var_count = label_count = 0;
    startup_ok = false;
}

/* Gets the offset counter of the target machine.
 *
 * RETURNS:
 *   the offset counter of the target machine
 */
OffsetCounter *TransHelper::getOffsetCounter(void) {
    return mach->getOffsetCounter();
}

/* Allocates a new temporary variable (int32 or float32).
 *
 * RETURNS:
 *   the newly created temporary variable
 * NOTE:
 *   we use the variable index to avoid name crash.
 */
Temp TransHelper::getNewTempI4(void) {
    Temp v = new TempVariable();
    v->id = var_count++;
    v->size = 4;
    v->offset = 0;
    v->is_offset_fixed = false;
    v->ctval = 0;
    v->ctvalf = 0.0;
    v->isFloat = false;
    v->isConst = false;
    return v;
}

/* Allocates a new temporary int32 pointer.
 *
 * RETURNS:
 *   the newly created temporary pointer
 * NOTE:
 *   we use the variable index to avoid name crash.
 */
Temp TransHelper::allocNewTempI4(int size) {
    Temp v = getNewTempI4();
    chainUp(Tac::Alloc(v, size));
    return v;
}

/* Allocates a new label.
 *
 * RETURNS:
 *   the newly created label
 * NOTE:
 *   we use the label index to avoid name crash.
 */
Label TransHelper::getNewLabel(void) {
    Label l = new LabelObject();
    l->id = label_count++;
    l->str_form = std::string(); // 0 means using the default label name
    l->target = false;

    return l;
}

/* Creates a new Label object for the function entry.
 *
 * PARAMETERS:
 *   fn   - the function (symb::Function)
 * RETURNS:
 *   the entry label object
 */
Label TransHelper::getNewEntryLabel(Function *fn) {
    knpc_assert(NULL != fn);
    std::string fn_name = fn->getName();

    Label l = new LabelObject();
    l->id = label_count++;
    l->str_form = fn_name;
    l->target = true; // such label is referenced by virtual tables

    return l;
}

Label TransHelper::getNewEntryLabel(std::string name) {
    Label l = new LabelObject();
    l->id = label_count++;
    l->str_form = name;
    l->target = true; // such label is referenced by virtual tables

    return l;
}

/* Creates a Memo tac about the function parameters.
 *
 * PARAMETERS:
 *   f - a Function object
 * RETURNS:
 *   the Memo tac
 * NOTE:
 *   Memo is not operating Tac, i.e. it serves as comments.
 *   this function also fix the offset of the temp vars of the parameters.
 */
Tac *TransHelper::memoOf(Function *f) {
    std::ostringstream oss;
    FuncScope *scope = f->getAssociatedScope();

    for (Scope::iterator it = scope->begin(); it != scope->end(); ++it) {
        Variable *v = (Variable *)*it;

        if (v->isParameter()) {
            Temp t = v->getTemp();

            knpc_assert(NULL != t); // it should have been created in TransPass1
            t->param_ord = v->getOrder() + 1;
            if (t->param_ord <= 4) {
                oss << t << ": A" << t->param_ord << " ";
                t->is_offset_fixed = false;
            } else {
                oss << t << ": " << t->offset - 16 << " ";
                t->offset = v->offset - 16;
                t->is_offset_fixed = true;
            }
        }
    }

    int length = oss.str().size();
    char *memo = new char[length + 1];
    *memo = '\0'; // Or memo may be uninitialized.
    oss.str().copy(memo, length);

    return (Tac::Memo(memo));
}

/* Starts the procession of a Function object.
 *
 * PARAMETERS:
 *   f    - the Function object
 * NOTE:
 *   the newly created Functy object will be chained up into the Piece list
 */
void TransHelper::startFunc(Function *f) {
    knpc_assert(NULL != f && NULL == current); // non-reentrant

    Label entry = f->getEntryLabel();
    knpc_assert(NULL != entry); // it should have been created in TransPass1

    ptail = ptail->next = new Piece();
    ptail->kind = Piece::FUNCTY;
    ptail->as.functy = new FunctyObject();
    ptail->as.functy->entry = entry;
    current = f;

    // generates a memorandum line
    chainUp(memoOf(f));

    // generates entry label
    genMarkLabel(entry);
}

/* Ends the procession of the current Function object.
 *
 * NOTE:
 *   the newly created Functy object will be attached to the Function object
 */
void TransHelper::endFunc(void) {
    // does things automatically
    ptail->as.functy->code = tacs;
    tacs = tacs_tail = NULL;
    current->attachFuncty(ptail->as.functy);
    current = NULL;
}

void TransHelper::genGlobalVarible(std::string name, int value, int size, bool isConst) {
    ptail = ptail->next = new Piece();
    ptail->kind = Piece::GLOBAL;
    ptail->as.globalVar = new GlobalObject();
    ptail->as.globalVar->name = name;
    ptail->as.globalVar->value = value;
    ptail->as.globalVar->size = size;
    ptail->as.globalVar->isConst = isConst;
}

void TransHelper::genGlobalVaribleF(std::string name, float value, int size, bool isConst) {
    ptail = ptail->next = new Piece();
    ptail->kind = Piece::GLOBALF;
    ptail->as.globalVarF = new GlobalObjectF();
    ptail->as.globalVarF->name = name;
    ptail->as.globalVarF->value = value;
    ptail->as.globalVarF->size = size;
    ptail->as.globalVarF->isConst = isConst;
}

void TransHelper::genGlobalArray(std::string name, util::Vector<int> values, int size, bool isConst) {
    ptail = ptail->next = new Piece();
    ptail->kind = Piece::GLOARR;
    ptail->as.globalArr = new GlobalArray();
    ptail->as.globalArr->name = name;
    ptail->as.globalArr->values = values;
    ptail->as.globalArr->size = size;
    ptail->as.globalArr->isConst = isConst;
}

void TransHelper::genGlobalArrayF(std::string name, util::Vector<float> values, int size, bool isConst) {
    ptail = ptail->next = new Piece();
    ptail->kind = Piece::GLOARRF;
    ptail->as.globalArrF = new GlobalArrayF();
    ptail->as.globalArrF->name = name;
    ptail->as.globalArrF->values = values;
    ptail->as.globalArrF->size = size;
    ptail->as.globalArrF->isConst = isConst;
}

/* Appends an Add tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a + b)
 */
Temp TransHelper::genAdd(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Add(c, a, b));
    return c;
}

/* Appends a Sub tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a - b)
 */
Temp TransHelper::genSub(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Sub(c, a, b));
    return c;
}

/* Appends a Mul tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a * b)
 */
Temp TransHelper::genMul(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Mul(c, a, b));
    return c;
}

/* Appends a Div tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a / b)
 */
Temp TransHelper::genDiv(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Div(c, a, b));
    return c;
}

/* Appends a Mod tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a % b)
 */
Temp TransHelper::genMod(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Mod(c, a, b));
    return c;
}

/* Appends a Equ tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a == b)
 */
Temp TransHelper::genEqu(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Equ(c, a, b));
    return c;
}

/* Appends a Neq tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a != b)
 */
Temp TransHelper::genNeq(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Neq(c, a, b));
    return c;
}

/* Appends a Les tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a < b)
 */
Temp TransHelper::genLes(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Les(c, a, b));
    return c;
}

/* Appends a Leq tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a <= b)
 */
Temp TransHelper::genLeq(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Leq(c, a, b));
    return c;
}

/* Appends a Gtr tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a > b)
 */
Temp TransHelper::genGtr(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Gtr(c, a, b));
    return c;
}

/* Appends a Geq tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a >= b)
 */
Temp TransHelper::genGeq(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::Geq(c, a, b));
    return c;
}

/* Appends a Neg tac node to the current list.
 *
 * PARAMETERS:
 *   src  - operand
 * RETURNS:
 *   the temporary containing the result of (-src)
 */
Temp TransHelper::genNeg(Temp src) {
    Temp c = getNewTempI4();
    chainUp(Tac::Neg(c, src));
    return c;
}

/* Appends a LAnd tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a && b)
 */
Temp TransHelper::genLAnd(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::LAnd(c, a, b));
    return c;
}

/* Appends a LOr tac node to the current list.
 *
 * PARAMETERS:
 *   a    - operand 1
 *   b    - operand 2
 * RETURNS:
 *   the temporary containing the result of (a || b)
 */
Temp TransHelper::genLOr(Temp a, Temp b) {
    Temp c = getNewTempI4();
    chainUp(Tac::LOr(c, a, b));
    return c;
}

/* Appends a LNot tac node to the current list.  logical not
 *
 * PARAMETERS:
 *   src  - operand
 * RETURNS:
 *   the temporary containing the result of (!src)
 */
Temp TransHelper::genLNot(Temp src) {
    Temp c = getNewTempI4();
    chainUp(Tac::LNot(c, src));
    return c;
}

/* Appends a BNot tac node to the current list.  bitwise not
 *
 * PARAMETERS:
 *   src  - operand
 * RETURNS:
 *   the temporary containing the result of (!src)
 */
Temp TransHelper::genBNot(Temp src) {
    Temp c = getNewTempI4();
    chainUp(Tac::BNot(c, src));
    return c;
}

/* Appends a Pop tac node to the current list.
 *
 * RETURNS:
 *   the temporary containing the result of the newly poped value
 */
Temp TransHelper::genPop(void) {
    Temp c = getNewTempI4();
    chainUp(Tac::Pop(c));
    return c;
}

/* Appends a Push tac node to the current list.
 *
 * PARAMETERS:
 *   src  - the value to be pushed into the stack
 */
void TransHelper::genPush(Temp src) { chainUp(Tac::Push(src)); }

Temp TransHelper::genCall(Label label) {
    Temp c = getNewTempI4(); // TODO: float
    chainUp(Tac::Call(c, label));
    return c;
}

void TransHelper::genParam(Temp dest) { chainUp(Tac::Param(dest)); }

/* Appends a Jump tac node to the current list.
 *
 * PARAMETERS:
 *   dest - destination label
 * NOTE:
 *   this is unconditional jump
 */
void TransHelper::genJump(Label dest) { chainUp(Tac::Jump(dest)); }

/* Appends a JZero tac node to the current list.
 *
 * PARAMETERS:
 *   dest - destination label
 *   cond - jump condition
 * NOTE:
 *   this is conditional jump
 */
void TransHelper::genJumpOnZero(Label dest, Temp cond) {
    chainUp(Tac::JZero(dest, cond));
}

/* Appends a Return tac node to the current list.
 *
 * PARAMETERS:
 *   value - return value
 * NOTE:
 *   this operation also terminates the current function execution
 */
void TransHelper::genReturn(Temp value) { chainUp(Tac::Return(value)); }

/* Appends an Assign tac node to the current list.
 *
 * PARAMETERS:
 *   dest  - target variable
 *   src   - source variable
 */
void TransHelper::genAssign(Temp dest, Temp src) {
    chainUp(Tac::Assign(dest, src));
}

/* Appends a LoadImm4 tac node to the current list.
 *
 * PARAMETERS:
 *   value - int32 immediate number
 * RETURNS:
 *   the temporary with the immediate number loaded
 */
Temp TransHelper::genLoadImm4(int value) {
    Temp c = getNewTempI4();
    c->isConst = true;
    c->ctval = value;
    chainUp(Tac::LoadImm4(c, value));
    return c;
}

Temp TransHelper::genLoadImm4F(float value) {
    Temp c = getNewTempI4();
    c->isConst = true;
    c->isFloat = true;
    c->ctvalf = value;
    chainUp(Tac::LoadImm4F(c, value));
    return c;
}

Temp TransHelper::genLoadImm4NoChainUp(int value) { // used when get array initvals to pad zeroes
    Temp c = getNewTempI4();
    c->isConst = true;
    c->ctval = value;
    return c;
}

Temp TransHelper::genLoadImm4FNoChainUp(float value) { // used when get array initvals to pad zeroes
    Temp c = getNewTempI4();
    c->isConst = true;
    c->isFloat = true;
    c->ctvalf = value;
    return c;
}

Temp TransHelper::genLoadSymbol(std::string label){
    Temp c = getNewTempI4();
    chainUp(Tac::LoadSymbol(c, label));
    return c;
}

Temp TransHelper::genLoad(Temp temp, int offset){
    Temp c = getNewTempI4();
    chainUp(Tac::Load(c, temp, offset));
    return c;
}

void TransHelper::genStore(Temp src, Temp base, int offset){
    chainUp(Tac::Store(src, base, offset));
}

/* Appends a MarkLabel tac node to the current list.
 *
 * PARAMETERS:
 *   label - Label object
 * NOTE:
 *   "marking a label" means pointing out the location of the label in the tac
 * list
 */
void TransHelper::genMarkLabel(Label label) { chainUp(Tac::Mark(label)); }

/* Appends a Memo tac node to the current list.
 *
 * PARAMETERS:
 *   comment - the comment line of the memo (please use string literal, e.g.
 * "This is comment") NOTE: memorandum can serve as comment in TAC sequence
 */
void TransHelper::genMemo(const char *comment) { chainUp(Tac::Memo(comment)); }

/* Retrieves the entire Piece list.
 *
 * RETURNS:
 *   the Piece list (representing as a single linked list)
 */
Piece *TransHelper::getPiece(void) { return head.next; }
