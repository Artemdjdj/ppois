#include "story.h"

#include <stdexcept>

#include "exceptions.h"
#include "../Utils/project_utils.h"

StorySettings::StorySettings(const std::string &category, bool is_public): is_public_(is_public) {
    SetCategory(category);
}

bool StorySettings::CheckIsCategoryCorrect(const std::string &category) {
    const auto it = kStoriesCategories.find(category);
    if (it == kStoriesCategories.end()) {
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
             const std::shared_ptr<User> &author, const std::string& id): id_(id), name_(name),
                            info_(info), settings_(settings), author_(author) {
}

// void Story::SetId(const std::string &id) {
//     this->id_ = id;
// }

void Story::SetName(const std::string &name, const std::shared_ptr<User> &user) {
    DefaultProjectSettings::SetValueWithAuthor(this->name_, name, this->author_.lock(), user, "You can't changing info about story",
                                     "You can't set name of your stories empty");
}

void Story::SetInfo(const std::string &info, const std::shared_ptr<User> &user) {
    DefaultProjectSettings::SetValueWithAuthor(this->info_, info, this->author_.lock(), user, "You can't changing info about story",
                                     "You can't set name of your stories empty");
}

void Story::MakeVisibilityPublic(const bool is_public, const std::shared_ptr<User> & user) {
    if (const auto author = author_.lock(); !author || author != user) {
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
