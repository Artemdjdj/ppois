#include "story.h"

#include "../Utils/project_utils.h"

Story::Story() = default;

Story::Story(const std::string &name, const std::string &info, const std::string &category,
			const bool is_for_all): name_(name), info_(info), is_for_all_(is_for_all) {
	SetStoryCategory(category);
}

void Story::SetStoryName(const std::string &name) {
	name_ = name;
}

void Story::SetStoryInfo(const std::string &info) {
	info_ = info;
}

void Story::SetStoryCategory(std::string category) {
	DefaultProjectSettings::ToLower(category);
	if (DefaultProjectSettings::CheckIsStatementInAllowed(category, stories_categories)) {
		category_ = category;
	} else {
		DefaultProjectSettings::LogFile("Incorrect Category", main_log_file);
	}
}

void Story::MakeStoryForFriends() {
	this->is_for_all_ = false;
}

void Story::MakeStoryForAll() {
	this->is_for_all_ = true;
}

std::string Story::GetStoryName() {
	return this->name_;
}

std::string Story::GetStoryInfo() {
	return this->info_;
}

std::string Story::GetStoryCategory() {
	return this->category_;
}

bool Story::GetIsForAll() const {
	return this->is_for_all_;
}
