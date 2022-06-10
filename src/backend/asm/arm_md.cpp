/*****************************************************
 *  Implementation of ArmDesc.
 *
 */

#include "asm/arm_md.hpp"
#include "3rdparty/set.hpp"
#include "asm/offset_counter.hpp"
#include "asm/arm_frame_manager.hpp"
#include "config.hpp"
#include "options.hpp"
#include "scope/scope.hpp"
#include "symb/symbol.hpp"
#include "tac/flow_graph.hpp"
#include "tac/tac.hpp"

#include <cstring>
#include <iomanip>
#include <sstream>

using namespace knpc::assembly;
using namespace knpc::tac;
using namespace knpc::util;
using namespace knpc;

// declaration of empty string
#define EMPTY_STR std::string()
#define WORD_SIZE 4

/* Constructor of ArmReg.
 *
 * PARAMETERS:
 *   reg_name   - name of this register
 *   is_general - whether this register is a general-purpose one
 */
ArmReg::ArmReg(const char *reg_name, bool is_general) {
    name = reg_name;
    dirty = false;
    var = NULL;
    general = is_general;
}

/* Constructor of ArmDesc.
 *
 */
ArmDesc::ArmDesc(void) {
    // {GLOBAL, LOCAL, PARAMETER}
    // Actually, we only use the parameter offset counter,
    // other two options are remained for extension
    int start[3] = {0, 0, 0}; 
    int dir[3] = {+1, -1, +1};
    _counter = new OffsetCounter(start, dir);

    // initializes the register vector
    // (we regard all general-purpose registers as caller-saved, which is
    // different from the Arm specification)
    _reg[ArmReg::A1] = new ArmReg("a1", false); // argument, return value
    _reg[ArmReg::A2] = new ArmReg("a2", false); // argument
    _reg[ArmReg::A3] = new ArmReg("a3", false); // argument
    _reg[ArmReg::A4] = new ArmReg("a4", false); // argument
    _reg[ArmReg::V1] = new ArmReg("v1", true);
    _reg[ArmReg::V2] = new ArmReg("v2", true);
    _reg[ArmReg::V3] = new ArmReg("v3", true);
    _reg[ArmReg::V4] = new ArmReg("v4", true);
    _reg[ArmReg::V5] = new ArmReg("v5", true);
    _reg[ArmReg::V6] = new ArmReg("v6", true);
    _reg[ArmReg::V7] = new ArmReg("v7", true);
    _reg[ArmReg::FP] = new ArmReg("fp", false);
    _reg[ArmReg::IP] = new ArmReg("ip", false);
    _reg[ArmReg::SP] = new ArmReg("sp", false);
    _reg[ArmReg::LR] = new ArmReg("lr", false);
    _reg[ArmReg::PC] = new ArmReg("pc", false);

    _lastUsedReg = 0;
    _label_counter = 0;
}

/* Gets the offset counter for this machine.
 *
 * RETURNS:
 *   the offset counter for Arm
 */
OffsetCounter *ArmDesc::getOffsetCounter(void) { return _counter; }

/* Translates the given Piece list into assembly code and output.
 *
 * PARAMETERS:
 *   ps    - the Piece list
 *   os    - the output stream
 */
void ArmDesc::emitPieces(scope::GlobalScope *gscope, Piece *ps,
                           std::ostream &os) {

    _result = &os;
    // output to .data and .bss segment
    std::ostringstream _data, _bss;

    if (Option::getLevel() == Option::ASMGEN) {
        // program preamble
        emit(EMPTY_STR, ".text", NULL);
        emit(EMPTY_STR, ".globl main", NULL);
        emit(EMPTY_STR, ".align 2", NULL);
    }
    // translates node by node
    while (NULL != ps) {
        switch (ps->kind) {
        case Piece::FUNCTY:
            emitFuncty(ps->as.functy);
            break;

        case Piece::GLOBAL:
            emit(EMPTY_STR, ".data", NULL);
            emit(EMPTY_STR, ((std::string)(".global ") + ps->as.globalVar->name).c_str(), NULL);
            emit(EMPTY_STR, ((std::string)(".size ") + ps->as.globalVar->name + (std::string)(", ") + std::to_string(ps->as.globalVar->size)).c_str(), NULL);
            emit(ps->as.globalVar->name.c_str(), NULL, NULL);
            if(ps->as.globalVar->value != 0){
                emit(EMPTY_STR, ((std::string)(".word ") + std::to_string(ps->as.globalVar->value)).c_str(), NULL);
            }
            else emit(EMPTY_STR, ((std::string)(".zero ") + std::to_string(ps->as.globalVar->size)).c_str(), NULL);
            break;

        case Piece::GLOARR:
            if(ps->as.globalArr->values.size() > 0) {
                emit(EMPTY_STR, ".data", NULL);
                emit(EMPTY_STR, ((std::string)(".global ") + ps->as.globalArr->name).c_str(), NULL);
                emit(EMPTY_STR, ((std::string)(".size ") + ps->as.globalArr->name + (std::string)(", ") + std::to_string(ps->as.globalArr->size)).c_str(), NULL);
                emit(ps->as.globalArr->name.c_str(), NULL, NULL);
                for(size_t i = 0; i < ps->as.globalArr->values.size(); i++) {
                    emit(EMPTY_STR, ((std::string)(".word ") + std::to_string(ps->as.globalArr->values[i])).c_str(), NULL);
                }
            } else {
                emit(EMPTY_STR, ".bss", NULL);
                emit(EMPTY_STR, ((std::string)(".global ") + ps->as.globalArr->name).c_str(), NULL);
                emit(EMPTY_STR, ((std::string)(".size ") + ps->as.globalArr->name + (std::string)(", ") + std::to_string(ps->as.globalArr->size)).c_str(), NULL);
                emit(ps->as.globalArr->name.c_str(), NULL, NULL);
                emit(EMPTY_STR, ((std::string)(".space ") + std::to_string(ps->as.globalArr->size)).c_str(), NULL);
            }
            break;

        default:
            knpc_assert(false); // unreachable
            break;
        }

        ps = ps->next;
    }
}

