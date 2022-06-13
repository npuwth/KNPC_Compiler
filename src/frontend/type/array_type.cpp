/*****************************************************
 *  Implementation of the "ArrayType" class.
 *
 *  Keltin Leung 
 */

#include "util/config.hpp"
#include "type/type.hpp"

using namespace knpc::type;
using namespace knpc::util;

/* Constructor.
 *
 * PARAMETERS:
 *   bt    - the base type (i.e. the element type)
 *   len   - the length or the array
 */
ArrayType::ArrayType(Type *bt, util::Vector<int> _dims) {
    knpc_assert(NULL != bt && !bt->isFuncType() && !bt->equal(BaseType::Error));

    element_type = bt;
    dims = _dims;
}

/* Gets the element type.
 *
 * RETURNS:
 *   the element type
 */
Type *ArrayType::getElementType(void) { return element_type; }

Vector<int> ArrayType::getLength(void) { return dims; }

/* Tests whether it is an ArrayType.
 *
 * RETURNS:
 *   true
 */
bool ArrayType::isArrayType(void) { return true; }

/* Get the size of this type
 */
int ArrayType::getSize() { 
    int size = 1;
    for(auto i : dims) {
        size = size*i;
    }
    return element_type->getSize() * size; 
}

/* Tests whether this type is compatible with the given type.
 *
 * PARAMETERS:
 *   t     - the given type
 * RETURNS:
 *   true if this type is compatible with the given type; false otherwise
 * NOTE:
 *   Array types are always imcompatible, because there is no array comparison
 * or assignment in C++
 */
bool ArrayType::compatible(Type *t) {
    knpc_assert(NULL != t);

    if (t->equal(BaseType::Error))
        return true;
    else
        return false;
}

/* Tests whether this type is equal to the given type.
 *
 * PARAMETERS:
 *   t     - the given type
 * RETURNS:
 *   true if this type is equal to the given type; false otherwise
 */
bool ArrayType::equal(Type *t) {
    knpc_assert(NULL != t);

    if (!t->isArrayType())
        return false;
    else
        return (element_type->equal(((ArrayType *)t)->element_type));
}

/* Prints this type
 *
 * PARAMETERS:
 *   os    - the output stream
 */
void ArrayType::dump(std::ostream &os) { os << element_type << "[]"; }
