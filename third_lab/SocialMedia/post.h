#ifndef POST_H
#define POST_H
#include <string>
#include <map>

#include "hash_tag.h"
#include "reaction.h"
#include "../User/user.h"

class Post {
public:
	Post(const std::string &name, const std::string &info, User *author);

	void SetName(const std::string &name, const User *author);

	void SetInfo(const std::string &info, const User *author);

	std::string GetName() const;

	std::string GetInfo() const;

	void AddReaction(const std::string &reaction, User *author);

	void RemoveReaction(const std::string &username);

	void AddHashTag(const std::string &hash_tag, User *author);

	void RemoveHashTag(const std::string &username);

private:
	std::string name_;
	std::string info_;
	std::map<std::string, Reaction> reactions_;
	std::map<std::string, HashTag> hash_tags_;
	User *author_;
};

#endif //POST_H
