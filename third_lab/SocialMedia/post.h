#ifndef POST_H
#define POST_H
#include <string>
#include <map>
#include <vector>
#include "hash_tag.h"
#include "reaction.h"
#include "poll.h"
#include "../User/user.h"

class Post {
public:

	Post(const std::string &name, const std::string &info, User *author);

	void SetName(const std::string &name, const User *author);

	void SetInfo(const std::string &info, const User *author);

	std::string GetName() const;

	std::string GetInfo() const;

	void AddReaction(Reaction *reaction);

	void RemoveReaction(const std::string &username);

	Reaction* SeeReactionByAuthor(const std::string &username) const;

	void AddHashTag(HashTag *hash_tag);

	void RemoveHashTag(const std::string &hash_tag, const User *author);

	void AddPoll(Poll *poll, const User *author);

	void RemovePoll(const std::string &question, const User *author);

private:
	std::string name_;
	std::string info_;
	std::map<std::string, Reaction*> reactions_;
	std::vector<HashTag*> hash_tags_;
	std::vector<Poll*> polls_;
	User *author_;

	int CheckHashTagUsed(const std::string &check_hash_tag) const;

	int CheckPollUsed(const std::string &check_question) const;

	bool CheckPollUsedInList(const Poll *check_poll) const;
};

#endif //POST_H
