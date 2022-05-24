/*****************************************************
 *  Garbage-collectable Data Structure: Stack.
 *
 *  NOTE: just treat it like std::stack.
 *
 *  Keltin Leung 
 */

#ifndef __KNPC_STACK__
#define __KNPC_STACK__

#include "boehmgc.hpp"

#include <vector>
#include <stack>

namespace knpc {

  namespace util {

	// Iteratable Stack (garbage-collectable version)
	template<typename _T>
	class Stack : public std::stack<_T, std::vector<_T, gc_allocator<_T> > > {
	  // we use "std::vector" as the underlying container
	private:
	  typedef std::vector<_T, gc_allocator<_T> > _Cntner;
	  typedef std::stack<_T, _Cntner>            _Super;
	  
	public:
	  typedef typename _Cntner::reverse_iterator iterator;
	  
	  iterator begin(void) { return _Super::c.rbegin(); }
	  iterator end(void)   { return _Super::c.rend(); }
	};
	
  }  
}

#endif // __KNPC_STACK__
