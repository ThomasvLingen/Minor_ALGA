//
// Created by jazula on 10/31/16.
//

#include "Floor.hpp"


Floor::Floor(int width, int height)
: width(width)
, height(height)
{
    this->rooms.resize((size_t)(width * height)); //all nullptrs now
    rooms[0] = new Room(RoomType::START, 0);
    for(int index = 1; index < (width * height - 1); index++){
        rooms[index] = new Room(RoomType::NORMAL, 0);
    }
    rooms[height*width - 1] = new Room(RoomType::END, 0);
}

Floor::~Floor()
{

}

void Floor::print_map()
{
    for(int index = 0; index < (int)this->rooms.size(); index++){
        if(rooms[index] == nullptr){
            cout << '.';
        } else {
            cout << room_type_to_char_map[rooms[index]->room_type];
        }

        if((index + 1) % width == 0){
            cout << endl;
        } else {
            cout << "  "; //adjen
        }
    }
}

void Floor::build_adjecency_list()
{
    for(int room1 = 0; room1 < (int)rooms.size(); room1++){
        //for(int room2 = room1 - width; room2 <= room1 + width; room2++){
        for(int room2 = 0; room2 < (int)rooms.size(); room2++) {
            if(are_adjecent(room1, room2) && rooms[room1] != nullptr && rooms[room2] != nullptr){
                RoomEdge roomEdge = {
                    .room_id = room2,
                    .connection = Connection::OPEN
                };
                adjecency_list[room1].push_back(roomEdge);
            }
        }
    }
}

bool Floor::are_adjecent(int room_1_index, int room_2_index)
{
    if(room_2_index == room_1_index + width || room_2_index == room_1_index - width){
        return true;
    }
    else if(room_1_index + 1 == room_2_index && room_2_index % width != 0){
        return true;
    }
    else if (room_1_index - 1 == room_2_index && (room_2_index + 1) % width != 0) {
        return true;
    }
    return false;
}