/* Allocates a new label (for a basic block).
 *
 * RETURNS:
 *   a new label guaranteed to be non-conflict with the existing ones
 */
const char *ArmDesc::getNewLabel(void) {
    knpc_assert(_label_counter < 10000);

    char *buf = new char[10];
    std::sprintf(buf, "__LL%d", _label_counter++);

    return buf;
}

/* Translates a single basic block into Arm instructions.
 *
 * PARAMETERS:
 *   b     - the basic block to translate
 *   g     - the control-flow graph
 * RETURNS:
 *   the Arm instruction sequence of this basic block
 */
ArmInstr *ArmDesc::prepareSingleChain(BasicBlock *b, FlowGraph *g) {
    ArmInstr leading;
    int r0;

    _tail = &leading;
    for (Tac *t = b->tac_chain; t != NULL; t = t->next)
        emitTac(t);
    
    switch (b->end_kind) {
    case BasicBlock::BY_JUMP:
        spillDirtyRegs(b->LiveOut);
        addInstr(ArmInstr::J, NULL, NULL, NULL, 0,
                 std::string(g->getBlock(b->next[0])->entry_label), EMPTY_STR);
        // "B" for "branch"
        break;

    case BasicBlock::BY_JZERO:
        r0 = getRegForRead(b->var, 0, b->LiveOut);
        spillDirtyRegs(b->LiveOut);
        // uses "branch if equal to zero" instruction
        addInstr(ArmInstr::TEQZ, NULL, _reg[r0], NULL, 0,
                 std::string(g->getBlock(b->next[0])->entry_label), EMPTY_STR);
        addInstr(ArmInstr::BEQ, NULL, NULL, NULL, 0,
                 std::string(g->getBlock(b->next[0])->entry_label), EMPTY_STR);
        addInstr(ArmInstr::J, NULL, NULL, NULL, 0,
                 std::string(g->getBlock(b->next[1])->entry_label), EMPTY_STR);
        break;

    case BasicBlock::BY_RETURN:
        r0 = getRegForRead(b->var, 0, b->LiveOut);
        spillDirtyRegs(b->LiveOut); // just to deattach all temporary variables
        addInstr(ArmInstr::MV, _reg[ArmReg::A1], _reg[r0], NULL, 0,
                 EMPTY_STR, EMPTY_STR);
        addInstr(ArmInstr::MV, _reg[ArmReg::SP], _reg[ArmReg::FP], NULL,
                 0, EMPTY_STR, EMPTY_STR);
        addInstr(ArmInstr::LW, _reg[ArmReg::LR], _reg[ArmReg::FP], NULL,
                 -4, EMPTY_STR, EMPTY_STR);
        addInstr(ArmInstr::LW, _reg[ArmReg::FP], _reg[ArmReg::FP], NULL,
                 -8, EMPTY_STR, EMPTY_STR);
        addInstr(ArmInstr::RET, NULL, NULL, NULL, 0, EMPTY_STR, EMPTY_STR);
        break;

    default:
        knpc_assert(false); // unreachable
    }
    _tail = NULL;
    return leading.next;
}

/* Translates a single TAC into Arm instructions (and records the result.
 *
 * PARAMETERS:
 *   t     - the TAC to translate
 * SIDE-EFFECT:
 *   modifies the "_tail" field
 */
