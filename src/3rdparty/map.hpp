/*****************************************************
 *  Garbage-collectable Data Structure: TreeMap & HashMap.
 *
 *  NOTE: just treat it like std::map && hash_map.
 *
 *  Keltin Leung 
 */

#ifndef __KNPC_MAP__
#define __KNPC_MAP__

//#include "boehmgc.hpp"

#include <map>

namespace knpc {

  namespace util {

	// Red-black Tree Map (garbage-collectable version)
	template <typename _K, typename _T, typename _C =std::less<_K> >
	class TreeMap : public std::map<_K, _T, _C> {
	};

	// We put the definition of HashMap in 3rdparty/hash.hpp
	
  }  
}

#endif // __KNPC_MAP__
