/*****************************************************
 *  Implementation of "ArrayVariable".
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
ArrayVariable::ArrayVariable(std::string n, Type *t) {
    knpc_assert(NULL != t);

    name = n;
    type = t;
    order = -1;

    is_parameter = false;
    attached = NULL;

    mark = 0;
}

/* Sets the parameter flag (i.e. it is a parameter).
 *
 */
void ArrayVariable::setParameter(void) { is_parameter = true; }

/* Tests whether it is a parameter.
 *
 * RETURNS:
 *   true if it is a parameter; false otherwise
 */
bool ArrayVariable::isParameter(void) { return is_parameter; }

void ArrayVariable::setGlobalInit(util::Vector<int> val) { global_init = val; }

util::Vector<int> ArrayVariable::getGlobalInit() { return global_init; }

/* Tests whether it is a local variable.
 *
 * RETURNS:
 *   true if it is a local variable, false otherwise
 */
bool ArrayVariable::isLocalVar(void) {
    knpc_assert(NULL != defined_in);

    return (defined_in->isFuncScope() && !is_parameter);
}

/* Tests whether it is a global variable.
 *
 * RETURNS:
 *   true if it is a global variable, false otherwise
 */
bool ArrayVariable::isGlobalVar(void) {
    knpc_assert(NULL != defined_in);

    return defined_in->isGlobalScope();
}

/* Tests whether this symbol is a Variable.
 *
 * RETURNS:
 *   true
 */
bool ArrayVariable::isVariable(void) { return true; }

/* Prints this symbol.
 *
 * PARAMETERS:
 *   os    - the output stream
 */
void ArrayVariable::dump(std::ostream &os) {
    os << "arrayvariable ";
    if (is_parameter)
        os << "@" << (name);
    else
        os << (name);
    os << " : " << type;
    if (isGlobalVar())
        os << " = " << "{ ";
        for(auto i : global_init) os << i << ' ';
        os << "}";
}

/* Attaches the register object to this symbol.
 *
 * PARAMETERS:
 *   v     - the register object
 */
void ArrayVariable::attachTemp(tac::Temp v) {
    knpc_assert(NULL != v && NULL == attached);

    attached = v;
}

/* Gets the attached register object.
 *
 * RETURNS:
 *   the attached register object
 */
Temp ArrayVariable::getTemp(void) { return attached; }
