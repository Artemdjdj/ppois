#ifndef POST_H
#define POST_H
#include <string>
#include <map>
#include <vector>
#include "hash_tag.h"
#include "reaction.h"
#include "poll.h"
#include "../User/user.h"
#include "../Utils/project_utils.h"

class Post{
public:

	Post(const std::string &name, const std::string &info, const std::shared_ptr<User> &author, const std::string &id_);

	// void SetId(const std::string &id);

	void SetName(const std::string &name, const std::shared_ptr<User> &author);

	void SetInfo(const std::string &info, const std::shared_ptr<User> &author);

	std::string GetName() const;

	std::string GetInfo() const;

	std::string GetId() const;

	void AddReaction(const std::shared_ptr<Reaction> &reaction);

	void RemoveReaction(const std::string &username);

	std::shared_ptr<Reaction> SeeReactionByAuthor(const std::string &username) const;

	void AddHashTag(const std::shared_ptr<HashTag> &hash_tag);

	void RemoveHashTag(const std::string &hash_tag, const std::shared_ptr<User> &author);

	void AddPoll(const std::shared_ptr<Poll> &poll, const  std::shared_ptr<User> &author);

	void RemovePoll(const std::string &question, const std::shared_ptr<User> &author);

private:
	std::string id_;
	std::string name_;
	std::string info_;
	std::map<std::string, std::shared_ptr<Reaction>> kReactions_;
	std::vector<std::shared_ptr<HashTag>> hash_tags_;
	std::vector<std::shared_ptr<Poll>> polls_;
	std::weak_ptr<User> author_;

	int CheckHashTagUsed(const std::string &check_hash_tag) const;

	int CheckPollUsed(const std::string &check_question) const;

	bool CheckPollUsedInList(const std::shared_ptr<Poll> &check_poll) const;
};

#endif //POST_H