void ArmDesc::emitTac(Tac *t) {
    std::ostringstream oss;
    t->dump(oss);
    addInstr(ArmInstr::COMMENT, NULL, NULL, NULL, 0, EMPTY_STR, oss.str());
    switch (t->op_code) {
    case Tac::LOAD_IMM4:
        emitLoadImm4Tac(t);
        break;

    case Tac::BNOT:
        emitUnaryTac(ArmInstr::NOT, t);
        break;

    case Tac::LNOT:
        emitUnaryTac(ArmInstr::TEQZ, t); // 与0相等测试
        emitUnaryTac(ArmInstr::SEQ, t);
        emitUnaryTac(ArmInstr::CNE, t);
        break;
    
    case Tac::NEG:
        emitUnaryTac(ArmInstr::NEG, t);
        break;

    case Tac::EQU:
        emitBinaryTac(ArmInstr::SUBS, t);
        emitUnaryTac(ArmInstr::SEQ, t);
        emitUnaryTac(ArmInstr::CNE, t);
        break;
    
    case Tac::NEQ:
        emitBinaryTac(ArmInstr::SUBS, t);
        emitUnaryTac(ArmInstr::SNE, t);
        emitUnaryTac(ArmInstr::CEQ, t);
        break;
        
    case Tac::LES:
	    emitBinaryTac(ArmInstr::SUBS, t);
	    emitUnaryTac(ArmInstr::SLT, t);
	    emitUnaryTac(ArmInstr::CGE, t);
        break;

    case Tac::LEQ:
	    emitBinaryTac(ArmInstr::SUBS, t);
	    emitUnaryTac(ArmInstr::SLE, t);
	    emitUnaryTac(ArmInstr::CGT, t);
        break;

    case Tac::GEQ:
        emitBinaryTac(ArmInstr::SUBS, t);
        emitUnaryTac(ArmInstr::SGE, t);
        emitUnaryTac(ArmInstr::CLT, t);
        break;

    case Tac::GTR:
        emitBinaryTac(ArmInstr::SUBS, t);
        emitUnaryTac(ArmInstr::SGT, t);
        emitUnaryTac(ArmInstr::CLE, t);
        break;
    
    case Tac::LAND:
        emitBinaryTac(ArmInstr::AND, t);
        break;
    
    case Tac::LOR:
        emitBinaryTac(ArmInstr::OR, t);
        break;
    
    case Tac::ADD:
        emitBinaryTac(ArmInstr::ADD, t);
        break;
    
    case Tac::SUB:
        emitBinaryTac(ArmInstr::SUB, t);
        break;
    
    case Tac::MUL:
        emitBinaryTac(ArmInstr::MUL, t);
        break;
    
    case Tac::DIV:
        emitBinaryTac(ArmInstr::DIV, t);
        break;

    case Tac::MOD:
        emitBinaryTac(ArmInstr::DIV, t);
        emitBinaryTac(ArmInstr::INPLACE_MLS, t);
        break;

    case Tac::ASSIGN:
        emitUnaryTac(ArmInstr::MV, t);
        break;

    case Tac::PUSH:
        emitPushTac(t);
        break;
        //knpc_assert(false);

    case Tac::POP:
        addInstr(ArmInstr::ADDI, _reg[ArmReg::SP], _reg[ArmReg::SP], NULL, 4, EMPTY_STR, EMPTY_STR);
        break;

    case Tac::CALL: 
        emitCallTac(t);
        /*{
            addInstr(ArmInstr::CALL, NULL, NULL, NULL, 0, std::string("_") + t->op1.label->str_form, NULL);
            int r0 = getRegForWrite(t->op0.var, 0, 0, t->LiveOut);
            addInstr(ArmInstr::MV, _reg[r0], _reg[ArmReg::A0], NULL, 0, EMPTY_STR, NULL);
            }
        */
        break;
    
    case Tac::PARAM:
        break;
    
    case Tac::LOAD_SYMBOL:
        emitLoadSymbolTac(t);
        break;
    
    case Tac::LOAD:
        emitLoadTac(t);
        break;

    case Tac::STORE:
        emitStoreTac(t);
        break;
    
    case Tac::ALLOC:
        emitAllocTac(t);
        break;

    default:
        printf("%d ????\n", t->op_code);
        knpc_assert(false); // should not appear inside a basic block
    }
}


