#include "door.h"
#include "basic_params.h"
#include <iostream>
#include <string>

SideMirror::SideMirror(int height, int width, std::string color): BasicParams(height, width), Color(color) {
}

SideMirror::~SideMirror() {
}

BackDoor::BackDoor(int height, int width): BasicParams(height, width) {
}

BackDoor::~BackDoor() {
}

FrontDoor::FrontDoor(int height_door, int width_door, int height_mirror, int width_mirror, bool is_lock,
					std::string color) : BackDoor(height_door, width_door),
										mirror_(height_mirror, width_mirror, color) {
	this->is_lock_ = is_lock;
}

bool FrontDoor::GetLock() const {
	return is_lock_;
}

void FrontDoor::OpenDoor() {
	this->is_lock_ = true;
}

void FrontDoor::CloseDoor() {
	this->is_lock_ = false;
}

void FrontDoor::GetColorOfMirror(std::string &result_color) {
	result_color = mirror_.GetColor();
}
