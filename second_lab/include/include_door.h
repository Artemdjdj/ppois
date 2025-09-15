//
// Created by Redmi on 13.09.2025.
//

#ifndef INCLUDE_DOOR_H
#define INCLUDE_DOOR_H

#include<string>
#include <iostream>
#include "include_basic_params.h"
using namespace std;
class SideMirror: public BasicParams, public Color {
public:
    SideMirror(int height =0, int width =0, string color="black");
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
    int height_mirror = 0,
    int width_mirror = 0,
    bool is_lock = false,
    string color = "black"
);
    void open_door();
    void close_door();
    bool get_lock();
    void get_color_of_mirror(string& result_color);
};

#endif //INCLUDE_DOOR_H