void ArmDesc::emitCallTac(Tac *t) {

    Tac *first_tac_before_param = t->prev ? t->prev : t;
    for(; first_tac_before_param->prev != NULL && first_tac_before_param->op_code == Tac::PARAM; first_tac_before_param = first_tac_before_param->prev) ;
    Set<Temp>* liveness = t->LiveOut->clone();

    {
        int cnt = 0;
        for(auto temp : *liveness){
            cnt -= 4;
            int r1 = getRegForRead(temp, 0, first_tac_before_param->LiveOut);
            addInstr(ArmInstr::SW,  _reg[r1], _reg[ArmReg::SP], NULL, cnt, EMPTY_STR, EMPTY_STR);
        }
        addInstr(ArmInstr::ADDI, _reg[ArmReg::SP], _reg[ArmReg::SP], NULL, cnt, EMPTY_STR, EMPTY_STR);
    }

    int count = 0;
    for(Tac *it = t->prev; it != NULL && it->op_code == Tac::PARAM; it = it->prev) count += 4;

    if(count > 0){
        addInstr(ArmInstr::ADDI, _reg[ArmReg::SP], _reg[ArmReg::SP], NULL, -count, EMPTY_STR, EMPTY_STR);
        int cnt = count;
        for(Tac *it = t->prev; it != NULL && it->op_code == Tac::PARAM; it = it->prev){
            cnt -= 4;
            int r1 = getRegForRead(it->op0.var, 0, it->LiveOut);
            if (cnt <= 16) {
                addInstr(ArmInstr::MV,  _reg[cnt >> 2], _reg[r1], NULL, 0, EMPTY_STR, EMPTY_STR);
            } else {
                addInstr(ArmInstr::SW,  _reg[r1], _reg[ArmReg::SP], NULL, cnt, EMPTY_STR, EMPTY_STR);
            }
        }
    }
    count += liveness->size() * 4;

    addInstr(ArmInstr::CALL, NULL, NULL, NULL, 0, t->op1.label->str_form, EMPTY_STR);
    
    //printf("%d\n", r0);
    {
        int cnt = 0;
        addInstr(ArmInstr::ADDI, _reg[ArmReg::SP], _reg[ArmReg::SP], NULL, count, EMPTY_STR, EMPTY_STR);
        for(auto temp: *liveness){
            cnt -= 4;
            int r1 = getRegForWrite(temp, 0, 0, t->LiveOut);
            addInstr(ArmInstr::LW,  _reg[r1], _reg[ArmReg::SP], NULL, cnt, EMPTY_STR, EMPTY_STR);
        }
    }
    
    int r0 = getRegForWrite(t->op0.var, 0, 0, t->LiveOut);
    addInstr(ArmInstr::MV, _reg[r0], _reg[ArmReg::A1], NULL, 0, EMPTY_STR, EMPTY_STR);
}


void ArmDesc::emitPushTac(Tac *t) {
    int r1 = getRegForRead(t->op0.var, 0, t->LiveOut);
    addInstr(ArmInstr::ADDI, _reg[ArmReg::SP], _reg[ArmReg::SP], NULL, -4, EMPTY_STR, EMPTY_STR);
    addInstr(ArmInstr::SW,  _reg[r1], _reg[ArmReg::SP], NULL, 0, EMPTY_STR, EMPTY_STR);
}

void ArmDesc::emitAllocTac(Tac *t) {
    if (!t->LiveOut->contains(t->op0.var))
        return;
    int r0 = getRegForWrite(t->op0.var, 0, 0, t->LiveOut);
    addInstr(ArmInstr::ADDI, _reg[ArmReg::SP], _reg[ArmReg::SP], NULL, -t->op1.size, EMPTY_STR, EMPTY_STR);
    addInstr(ArmInstr::MV, _reg[r0], _reg[ArmReg::SP], NULL, 0, EMPTY_STR, EMPTY_STR);
}

/*void ArmDesc::emitPopTac(Tac *t) {
    addInstr(ArmInstr::ADDI, _reg[ArmReg::SP], _reg[ArmReg::SP], NULL, 4, EMPTY_STR, NULL);
}*/



/* Translates a LoadImm4 TAC into Arm instructions.
 *
 * PARAMETERS:
 *   t     - the LoadImm4 TAC
 */
void ArmDesc::emitLoadImm4Tac(Tac *t) {
    // eliminates useless assignments
    if (!t->LiveOut->contains(t->op0.var))
        return;

    // uses "load immediate number" instruction
    int r0 = getRegForWrite(t->op0.var, 0, 0, t->LiveOut);
    addInstr(ArmInstr::LI, _reg[r0], NULL, NULL, t->op1.ival, EMPTY_STR,
             EMPTY_STR);
}

void ArmDesc::emitLoadSymbolTac(Tac *t) {
    if (!t->LiveOut->contains(t->op0.var))
        return;

    // uses "load immediate number" instruction
    int r0 = getRegForWrite(t->op0.var, 0, 0, t->LiveOut);
    addInstr(ArmInstr::LA, _reg[r0], NULL, NULL, 0, t->op1.name,
             EMPTY_STR);
}

void ArmDesc::emitLoadTac(Tac *t) {
    if (!t->LiveOut->contains(t->op0.var))
        return;

    // uses "load immediate number" instruction
    int r1 = getRegForRead(t->op1.var, 0, t->LiveOut);
    int r0 = getRegForWrite(t->op0.var, r1, 0, t->LiveOut);
    addInstr(ArmInstr::LW, _reg[r0], _reg[r1], NULL, t->op1.offset, EMPTY_STR,
             EMPTY_STR);
}

