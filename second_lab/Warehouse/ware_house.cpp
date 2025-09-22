#include "ware_house.h"
#include "../GeneratorId/generator_id.h"
#include <iostream>

bool WareHouse::AddNewDetail(CarPart *new_detail, std::string &my_id) {
	std::string id;
	if (!generated_id_.GenerateNewId(id)) {
		return false;
	}
	my_id = id;
	warehouse_.insert(std::make_pair(id, new_detail));
	return true;
}

bool WareHouse::DeleteDetailById(const std::string &id) {
	const int result = warehouse_.erase(id);
	generated_id_.DeleteId(id);
	return result != 0;
}

bool WareHouse::FindDetailById(const std::string &id, CarPart *&detail) {
	const auto element = warehouse_.find(id);
	if (element == warehouse_.end()) {
		return false;
	}
	detail = element->second;
	return true;
}

void WareHouse::GetAllDetails() {
	for (const auto &[key, value]: warehouse_) {
		std::cout << "Id: " << key << ", CarPart: " << value->GetInfoAboutPart() << std::endl;
	}
}
