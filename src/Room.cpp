//
// Created by jazula on 10/31/16.
//

#include "Room.hpp"

Room::Room(RoomType room_type, int enemy_level)
: enemy_level(enemy_level)
, room_type(room_type)
{

}

Room::~Room()
{

}

bool Room::is_of_room_type(RoomType type_to_check)
{
    return this->room_type == type_to_check;
}
