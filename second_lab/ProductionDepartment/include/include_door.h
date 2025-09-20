//
// Created by Redmi on 13.09.2025.
//

#ifndef INCLUDE_DOOR_H
#define INCLUDE_DOOR_H

#include<string>
#include <iostream>
#include "include_basic_params.h"

class SideMirror: public BasicParams, public Color {
public:
    SideMirror(int height =0, int width =0, std::string color="black");
    ~SideMirror();
};

class BackDoor:public BasicParams {
public:
    BackDoor(int height, int width);
    ~BackDoor();
};

class FrontDoor : public BackDoor {
private:
    bool is_lock = false;
    SideMirror mirror;
public:
    FrontDoor(
    int height_door = 0,
    int width_door = 0,
    int height_Mirror = 0,
    int width_Mirror = 0,
    bool is_lock = false,
    std::string color = "black"
);
    void open_door();
    void close_door();
    bool get_lock();
    void get_color_of_mirror(std::string& result_color);
};

#endif //INCLUDE_DOOR_H
