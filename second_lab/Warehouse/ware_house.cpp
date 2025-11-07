#include "ware_house.h"
#include "../GeneratorId/generator_id.h"
#include <iostream>

void WareHouse::AddNewDetail(CarPart *new_detail, std::string &my_id) {
    std::string id;
    generated_id_.GenerateNewId(id);
    my_id = id;
    this->warehouse_.insert(std::make_pair(id, new_detail));
}

bool WareHouse::DeleteDetailById(const std::string &id) {
    const int result = this->warehouse_.erase(id);
    generated_id_.DeleteId(id);
    return result != 0;
}

bool WareHouse::FindDetailById(const std::string &id, CarPart *&detail) {
    const auto element = this->warehouse_.find(id);
    if (element == this->warehouse_.end()) {
        return false;
    }
    detail = element->second;
    return true;
}

std::map<std::string, CarPart *> WareHouse::GetWareHouse() {
    return this->warehouse_;
}

std::vector<CarPart *> WareHouse::GetAllDetails() const {
    std::vector<CarPart *> details;
    for (const auto &pair: this->warehouse_) {
        details.push_back(pair.second);
    }
    return details;
}

void WareHouse::DeleteAllDetails() {
    this->warehouse_.clear();
}
