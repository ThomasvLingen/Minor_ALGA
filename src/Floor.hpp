//
// Created by jazula on 10/31/16.
//

#ifndef SRC_FLOOR_HPP
#define SRC_FLOOR_HPP


#include "Room.hpp"
#include <vector>
#include <iostream>
#include <map>
#include "RoomEdge.hpp"

using std::vector;
using std::cout;
using std::endl;
using std::map;

struct Coord {
    size_t x;
    size_t y;
};

class Floor {
public:
    Floor(int width, int height);
    virtual ~Floor();

    int width;
    int height;
    void print_map();
    void build_adjecency_list();
    bool are_adjecent(int room_1_index, int room_2_index);
    size_t get_room_index(Coord coord);
    vector<size_t> get_adjecent_room_indexes(size_t current_room_index);
    void set_end_room();

    vector<Room*> rooms;

    map<int, vector<RoomEdge>> adjecency_list;

    map<RoomType, char> room_type_to_char_map = {
        {RoomType::NORMAL, 'n'},
        {RoomType::START, 'S'},
        {RoomType::END, 'E'}
    };
};


#endif //SRC_FLOOR_HPP
