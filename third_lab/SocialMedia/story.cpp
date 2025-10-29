#include "story.h"

#include <stdexcept>

#include "exceptions.h"
#include "../Utils/project_utils.h"

StorySettings::StorySettings(const std::string &category, const bool is_public): is_public_(is_public) {
    SetCategory(category);
}

void StorySettings::SetCategory(std::string category) {
    StringFormatter::ToLower(category);
    if (!ValidatorString::CheckIsStatementInAllowed(category, kStoriesCategories)) {
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
             const std::string &author, const std::string& id): id_(id), name_(name),
                            info_(info), settings_(settings), author_(author) {
}

// void Story::SetId(const std::string &id) {
//     this->id_ = id;
// }

void Story::SetName(const std::string &name, const std::string &user) {
    PropertySetter::SetValueWithAuthor(this->name_, name, this->author_, user, "You can't changing info about story",
                                     "You can't set name of your stories empty");
}

void Story::SetInfo(const std::string &info, const std::string &user) {
    PropertySetter::SetValueWithAuthor(this->info_, info, this->author_, user, "You can't changing info about story",
                                     "You can't set name of your stories empty");
}

void Story::MakeVisibilityPublic(const bool is_public, const std::string & user) {
    if (const auto author = author_; author != user) {
        throw std::invalid_argument("You can't change visibility of this story");
    }

    if (is_public) {
        settings_.MakeStoryPublic();
    } else {
        settings_.MakeStoryPrivate();
    }
}

std::string Story::GetName() {
    return this->name_;
}

std::string Story::GetInfo() {
    return this->info_;
}

std::string Story::GetStoryCategory() const {
    return this->settings_.GetCategory();
}

bool Story::CheckIsPublic() const {
    return this->settings_.GetTypeOfVisibility();
}

std::string Story::GetId() const {
    return this->id_;
}
