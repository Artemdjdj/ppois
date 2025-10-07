#include "generator.h"
#include <random>
#include <string>
#include "../Exceptions/exceptions.h"
#include "../Utils/project_utils.h"

bool GeneratorId::CheckIdIsTaken(const std::string& id) const {
	return list_of_id_.contains(id);
}

bool GeneratorId::GenerateNewId(std::string &id) {
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

	try {
		if (count_of_attempts >= max_count_of_attempts) {
			throw ExceptionRuntimeError("Runtime error");
		}
		list_of_id_.emplace(id);
		return true;
	} catch (const ExceptionRuntimeError &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
		return false;
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
		return false;
	}
}

bool GeneratorId::DeleteId(const std::string &id) {
	const auto it = list_of_id_.find(id);
	if (it == list_of_id_.end()) {
		return false;
	}
	list_of_id_.erase(it);
	return true;
}