/*****************************************************
 *  Definition of ScopeStack.
 *
 *  We organize all the open scopes by a stack, at top
 *  of which is the innermost scope. GlobalScope is at
 *  the bottom of the stack.
 *
 *  Keltin Leung 
 */

#ifndef __KNPC_SCOPESTACK__
#define __KNPC_SCOPESTACK__

#include "scope.hpp"
#include "../../3rdparty/stack.hpp"
#include "../../util/define.hpp"

namespace knpc {

#define KNPC_SCOPESTACK_DEFIINED
namespace scope {

/* Scope Stack.
 *
 * We orgainize all the visible scopes with a stack, the topmost of which
 * is the innermost open scope.
 */
class ScopeStack {
  private:
    // the underlying stack
    util::Stack<Scope *> _stack;
    // a track of the global scope
    Scope *_global;

  public:
    // Constructor
    ScopeStack();
    // Looks up a name in the scope stack
    symb::Symbol *lookup(std::string id, bool through);
    // Declares a symbol in the current scope
    void declare(symb::Symbol *s);
    // Opens a scope
    void open(Scope *s);
    // Closes the current scope
    void close(void);
    // Gets the current scope
    Scope *top(void);
    // Looks up the topmost scope of a specific kind
    Scope *lookForScope(Scope::kind_t kind);
};
} // namespace scope
} // namespace knpc

#endif // __KNPC_SCOPESTACK__
