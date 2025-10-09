#include "handbrake.h"

Handbrake::Handbrake(): size_() {
}

Handbrake::Handbrake(int height, int width, bool is_car_block_now): size_(height, width) {
	this->is_block_ = is_car_block_now;
}

void Handbrake::SetSize(int height, int width) {
	this->size_.SetSize(height, width);
}

int Handbrake::GetHeight() const {
	return this->size_.GetHeight();
}

int Handbrake::GetWidth() const {
	return this->size_.GetWidth();
}

void Handbrake::BlockCar() {
	this->is_block_ = true;
}

void Handbrake::UnblockCar() {
	this->is_block_ = false;
}

bool Handbrake::GetIsBlock() const {
	return this->is_block_;
}
