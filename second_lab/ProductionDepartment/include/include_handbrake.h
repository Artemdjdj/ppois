

#ifndef INCLUDE_HANDBRAKE_H
#define INCLUDE_HANDBRAKE_H
#include "include_basic_params.h"

class Handbrake {
private:
    BasicParams size;
    bool is_block{false};
public:
    Handbrake();
    Handbrake(int height, int width, bool is_car_block_now);
    bool set_size(int height, int width);
    int get_height();
    int get_width();
    void block_car();
    void unblock_car();
    bool get_is_block();
};
#endif //INCLUDE_HANDBRAKE_H
