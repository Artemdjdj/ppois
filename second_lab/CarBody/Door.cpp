
#include "include_door.h"

SideMirror::SideMirror(int height, int width, string color):BasicParams(height, width) {
    this->color = color;
}
SideMirror::~SideMirror() {}

void SideMirror::set_color(string color) {
    this->color = color;
}

void SideMirror::get_color(string & color) {
    color = this->color;
}

BackDoor::BackDoor(int height, int width):BasicParams(height, width) {}

BackDoor::~BackDoor(){}

FrontDoor::FrontDoor(int height_door,int width_door,int height_mirror ,int width_mirror,bool is_lock ,string color) : mirror(height_mirror, width_mirror, color),BackDoor(height_door, width_door){
        this->is_lock = is_lock;
}

void FrontDoor::open_door() {
    this->is_lock = true;
}

void FrontDoor::close_door() {
    this->is_lock = false;
}

void FrontDoor::get_color_of_mirror(string& result_color) {
    mirror.get_color(result_color);
}

// int main() {
//     BackDoor back_door = BackDoor(5,3);
//     FrontDoor front_door = FrontDoor(7,8 ,1,2,true, "green");
//     int height, width;
//     front_door.get_size(height, width);
//     front_door.set_size(89, 123);
//     cout<<height<<" "<< width<<endl;
//     front_door.get_size(height, width);
//     cout<<height<<" "<< width<<endl;
//
//     return 0;
// }