void ArmDesc::emitStoreTac(Tac *t) {
    util::Set<Temp> *LiveInternal = t->LiveOut->clone();
    LiveInternal->add(t->op1.var);
    int r0 = getRegForRead(t->op0.var, 0, LiveInternal);
    int r1 = getRegForRead(t->op1.var, r0, t->LiveOut);
    addInstr(ArmInstr::SW, _reg[r0], _reg[r1], NULL, t->op1.offset, EMPTY_STR,
             EMPTY_STR);
}
/* Translates a Unary TAC into Arm instructions.
 *
 * PARAMETERS:
 *   t     - the Unary TAC
 */
void ArmDesc::emitUnaryTac(ArmInstr::OpCode op, Tac *t) {
    // eliminates useless assignments
    if (!t->LiveOut->contains(t->op0.var))
        return;

    int r1 = getRegForRead(t->op1.var, 0, t->LiveOut);
    int r0 = getRegForWrite(t->op0.var, r1, 0, t->LiveOut);

    addInstr(op, _reg[r0], _reg[r1], NULL, 0, EMPTY_STR, EMPTY_STR);
}

/* Translates a Binary TAC into Arm instructions.
 *
 * PARAMETERS:
 *   t     - the Binary TAC
 */
void ArmDesc::emitBinaryTac(ArmInstr::OpCode op, Tac *t) {
    // eliminates useless assignments
    if (!t->LiveOut->contains(t->op0.var))
        return;

    Set<Temp>* liveness = t->LiveOut->clone();
    liveness->add(t->op1.var);
    liveness->add(t->op2.var);
    int r1 = getRegForRead(t->op1.var, 0, liveness);
    int r2 = getRegForRead(t->op2.var, r1, liveness);
    int r0 = getRegForWrite(t->op0.var, r1, r2, liveness);

    addInstr(op, _reg[r0], _reg[r1], _reg[r2], 0, EMPTY_STR, EMPTY_STR);
}

/* Outputs a single instruction line.
 *
 * PARAMETERS:
 *   label   - label of this line
 *   body    - instruction
 *   comment - comment of this line
 */
void ArmDesc::emit(std::string label, const char *body, const char *comment) {
    std::ostream &os(*_result);

    if ((NULL != comment) && (label.empty()) && (NULL == body)) {
        os << "                                  @ " << comment;

    } else {
        if (!label.empty())
            os << label << std::left << std::setw(40 - label.length()) << ":";
        else if (NULL != body)
            os << "          " << std::left << std::setw(30) << body;

        if (NULL != comment && '\0' != *comment)
            os << "@ " << comment;
    }

    os << std::endl;
}

/* Translates a "Functy" object into assembly code and output.
 *
 * PARAMETERS:
 *   f     - the Functy object
 */
void ArmDesc::emitFuncty(Functy f) {
    knpc_assert(NULL != f);

    _frame = new ArmStackFrameManager(-3 * WORD_SIZE);
    FlowGraph *g = FlowGraph::makeGraph(f);
    g->simplify();        // simple optimization
    g->analyzeLiveness(); // computes LiveOut set of the basic blocks

    for (FlowGraph::iterator it = g->begin(); it != g->end(); ++it) {
        // all variables shared between basic blocks should be reserved
        Set<Temp> *liveout = (*it)->LiveOut;
        for (Set<Temp>::iterator sit = liveout->begin(); sit != liveout->end();
             ++sit) {
            _frame->reserve(*sit);
        }
        (*it)->entry_label = getNewLabel(); // adds entry label of a basic block
    }
    for (FlowGraph::iterator it = g->begin(); it != g->end(); ++it) {
        BasicBlock *b = *it;
        b->analyzeLiveness(); // computes LiveOut set of every TAC
        _frame->reset();
        // translates the TAC sequences of this block
        b->instr_chain = prepareSingleChain(b, g);
        if (Option::doOptimize()) // use "-O" option to enable optimization
            simplePeephole((ArmInstr *)b->instr_chain);
        b->mark = 0; // clears the marks (for the next step)
    }
    if (Option::getLevel() == Option::DATAFLOW) {
        std::cout << "Control-flow Graph of " << f->entry << ":" << std::endl;
        g->dump(std::cout);
        // TO STUDENTS: You might not want to get lots of outputs when
        // debugging.
        //              You can enable the following line so that the program
        //              will terminate after the first Functy is done.
        // std::exit(0);
        return;
    }
    knpc_assert(!f->entry->str_form.empty()); // this assertion should hold for every Functy
    // outputs the header of a function
    emitProlog(f->entry, _frame->getStackFrameSize());
    // chains up the assembly code of every basic block and output.
    //
    // ``A trace is a sequence of statements that could be consecutively
    //   executed during the execution of the program. It can include
    //   conditional branches.''
    //           -- Modern Compiler Implementation in Java (the ``Tiger Book'')
    for (FlowGraph::iterator it = g->begin(); it != g->end(); ++it)
        emitTrace(*it, g);
}

