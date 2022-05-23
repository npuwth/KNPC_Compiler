/*****************************************************
 *  Location Record.
 *
 *
 *  Keltin Leung 
 */

#ifndef __KNPC_LOCATION__
#define __KNPC_LOCATION__

#include <iostream>

namespace knpc {

#define KNPC_LOCATION_DEFINED
struct Location {
    int line;
    int col;

    Location(int l, int c) : line(l), col(c) {}

    Location(int l) : line(l), col(-1) {}
};

inline bool operator<(const Location &lhs, const Location &rhs) {
    return lhs.line < rhs.line || (lhs.line == rhs.line && lhs.col < rhs.col);
}

} // namespace knpc

#endif // __KNPC_LOCATION__
