//
// Created by jazula on 10/31/16.
//

#ifndef SRC_ROOM_HPP
#define SRC_ROOM_HPP


enum RoomType {
    START,
    END,
    NORMAL
};

class Room {
public:
    Room(RoomType  room_type, int enemy_level);
    virtual ~Room();

    RoomType room_type;
    int enemy_level;
};


#endif //SRC_ROOM_HPP