/* Outputs the leading code of a function.
 *
 * PARAMETERS:
 *   entry_label - the function label
 *   frame_size  - stack-frame size of this function
 * NOTE:
 *   the prolog code is used to save context and establish the stack frame.
 */
void ArmDesc::emitProlog(Label entry_label, int frame_size) {
    std::ostringstream oss;

    emit(EMPTY_STR, NULL, NULL); // an empty line
    emit(EMPTY_STR, ".text", NULL);
    if (entry_label->str_form == "main") {
        oss << "main";
    } else {
        oss << entry_label;
    }
    emit(oss.str(), NULL, "function entry"); // marks the function entry label
    oss.str("");
    // saves old context
    emit(EMPTY_STR, "str    lr, [sp, #-4]", NULL); // saves old frame pointer
    emit(EMPTY_STR, "str    fp, [sp, #-8]", NULL); // saves return address
    // establishes new stack frame (new context)
    emit(EMPTY_STR, "mov    fp, sp", NULL);
    oss << "add  sp, sp, #-" << (frame_size + 2 * WORD_SIZE); // 2 WORD's for old $fp and $ra
    emit(EMPTY_STR, oss.str().c_str(), NULL);
}

/* Outputs a single instruction.
 *
 * PARAMETERS:
 *   i     - the instruction to output
 */
void ArmDesc::emitInstr(ArmInstr *i) {
    if (i->cancelled)
        return;
    std::ostringstream oss;
    oss << std::left << std::setw(6);
    switch (i->op_code) {
    case ArmInstr::COMMENT:
        emit(EMPTY_STR, NULL, i->comment.c_str());
        return;
    
    case ArmInstr::LI:
        oss << "ldr" << i->r0->name << ", =" << i->i;
        break;

    case ArmInstr::NEG:
        oss << "neg" << i->r0->name << ", " << i->r1->name;
        break;
    
    case ArmInstr::NOT:
        oss << "mvn" << i->r0->name << ", " << i->r1->name;
        break;

    case ArmInstr::TEQZ:
        oss << "teq" << i->r1->name << ", #0";
        break;
    
    case ArmInstr::SEQ:
        oss << "moveq" << i->r0->name << ", #1";
        break;
    
    case ArmInstr::CEQ:
        oss << "moveq" << i->r0->name << ", #0";
        break;

    case ArmInstr::SNE:
        oss << "movne" << i->r0->name << ", #1";
        break;
    
    case ArmInstr::CNE:
        oss << "movne" << i->r0->name << ", #0";
        break;

    case ArmInstr::MV:
        oss << "mov" << i->r0->name << ", " << i->r1->name;
        break;

    case ArmInstr::LW:
        oss << "ldr" << i->r0->name << ", " << "[" << i->r1->name << ", #" << i->i << "]";
        break;

    case ArmInstr::SW:
        oss << "str" << i->r0->name << ", " << "[" << i->r1->name << ", #" << i->i << "]";
        break;
    
    case ArmInstr::RET:
        oss << "bx" << "lr";
        break;

    case ArmInstr::AND:
        oss << "and" << i->r0->name << ", " << i->r1->name << "," << i->r2->name;
        break;
    
    case ArmInstr::OR:
        oss << "orr" << i->r0->name << ", " << i->r1->name << "," << i->r2->name;
        break; 
    
    case ArmInstr::SLT:
        oss << "movlt" << i->r0->name << ", #1";
        break;
    
    case ArmInstr::CLT:
        oss << "movlt" << i->r0->name << ", #0";
        break;
    
    case ArmInstr::SLE:
        oss << "movle" << i->r0->name << ", #1";
        break;
    
    case ArmInstr::CLE:
        oss << "movle" << i->r0->name << ", #0";
        break;
    
    // case ArmInstr::SLTU:
    //     oss << "sltu" << i->r0->name << ", " << i->r1->name << "," << i->r2->name;
    //     break;

    case ArmInstr::SGT:
        oss << "movgt" << i->r0->name << ", #1";
        break;

    case ArmInstr::CGT:
        oss << "movgt" << i->r0->name << ", #0";
        break;
    
    case ArmInstr::SGE:
        oss << "movge" << i->r0->name << ", #1";
        break;

    case ArmInstr::CGE:
        oss << "movge" << i->r0->name << ", #0";
        break;
    
    case ArmInstr::XOR:
        oss << "eor" << i->r0->name << ", " << i->r0->name << "," <<  "0x1";
        break;

    case ArmInstr::ADD:
        oss << "add" << i->r0->name << ", " << i->r1->name << ", " << i->r2->name;
        break;

    case ArmInstr::ADDI:
        oss << "add" << i->r0->name << ", " << i->r1->name << ", #"<< i->i;
        break;
    
    case ArmInstr::SUB:
        oss << "sub" << i->r0->name << ", " << i->r1->name << ", " << i->r2->name;
        break;
    
    case ArmInstr::SUBS:
        oss << "subs" << i->r0->name << ", " << i->r1->name << ", " << i->r2->name;
        break;

    case ArmInstr::MUL:
        oss << "mul" << i->r0->name << ", " << i->r1->name << ", " << i->r2->name;
        break;
    
    case ArmInstr::DIV:
        oss << "sdiv" << i->r0->name << ", " << i->r1->name << ", " << i->r2->name;
        break;
    
    case ArmInstr::INPLACE_MLS:
        oss << "mls" << i->r0->name << ", " << i->r0->name << ", " << i->r2->name << ", " << i->r1->name;
        break;

    case ArmInstr::BEQ:
        oss << "beq" << i->l;
        break;

    case ArmInstr::J:
        oss << "b" << i->l;
        break;

    case ArmInstr::CALL:
        oss << "bl" << i->l;
        break;

    case ArmInstr::LA:
        oss << "ldr" << i->r0->name << ", =" << i->l;
        break;

    default:
        knpc_assert(false); // other instructions not supported
    }

    emit(EMPTY_STR, oss.str().c_str(), i->comment.c_str());
}

