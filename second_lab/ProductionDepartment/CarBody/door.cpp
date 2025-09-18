
#include "include_door.h"
#include "include_basic_params.h"
#include "settings.h"
#include <iostream>
#include <string>
SideMirror::SideMirror(int height, int width, std::string color):BasicParams(height, width), Color(color) {}

SideMirror::~SideMirror() {}

BackDoor::BackDoor(int height, int width):BasicParams(height, width) {}

BackDoor::~BackDoor(){}

FrontDoor::FrontDoor(int height_door,int width_door,int height_mirror ,int width_mirror,bool is_lock ,std::string color) :BackDoor(height_door, width_door), mirror(height_mirror, width_mirror, color){
        this->is_lock = is_lock;
}

bool FrontDoor::get_lock() {
    return is_lock;
}

void FrontDoor::open_door() {
    this->is_lock = true;
}

void FrontDoor::close_door() {
    this->is_lock = false;
}

void FrontDoor::get_color_of_mirror(std::string& result_color) {
    result_color = mirror.get_color();
}

