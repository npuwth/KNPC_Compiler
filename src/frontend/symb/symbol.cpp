/*****************************************************
 *  Implementation of the "Symbol" abstract class.
 *
 *  Keltin Leung 
 */

#include "symbol.hpp"
#include "../../util/config.hpp"

using namespace knpc;
using namespace knpc::symb;
using namespace knpc::type;
using namespace knpc::scope;

/* Gets the name of this symbol.
 *
 * RETURNS:
 *   name of this symbol
 */
std::string Symbol::getName(void) { return name; }

/* Gets the type of this symbol.
 *
 * RETURNS:
 *   type of this symbol
 */
Type *Symbol::getType(void) { return type; }

/* Tests whether it is a Variable.
 *
 * RETURNS:
 *   true if yes, false otherwise
 */
bool Symbol::isVariable(void) { return false; }

/* Tests whether it is a Function.
 *
 * RETURNS:
 *   true if yes, false otherwise
 */
bool Symbol::isFunction(void) { return false; }

/* Gets the order of this symbol.
 *
 * RETURNS:
 *   the order of this symbol
 */
int Symbol::getOrder(void) { return order; }

/* Sets the order of this symbol.
 *
 * PARAMETERS:
 *   ord   - the order
 */
void Symbol::setOrder(int ord) {
    knpc_assert(ord >= 0);

    order = ord;
}

/* Gets the scope where this symbol is defined.
 *
 * RETURNS:
 *   the scope where this symbol is defined
 */
scope::Scope *Symbol::getScope(void) { return defined_in; }

/* Sets the scope where this symbol is defined.
 *
 * PARAMETERS:
 *   s     - the scope where this symbol is defined
 */
void Symbol::setScope(scope::Scope *s) {
    knpc_assert(NULL != s);

    defined_in = s;
}

/* Prints this symbol.
 *
 * PARAMETERS:
 *   os    - the output stream
 * RETURNS:
 *   the output stream
 */
std::ostream &knpc::operator<<(std::ostream &os, Symbol *sym) {
    sym->dump(os);
    return os;
}
