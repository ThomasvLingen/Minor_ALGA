#include <iostream>
#include "Floor.hpp"
#include "BreadFirstSearch.hpp"

int main() {
    std::cout << "Hi" << std::endl;

    Floor henk(4,5);
    henk.print_map();

//    for(int room1 = 0; room1 < 16; room1++){
//        for(int room2 = 0; room2 < 16; room2++){
//
//            if(henk.are_adjecent(room1, room2)){
//                cout << room1 << "->" << room2 << " = " << 1 << endl;
//            }
//
//        }
//        cout << endl;
//    }

    henk.build_adjecency_list();

//    for(auto brommer : henk.adjecency_list){
//        cout << brommer.first << ":  ";
//        for(auto wiel : brommer.second){
//            cout << wiel.room_id << "{" << wiel.connection << "}" ;
//        }
//        cout << endl;
//    }
    int index = BreadFirstSearch::get_distance_to_room_type({0,0}, &henk, RoomType::END);
    std::cout << std::endl << "Bobe: " << index << std::endl;

}
