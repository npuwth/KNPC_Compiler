#ifndef __KNPC_CONFIG__
#define __KNPC_CONFIG__

#include "3rdparty/boehmgc.hpp"
#include "define.hpp"
#include "error.hpp"

#include <cstring>
#include <iostream>
#include <memory>

/* declaration of some global data & functions you will use */
namespace knpc
{

    extern scope::ScopeStack *scopes;

    /* Output Functions */
    std::ostream &operator<<(std::ostream &, Location *);
    std::ostream &operator<<(std::ostream &, ast::ASTNode *);
    std::ostream &operator<<(std::ostream &, ast::FuncList *);
    std::ostream &operator<<(std::ostream &, ast::VarList *);
    std::ostream &operator<<(std::ostream &, ast::StmtList *);
    std::ostream &operator<<(std::ostream &, ast::ExprList *);
    std::ostream &operator<<(std::ostream &, ast::DimList *);
    std::ostream &operator<<(std::ostream &, ast::FuncOrGlobalList *);
    std::ostream &operator<<(std::ostream &, type::Type *);
    std::ostream &operator<<(std::ostream &, scope::Scope *);
    std::ostream &operator<<(std::ostream &, symb::Symbol *);
    std::ostream &operator<<(std::ostream &, tac::Tac *);
    std::ostream &operator<<(std::ostream &, tac::Temp);
    std::ostream &operator<<(std::ostream &, tac::Label);
    std::ostream &operator<<(std::ostream &, tac::VTable);
    std::ostream &operator<<(std::ostream &, tac::Functy);

    /* Output Indentation */
    void newLine(std::ostream &);
    void incIndent(std::ostream &);
    void decIndent(std::ostream &);
} // namespace knpc

#endif // __KNPC_CONFIG__#ifndef __KNPC_CONFIG__
