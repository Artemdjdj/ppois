#ifndef REACTION_H
#define REACTION_H
#include <memory>
#include <string>
#include <unordered_set>
#include "user.h"
const std::unordered_set<std::string> reactions{"anger", "sadness", "love", "like"};

class Reaction {
public:
	Reaction();

	explicit Reaction(const std::string &type_of_reaction);

	void SetReaction(std::string type_of_reaction);

	void DeleteReaction();

	std::string GetReaction();

private:
	std::string type_of_reaction_;
	// User * author_;
};
#endif //REACTION_H
