#ifndef STORY_H
#define STORY_H
#include <string>
#include <unordered_set>
#include <../User/user.h>
const std::unordered_set<std::string> stories_categories{"default", "worth a look", "important"};

class StorySettings {
public:
    StorySettings() = default;

    StorySettings(const std::string &category, bool is_public);

    void SetCategory(std::string category);

    void MakeStoryPublic();

    void MakeStoryPrivate();

    std::string GetCategory() const;

    bool GetTypeOfVisibility() const;

private:
    std::string category_;
    bool is_public_{false};

    static bool CheckIsCategoryCorrect(const std::string& category);
};

class Story {
public:
    Story() = default;

    Story(const std::string &name, const std::string &info, const StorySettings &settings, User * author);

    void SetStoryName(const std::string &name, const User * user);

    void SetStoryInfo(const std::string &info, const User *user);

    void ChangeVisibility(bool is_public);

    std::string GetStoryName();

    std::string GetStoryInfo();

    std::string GetStoryCategory() const;

    bool GetIsForAll() const;

private:
    std::string name_;
    std::string info_;
    StorySettings settings_;
    User* author_;
};

#endif //STORY_H
