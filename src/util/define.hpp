/*****************************************************
 *  Forward declarations of the classes.
 *
 *  This file is used to resolve the "cyclic reference"
 *  dilemma in C++.
 *
 *  Keltin Leung
 */

#ifndef __KNPC_DEFINE__
#define __KNPC_DEFINE__

#ifndef KNPC_AST_DEFINED
#include "../3rdparty/list.hpp"
#include "../3rdparty/set.hpp"
#endif

namespace knpc
{
    /* String ID */
    typedef unsigned long SID;

#ifndef KNPC_LOCATION_DEFINED
    struct Location;
#endif

#ifndef KNPC_TYPE_DEFINED
    namespace type
    {
        class Type;

        class ArrayType;
        class BaseType;
        class FuncType;
    } // namespace type
#endif

#ifndef KNPC_SCOPE_DEFINED
    namespace scope
    {
        class Scope;

        class FuncScope;
        class GlobalScope;
    } // namespace scope
#endif

#ifndef KNPC_SCOPESTACK_DEFINED
    namespace scope
    {
        class ScopeStack;
    }
#endif

#ifndef KNPC_SYMB_DEFINED
    namespace symb
    {
        class Symbol;

        class Function;
        class Variable;
    } // namespace symb
#endif

#ifndef KNPC_AST_DEFINED
    namespace ast
    {
        class Visitor;
        class ASTNode;

        class AddExpr;
        class AndExpr;
        class AssignExpr;
        class BoolConst;
        class BoolType;
        class CompStmt;
        class DivExpr;
        class EquExpr;
        class Expr;
        class ExprStmt;
        class ForStmt;
        class FuncDefn;
        class FuncOrGlobal;
        class IfStmt;
        class IntConst;
        class IntType;
        class LeqExpr;
        class LesExpr;
        class Lvalue;
        class LvalueExpr;
        class ModExpr;
        class MulExpr;
        class NegExpr;
        class NotExpr;
        class Program;
        class ReadExpr;
        class ReturnStmt;
        class Statement;
        class SubExpr;
        class Type;
        class VarDecl;
        class VarRef;
        class WhileStmt;

        // the lists are not ASTNode
        typedef util::List<FuncDefn *> FuncList;        // list of Function
        typedef util::List<VarDecl *> VarList;          // list of VarDecl
        typedef util::List<int> DimList;                // list of VarDecl
        typedef util::List<Statement *> StmtList;       // list of Statement
        typedef util::List<Expr *> ExprList;            // list of Expr
        typedef util::List<ASTNode *> FuncOrGlobalList; // list of Expr

    } // namespace ast
#endif

#ifndef KNPC_TAC_DEFINED
    namespace tac
    {
        struct LibFunc;
        struct TempVariable;
        struct LabelObject;
        struct VTableObject;
        struct FunctyObject;
        typedef struct TempVariable *Temp;
        typedef struct LabelObject *Label;
        typedef struct VTableObject *VTable;
        typedef struct FunctyObject *Functy;

        struct Tac;
        struct Piece;
    } // namespace tac
#endif

#ifndef KNPC_TRANSHELPER_DEFINED
    namespace tac
    {
        class TransHelper;
    }
#endif

#ifndef KNPC_FLOWGRAPH_DEFINED
    namespace tac
    {
        struct BasicBlock;
        class FlowGraph;
    } // namespace tac
#endif

#ifndef KNPC_MACHDESC_DEFINED
    namespace assembly
    {
        struct Instr;
        class MachineDesc;
    } // namespace assembly
#endif

#ifndef KNPC_OFFSETCOUNTER_DEFINED
    namespace assembly
    {
        class OffsetCounter;
    }
#endif

#ifndef ARM_COMPONENTS_DEFINED
    namespace assembly
    {
        struct ArmReg;
        struct ArmInstr;
        class ArmDesc;
    } // namespace assembly
#endif

} // namespace knpc

#endif // __KNPC_DEFINE__