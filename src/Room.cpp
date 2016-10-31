//
// Created by jazula on 10/31/16.
//

#include "Room.hpp"

Room::Room(RoomType room_type, int enemy_level)
: room_type(room_type)
, enemy_level(enemy_level)

{

}

Room::~Room()
{

}

bool Room::is_of_room_type(RoomType type_to_check)
{
    return this->room_type == type_to_check;
}
