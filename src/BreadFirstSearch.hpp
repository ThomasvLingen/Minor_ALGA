//
// Created by jazula on 11/9/16.
//

#ifndef SRC_BREADFIRSTSEARCH_HPP
#define SRC_BREADFIRSTSEARCH_HPP

#include <queue>
#include "Floor.hpp"

using std::queue;

class BreadFirstSearch {
public:
    static int get_distance_to_room_type(Coord start, Floor* floor, RoomType type);
};


#endif //SRC_BREADFIRSTSEARCH_HPP
