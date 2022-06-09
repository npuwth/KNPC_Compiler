/*****************************************************
 *  Implementation of "Variable".
 *
 *  Keltin Leung 
 */

#include "config.hpp"
#include "scope/scope.hpp"
#include "symb/symbol.hpp"

using namespace knpc;
using namespace knpc::symb;
using namespace knpc::type;
using namespace knpc::scope;
using namespace knpc::tac;

/* Constructor.
 *
 * PARAMETERS:
 *   n     - the variable name
 *   t     - the type
 */
Variable::Variable(std::string n, Type *t) {
    knpc_assert(NULL != t);

    name = n;
    type = t;
    order = -1;
    defined_in = NULL;

    is_parameter = false;
    is_const = false;
    // global_init = 0;
    attached = NULL;

    mark = 0;
}

/* Sets the parameter flag (i.e. it is a parameter).
 *
 */
void Variable::setParameter(void) { is_parameter = true; }

/* Tests whether it is a parameter.
 *
 * RETURNS:
 *   true if it is a parameter; false otherwise
 */
bool Variable::isParameter(void) { return is_parameter; }

void Variable::setConst(void) { is_const = true; }

bool Variable::isConst(void) { return is_const; }

void Variable::setGlobalInit(util::Vector<int> val) { global_init = val; }

int Variable::getGlobalInit(int index) { return global_init[index]; }

/* Tests whether it is a local variable.
 *
 * RETURNS:
 *   true if it is a local variable, false otherwise
 */
bool Variable::isLocalVar(void) {
    knpc_assert(NULL != defined_in);

    return (defined_in->isFuncScope() && !is_parameter);
}

/* Tests whether it is a global variable.
 *
 * RETURNS:
 *   true if it is a global variable, false otherwise
 */
bool Variable::isGlobalVar(void) {
    knpc_assert(NULL != defined_in);

    return defined_in->isGlobalScope();
}

/* Tests whether this symbol is a Variable.
 *
 * RETURNS:
 *   true
 */
bool Variable::isVariable(void) { return true; }

/* Prints this symbol.
 *
 * PARAMETERS:
 *   os    - the output stream
 */
void Variable::dump(std::ostream &os) {
    os << "variable ";
    if (is_parameter)
        os << "@" << (name);
    else
        os << (name);
    os << " : " << type;
    if (isGlobalVar()) {
        os << " = { ";
        for(int i : global_init) os << i << " ";
        os << "}";
    }
}

/* Attaches the register object to this symbol.
 *
 * PARAMETERS:
 *   v     - the register object
 */
void Variable::attachTemp(tac::Temp v) {
    knpc_assert(NULL != v && NULL == attached);

    attached = v;
}

/* Gets the attached register object.
 *
 * RETURNS:
 *   the attached register object
 */
Temp Variable::getTemp(void) { return attached; }
