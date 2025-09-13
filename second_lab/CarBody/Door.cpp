

#include "../include/include_door.h"


SideMirror::SideMirror(int height, int width, string color) {
    this->height = height;
    this->width = width;
    this->color = color;
}
SideMirror::~SideMirror() {}
void SideMirror::set_color(string color) {
    this->color = color;
}
void SideMirror::set_size(int height, int width) {
    this->height = height;
    this->width = width;
}
void SideMirror::get_color(string & color) {
    color = this->color;
}
void SideMirror::get_size(int & height, int & width) {
    height = this->height;
    width = this->width;
}

BackDoor::BackDoor(int height, int width): height(height), width(width) {}
BackDoor::~BackDoor(){}
void BackDoor::get_size(int & height, int & width) {
    height = this->height;
    width = this->width;
}
void BackDoor::set_size(int height, int width) {
    this->height = height;
    this->width = width;
}

FrontDoor::FrontDoor(int height_door,int width_door,int height_mirror ,int width_mirror,bool is_lock ,string color) : mirror(height_mirror, width_mirror, color),BackDoor::BackDoor(height_door, width_door){
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
//
// int main() {
//     BackDoor back_door = BackDoor(5,3);
//     FrontDoor front_door = FrontDoor(7,8 ,1,2,true, "green");
//     int height, width;
//     front_door.get_size(height, width);
//     cout<<height<< width<<endl;
//
//     return 0;
// }