/* Outputs a "trace" (see also: ArmDesc::emitFuncty).
 *
 * PARAMETERS:
 *   b     - the leading basic block of this trace
 *   g     - the control-flow graph
 * NOTE:
 *   we just do a simple depth-first search against the CFG
 */
void ArmDesc::emitTrace(BasicBlock *b, FlowGraph *g) {
    // a trace is a series of consecutive basic blocks
    if (b->mark > 0)
        return;
    b->mark = 1;
    emit(std::string(b->entry_label), NULL, NULL);
    ArmInstr *i = (ArmInstr *)b->instr_chain;
    while (NULL != i) {
        emitInstr(i);
        i = i->next;
    }
    switch (b->end_kind) {
    case BasicBlock::BY_JUMP:
        emitTrace(g->getBlock(b->next[0]), g);
        break;

    case BasicBlock::BY_JZERO:
        emitTrace(g->getBlock(b->next[1]), g);
        break;

    case BasicBlock::BY_RETURN:
        break;

    default:
        knpc_assert(false); // unreachable
    }
}

/* Appends an instruction line to "_tail". (internal helper function)
 *
 * PARAMETERS:
 *   op_code - operation code
 *   r0      - the first register operand (if any)
 *   r1      - the second register operand (if any)
 *   r2      - the third register operand (if any)
 *   i       - immediate number or offset (if any)
 *   l       - label operand (for LA and jumps)
 *   cmt     - comment of this line
 */
void ArmDesc::addInstr(ArmInstr::OpCode op_code, ArmReg *r0, ArmReg *r1,
                         ArmReg *r2, int i, std::string l, std::string cmt) {
    knpc_assert(NULL != _tail);

    // we should eliminate all the comments when doing optimization
    if (Option::doOptimize() && (ArmInstr::COMMENT == op_code))
        return;
    _tail->next = new ArmInstr();
    _tail = _tail->next;
    _tail->op_code = op_code;
    _tail->r0 = r0;
    _tail->r1 = r1;
    _tail->r2 = r2;
    _tail->i = i;
    _tail->l = l;
    _tail->comment = cmt;
}


/******************** a simple peephole optimizer *********************/

/* Performs a peephole optimization pass to the instruction sequence.
 *
 * PARAMETERS:
 *   iseq  - the instruction sequence to optimize
 */
void ArmDesc::simplePeephole(ArmInstr *iseq) {
    // if you are interested in peephole optimization, you can implement here
    // of course, beyond our requirements
    
}

/******************* REGISTER ALLOCATOR ***********************/

/* Acquires a register to read some variable.
 *
 * PARAMETERS:
 *   v      - the variable to read
 *   avoid1 - the register which should not be selected
 *   live   - current liveness set
 * RETURNS:
 *   number of the register containing the content of v
 */
int ArmDesc::getRegForRead(Temp v, int avoid1, LiveSet *live) {
    std::ostringstream oss;

    if (v->reg) {
        int reg_idx = v->reg - 1;
        spillReg(reg_idx, live);
        _reg[reg_idx]->var = v;
        v->reg = 0;
        return reg_idx;
    }

    int i = lookupReg(v);

    if (i < 0) {
        // we will load the content into some register
        i = lookupReg(NULL);
        if (i < 0) {
            i = selectRegToSpill(avoid1, ArmReg::PC, live);
            spillReg(i, live);
        }

        _reg[i]->var = v;

        if (v->is_offset_fixed) {
            ArmReg *base = _reg[ArmReg::FP];
            oss << "load " << v << " from (" << base->name
                << (v->offset < 0 ? "" : "+") << v->offset << ") into "
                << _reg[i]->name;
            addInstr(ArmInstr::LW, _reg[i], base, NULL, v->offset, EMPTY_STR,
                     oss.str());

        } else {
            oss << "initialize " << v << " with 0";
            addInstr(ArmInstr::LI, _reg[i], NULL, 0, 0,
                     EMPTY_STR, oss.str());
        }
        _reg[i]->dirty = false;
    }

    return i;
}

