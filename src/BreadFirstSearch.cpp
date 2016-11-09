//
// Created by jazula on 11/9/16.
//

#include "BreadFirstSearch.hpp"
#include <algorithm>
#include <map>

using std::map;

int BreadFirstSearch::get_distance_to_room_type(Coord start, Floor* floor, RoomType type)
{
    queue<size_t> room_queue;
    vector<size_t> checked_indexes;
    map<size_t, size_t> index_to_distance;
    room_queue.push(floor->get_room_index(start)); //add start room to queue

    index_to_distance[floor->get_room_index(start)] = 0;

    while(!room_queue.empty()){
        size_t current_index = room_queue.front();
        room_queue.pop();
        checked_indexes.push_back(current_index);
        Room* current_room = floor->rooms[current_index];

        if(current_room->is_of_room_type(type)){
            return (int)index_to_distance[current_index];
        } else {
            for(size_t index : floor->get_adjecent_room_indexes(current_index)){
                if(std::find(checked_indexes.begin(), checked_indexes.end(), index) == checked_indexes.end()){
                    room_queue.push(index);
                    checked_indexes.push_back(index);
                    index_to_distance[index] = index_to_distance[current_index] + 1;
                }
            }
        }

    }
    return -1;
}
