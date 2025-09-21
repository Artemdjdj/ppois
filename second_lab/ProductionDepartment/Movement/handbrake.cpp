#include "handbrake.h"

Handbrake::Handbrake():size(){}

Handbrake::Handbrake(int height, int width, bool is_car_block_now):
size(height, width) {
    this->is_block = is_car_block_now;
}

bool Handbrake::set_size(int height, int width) {
    return this->size.set_size(height, width);
}

int Handbrake::get_height() {
    return this->size.get_height();
}

int Handbrake::get_width() {
    return this->size.get_width();
}

void Handbrake::block_car() {
    this->is_block = true;
}

void Handbrake::unblock_car() {
    this->is_block = false;
}

bool Handbrake::get_is_block() {
    return this->is_block;
}