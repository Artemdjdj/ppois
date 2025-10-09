#include "metal_links.h"

Plata::Plata() = default;

Plata::Plata(int height, int width): size_(height, width) {
}

void Plata::SetPlataSize(int height, int width) {
	this->size_.SetSize(height, width);
}

int Plata::GetHeightOfPlata() const {
	return this->size_.GetHeight();
}

int Plata::GetWidthOfPlata() const {
	return this->size_.GetWidth();
}

std::string Plata::GetMaterial() const {
	return this->material_;
}

MetalCylinder::MetalCylinder(): Tube() {
};

MetalCylinder::MetalCylinder(int radius, int height, int weight): Tube(radius, height), weight_(weight) {
}

void MetalCylinder::SetWeight(int weight) {
	SetSingleValue(weight, "Weight, can't be negative or zero!", this->weight_);
}

int MetalCylinder::GetWeight() const {
	return this->weight_;
}

MetalLink::MetalLink() {
};

MetalLink::MetalLink(int height_of_plata, int width_of_plata, int radius, int height,
					int weight): cylinder_(radius, height, weight),
								two_plats_(Plata(height_of_plata, width_of_plata),
											Plata(height_of_plata, width_of_plata)) {
}

void MetalLink::SetDataForCylinder(int radius, int height, int weight) {
	cylinder_.SetWeight(weight);
	cylinder_.SetRadius(radius);
	cylinder_.SetHeight(height);
}

void::MetalLink::SetDataForTwoPlats(int height_of_plata, int width_of_plata) {
	this->two_plats_.first.SetPlataSize(height_of_plata, width_of_plata);
	two_plats_.second.SetPlataSize(
				height_of_plata, width_of_plata);
}

int MetalLink::GetHeightOfPlataForUser() const {
	return this->two_plats_.first.GetHeightOfPlata();
}

int MetalLink::GetWidthOfPlataForUser() const {
	return this->two_plats_.first.GetWidthOfPlata();
}

void MetalChain::AddNewMetalLink(const MetalLink &new_metal_link) {
	this->chain_.push_back(new_metal_link);
}

void MetalChain::DeleteMetalLink() {
	if (this->chain_.size() <= 0) return;
	this->chain_.pop_back();
}

int MetalChain::GetLensOfMetalChain() const {
	return this->chain_.size();
}
