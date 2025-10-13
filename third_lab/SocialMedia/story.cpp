#include "story.h"

#include <stdexcept>

#include "exceptions.h"
#include "../Utils/project_utils.h"

StorySettings::StorySettings(const std::string &category, bool is_public): is_public_(is_public) {
    SetCategory(category);
}

bool StorySettings::CheckIsCategoryCorrect(const std::string &category) {
    const auto it = stories_categories.find(category);
    if (it == stories_categories.end()) {
        return false;
    }
    return true;
}

void StorySettings::SetCategory(std::string category) {
    DefaultProjectSettings::ToLower(category);
    if (!CheckIsCategoryCorrect(category)) {
        throw std::invalid_argument("Invalid category!");
    }
    this->category_ = category;
}

void StorySettings::MakeStoryPublic() {
    this->is_public_ = true;
}

void StorySettings::MakeStoryPrivate() {
    this->is_public_ = false;
}

std::string StorySettings::GetCategory() const {
    return this->category_;
}

bool StorySettings::GetTypeOfVisibility() const {
    return this->is_public_;
}

Story::Story(const std::string &name, const std::string &info, const StorySettings &settings,
             User *author): name_(name), info_(info),
                            settings_(settings), author_(author) {
}

void Story::SetStoryName(const std::string &name, const User *user) {
    DefaultProjectSettings::SetValue(this->name_, name, this->author_, user, "You can't changing info about story",
                                     "You can't set name of your stories empty");
}

void Story::SetStoryInfo(const std::string &info, const User *user) {
    DefaultProjectSettings::SetValue(this->info_, info, this->author_, user, "You can't changing info about story",
                                     "You can't set name of your stories empty");
}

void Story::ChangeVisibility(const bool is_public) {
    if (is_public) {
        settings_.MakeStoryPublic();
    } else {
        settings_.MakeStoryPrivate();
    }
}

std::string Story::GetStoryName() {
    return this->name_;
}

std::string Story::GetStoryInfo() {
    return this->info_;
}

std::string Story::GetStoryCategory() const {
    return this->settings_.GetCategory();
}

bool Story::GetIsForAll() const {
    return this->settings_.GetTypeOfVisibility();
}
