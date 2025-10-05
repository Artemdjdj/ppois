

#ifndef POST_H
#define POST_H
#include <string>
#include <unordered_set>

#include "hash_tag.h"
#include "reaction.h"
#include "../User/user.h"
class Post {
private:
	std::string name_;
	std::string info_;
	std::unordered_set<Reaction> reactions_;
	std::unordered_set<HashTag> tags_;
};

#endif //POST_H
