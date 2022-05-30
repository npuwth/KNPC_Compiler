/*****************************************************
 *  Garbage-collectable Data Structure: Vector.
 *
 *  NOTE: just treat it like std::vector.
 *
 *  Keltin Leung 
 */

#ifndef __KNPC_VECTOR__
#define __KNPC_VECTOR__

//#include "boehmgc.hpp"

#include <vector>

namespace knpc {

  namespace util {

	// Vector (garbage-collectable version)
	template <typename _T>
	class Vector : public std::vector<_T> {
	};

  }  
}

#endif // __KNPC_VECTOR__
