#ifndef STORY_H
#define STORY_H
#include <string>
#include <unordered_set>
const std::unordered_set<std::string> stories_categories{"default", "worth a look", "important"};

class Story {
public:
	Story();

	Story(const std::string &name, const std::string &info, const std::string &category, bool is_for_all = false);

	void SetStoryName(const std::string &name);

	void SetStoryInfo(const std::string &info);

	void SetStoryCategory(std::string category);

	void MakeStoryForFriends();

	void MakeStoryForAll();

	std::string GetStoryName();

	std::string GetStoryInfo();

	std::string GetStoryCategory();

	bool GetIsForAll() const;

private:
	std::string name_;
	std::string info_;
	std::string category_;
	bool is_for_all_;
};

#endif //STORY_H
