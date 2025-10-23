#ifndef STORY_H
#define STORY_H
#include <string>
#include <unordered_set>
#include <../User/user.h>
const std::unordered_set<std::string> kStoriesCategories{"default", "worth a look", "important"};

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

    static bool CheckIsCategoryCorrect(const std::string &category);
};

class Story {
public:
    // Story() = default;

    Story(const std::string &name, const std::string &info, const StorySettings &settings,
          const std::string &author, const std::string &id);

    // void SetId(const std::string &id);

    void SetName(const std::string &name, const std::string &user);

    void SetInfo(const std::string &info, const std::string &user);

    void MakeVisibilityPublic(bool is_public, const std::string &user);

    std::string GetName();

    std::string GetInfo();

    std::string GetStoryCategory() const;

    bool CheckIsPublic() const;

    std::string GetId() const;

private:
    std::string id_;
    std::string name_;
    std::string info_;
    StorySettings settings_;
    std::string author_;
};

#endif //STORY_H
