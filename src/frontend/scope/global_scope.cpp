/*****************************************************
 *  Implementation of "GlobalScope".
 *
 *  Keltin Leung 
 */

#include "scope.hpp"
#include "../symb/symbol.hpp"
#include "../../3rdparty/vector.hpp"
#include "../../util/config.hpp"

#include <algorithm>
#include <cstring>

using namespace knpc;
using namespace knpc::symb;
using namespace knpc::scope;
using namespace knpc::util;

/*  Constructor.
 *
 */
GlobalScope::GlobalScope(void) {
    // just leave it alone
}

/*  Gets the kind of this scope.
 *
 *  RETURNS:
 *    Scope::GLOBAL
 */
Scope::kind_t GlobalScope::getKind(void) { return GLOBAL; }

/*  Declares a symbol in this scope.
 *
 *  PARAMETERS:
 *    s     - the symbol
 */
void GlobalScope::declare(Symbol *s) {
    knpc_assert(NULL != s);
    knpc_assert(s->getScope() == NULL);

    Scope::declare(s);
}

// symbol comparator
struct symbol_less {
    bool operator()(Symbol *s1, Symbol *s2) {
        return (std::strcmp((s1->getName().c_str()), (s2->getName().c_str())) <
                0);
    }
};

/*  Prints the content of this scope.
 *
 *  PARAMETERS:
 *    os    - the output stream
 */
void GlobalScope::dump(std::ostream &os) {
    Vector<Symbol *> s;
    for (ScopeIterator it = begin(); it != end(); ++it)
        s.push_back(*it);
    std::sort(s.begin(), s.end(), symbol_less());

    os << "GLOBAL SCOPE:";
    incIndent(os);
    for (Vector<Symbol *>::iterator it = s.begin(); it != s.end(); ++it) {
        newLine(os);
        os << "  " << *it;
    }
    decIndent(os);
    newLine(os);
}
