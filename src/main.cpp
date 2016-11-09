#include <iostream>
#include "Floor.hpp"
#include "BreadFirstSearch.hpp"

int main() {
    Floor floor(4,5);
    floor.print_map();
    floor.build_adjecency_list();

    int index = BreadFirstSearch::get_distance_to_room_type({0,0}, &floor, RoomType::END);
    std::cout << std::endl << "Distance: " << index << std::endl;

}