/* Acquires a register to write some variable.
 *
 * PARAMETERS:
 *   v      - the variable to write
 *   avoid1 - the register which should not be selected
 *   avoid2 - the same as "avoid1"
 *   live   - the current liveness set
 * RETURNS:
 *   number of the register which can be safely written to
 */
int ArmDesc::getRegForWrite(Temp v, int avoid1, int avoid2, LiveSet *live) {
    // if (NULL == v || !live->contains(v))
    //     return ArmReg::ZERO;

    int i = lookupReg(v);

    if (i < 0) {
        i = lookupReg(NULL);

        if (i < 0) {
            i = selectRegToSpill(avoid1, avoid2, live);
            spillReg(i, live);
        }
        _reg[i]->var = v;
    }

    _reg[i]->dirty = true;

    return i;
}

/* Spills a specified register (into memory, i.e. into the stack-frame).
 *
 * PARAMETERS:
 *   i     - number of the register to spill
 *   live  - the current liveness set
 * NOTE:
 *   if the variable contained in $i is no longer alive,
 *   we don't save it into memory.
 */
void ArmDesc::spillReg(int i, LiveSet *live) {
    std::ostringstream oss;

    Temp v = _reg[i]->var;

    if ((NULL != v) && _reg[i]->dirty && live->contains(v)) {
        ArmReg *base = _reg[ArmReg::FP];

        if (!v->is_offset_fixed) {
            _frame->getSlotToWrite(v, live);
        }

        oss << "spill " << v << " from " << _reg[i]->name << " to ("
            << base->name << (v->offset < 0 ? "" : "+") << v->offset << ")";
        addInstr(ArmInstr::SW, _reg[i], base, NULL, v->offset, EMPTY_STR,
                 oss.str());
    }

    _reg[i]->var = NULL;
    _reg[i]->dirty = false;
}

/* Spills all dirty (and alive) registers into memory.
 *
 * PARAMETERS:
 *   live  - the current liveness set
 */
void ArmDesc::spillDirtyRegs(LiveSet *live) {
    int i;
    // determines whether we should spill the registers
    for (i = 4; i < ArmReg::TOTAL_NUM; ++i) {
        if ((NULL != _reg[i]->var) && _reg[i]->dirty &&
            live->contains(_reg[i]->var))
            break;

        _reg[i]->var = NULL;
        _reg[i]->dirty = false;
    }

    if (i < ArmReg::TOTAL_NUM) {
        addInstr(ArmInstr::COMMENT, NULL, NULL, NULL, 0, EMPTY_STR,
                 std::string("(save modified registers before control flow changes)"));

        for (; i < ArmReg::TOTAL_NUM; ++i)
            spillReg(i, live);
    }
}

/* Looks up a register containing the specified variable.
 *
 * PARAMETERS:
 *   v     - the specified variable
 * RETURNS:
 *   number of the register if found; -1 if not found
 */
int ArmDesc::lookupReg(tac::Temp v) {
    for (int i = 0; i < ArmReg::TOTAL_NUM; ++i)
        if (( v != NULL || _reg[i]->general) && _reg[i]->var == v)
            return i;

    return -1;
}

/* Selects a register to spill into memory (so that it can be released).
 *
 * PARAMETERS:
 *   avoid1 - the register that should not be selected
 *   avoid2 - the same as avoid1
 *   live   - the current liveness set
 * RETURNS:
 *   number of the selected register
 */
int ArmDesc::selectRegToSpill(int avoid1, int avoid2, LiveSet *live) {
    // looks for a "ready" one
    for (int i = 0; i < ArmReg::TOTAL_NUM; ++i) {
        if (!_reg[i]->general)
            continue;

        if ((i != avoid1) && (i != avoid2) && !live->contains(_reg[i]->var))
            return i;
    }

    // looks for a clean one (so that we could save a "store")
    for (int i = 0; i < ArmReg::TOTAL_NUM; ++i) {
        if (!_reg[i]->general)
            continue;

        if ((i != avoid1) && (i != avoid2) && !_reg[i]->dirty)
            return i;
    }

    // the worst case: all are live and all are dirty.
    // chooses one register w.r.t a policy similar to the LRU algorithm (random
    // choice)
    do {
        _lastUsedReg = (_lastUsedReg + 1) % ArmReg::TOTAL_NUM;
    } while ((_lastUsedReg == avoid1) || (_lastUsedReg == avoid2) ||
             !_reg[_lastUsedReg]->general);

    return _lastUsedReg;
}
