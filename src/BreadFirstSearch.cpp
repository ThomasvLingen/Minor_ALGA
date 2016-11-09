//
// Created by jazula on 11/9/16.
//

#include "BreadFirstSearch.hpp"
#include <algorithm>

int BreadFirstSearch::get_distance_to_room_type(Coord start, Floor* floor, RoomType type)
{
    queue<size_t> room_queue;
    vector<size_t> checked_indexes;
    room_queue.push(floor->get_room_index(start)); //add start room to queue

    int current_level = 0;
    while(!room_queue.empty()){
        size_t current_index = room_queue.front();
        std::cout << current_index << " ";
        room_queue.pop();
        checked_indexes.push_back(current_index);
        Room* current_room = floor->rooms[current_index];

        if(current_room->is_of_room_type(type)){
            break;
        } else {
            for(size_t index : floor->get_adjecent_room_indexes(current_index)){
                if(std::find(checked_indexes.begin(), checked_indexes.end(), index) == checked_indexes.end()){
                    room_queue.push(index);
                    checked_indexes.push_back(index);
                }
            }
            std::cout << " hi " ;
            current_level++;
        }

    }
    return current_level;
}
