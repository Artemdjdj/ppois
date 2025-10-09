#include "generator_id.h"
#include "../Exceptions/exceptions.h"
#include "project_settings.h"
#include "../ProductionDepartment/Include/basic_params.h"
#include <string>
#include <random>



bool GeneratorId::CheckIdIsTaken(const std::string& id) const {
	return list_of_id_.contains(id);
}

void GeneratorId::GenerateNewId(std::string &id) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<int> dis(0, 9);

	int count_of_attempts = 0;

	while ((id.length() < length_of_id || CheckIdIsTaken(id)) && count_of_attempts < max_count_of_attempts) {
		id = "";
		for (int i = 0; i < length_of_id; i++) {
			id += std::to_string(dis(gen));
		}
		count_of_attempts++;
	}

	if (count_of_attempts >= max_count_of_attempts) {
		throw ExceptionRuntimeError("Runtime error");
	}
	list_of_id_.emplace(id);
}

bool GeneratorId::DeleteId(const std::string &id) {
	const auto it = list_of_id_.find(id);
	if (it == list_of_id_.end()) {
		return false;
	}
	list_of_id_.erase(it);
	return true;
}
