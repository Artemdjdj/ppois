#include "door.h"
#include "basic_params.h"
#include <iostream>
#include <string>

SideMirror::SideMirror(const int height, const int width, const Color &color) : BasicParams(height, width) {
    this->color_ = color;
}

void SideMirror::SetColor(const Color &color) {
    this->color_ = color;
}

std::string SideMirror::GetColor() const {
    return this->color_.GetColor();
}

BackDoor::BackDoor(const int height, const int width) : BasicParams(height, width) {
}

FrontDoor::FrontDoor(const int height, const int width, const SideMirror &mirror, const bool is_lock) : BackDoor(
    height, width) {
    this->mirror_ = mirror;
    this->is_lock_ = is_lock;
}

void FrontDoor::SetMirror(const SideMirror &mirror) {
    this->mirror_ = mirror;
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

std::string FrontDoor::GetColorOfMirror() const {
    return this->mirror_.GetColor();
}
