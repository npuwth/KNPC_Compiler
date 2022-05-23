/*****************************************************
 *  Implementation of the "Type" classes.
 */

#include "type/type.hpp"
#include "config.hpp"

using namespace knpc::type;
using namespace knpc::util;


// ---------------------------      Type(Abstract Class) Implementation      -------------------------------------//
bool Type::isBaseType(void) { return false; }

bool Type::isArrayType(void) { return false; }

bool Type::isFuncType(void) { return false; }

std::ostream &knpc::operator<<(std::ostream &os, Type *t) {
    t->dump(os);
    return os;
}


// ---------------------------   BaseType(Int, Float, Error) Implementation    -----------------------------------//
#define WORD_SIZE 4

#define EITHER_ERR(a, b) ((a == BaseType::Error) || (b == BaseType::Error))

BaseType::BaseType(const char *str) {
    mind_assert(NULL != str);

    type_name = str;
}

int BaseType::getSize() { return WORD_SIZE; } // get the size of this type

bool BaseType::isBaseType(void) { return true; } // true if is base type

bool BaseType::compatible(Type *t) { // true if this type is compatible with the given type
    mind_assert(NULL != t);

    return t->isBaseType();
}

bool BaseType::equal(Type *t) { // true if this type is equal to the given type
    mind_assert(NULL != t);

    return (this == t);
}

void BaseType::dump(std::ostream &os) { os << type_name; }

// private instances of the intrinsic types
BaseType BaseType::_int("Int");
BaseType BaseType::_float("Float");
BaseType BaseType::_error("Error");

// public interfaces (constant)
BaseType *const BaseType::Int = &_int;
BaseType *const BaseType::Float = &_float;
BaseType *const BaseType::Error = &_error;


// --------------------------------------         ArrayType Implementation         -----------------------//
ArrayType::ArrayType(Type *bt, int len) {
    mind_assert(NULL != bt && !bt->isFuncType() && !bt->equal(BaseType::Error));

    element_type = bt;
    length = len;
}

Type *ArrayType::getElementType(void) { return element_type; }

int ArrayType::getLength(void) { return length; }

bool ArrayType::isArrayType(void) { return true; }

int ArrayType::getSize() { return element_type->getSize() * length; } // get the size of this type

bool ArrayType::compatible(Type *t) {
    mind_assert(NULL != t);

    if (t->equal(BaseType::Error))
        return true;
    else
        return false;
}

bool ArrayType::equal(Type *t) {
    mind_assert(NULL != t);

    if (!t->isArrayType())
        return false;
    else
        return (element_type->equal(((ArrayType *)t)->element_type));
}

void ArrayType::dump(std::ostream &os) { os << element_type << "[]"; }


// -------------------------------------      FuncType Implementation      ----------------------------------//
typedef List<Type *> TypeList;

FuncType::FuncType(Type *result) {
    result_type = result;
    arglist = new TypeList();
}

bool FuncType::isFuncType(void) { return true; }

Type *FuncType::getResultType(void) { return result_type; }

List<Type *> *FuncType::getArgList(void) { return arglist; }

size_t FuncType::numOfParameters(void) { return arglist->length(); }

void FuncType::appendParameter(Type *t) { arglist->append(t); }

bool FuncType::compatible(Type *t) {
    mind_assert(NULL != t);

    if (!t->isFuncType())
        return false;
    else {
        FuncType *ft = (FuncType *)t;
        if (!result_type->compatible(ft->result_type) ||
            arglist->length() != ft->arglist->length())
            return false; // result types and arglist lengths must match

        TypeList::iterator it1, it2;
        it1 = arglist->begin();
        it2 = ft->arglist->begin();

        if (!(*it1)->compatible(*it2))
            return false; // "this" types must match

        int n = arglist->length();
        for (int i = 1; i < n; ++i) {
            ++it1;
            ++it2;
            if (!(*it2)->compatible(*it1))
                return false; // every pair of parameter types must match
        }

        return true;
    }
}

bool FuncType::equal(Type *t) {
    mind_assert(false); // you should never compare two function types..

    return false;
}

void FuncType::dump(std::ostream &os) {
    TypeList::iterator it;
    for (it = arglist->begin(); it != arglist->end(); ++it)
        os << (*it) << "->";
    os << result_type;
}
