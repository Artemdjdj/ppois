#ifndef REACTION_H
#define REACTION_H
#include <memory>
#include <string>
#include <unordered_set>
#include "user.h"
const std::unordered_set<std::string> kReactions{"angry", "sadness", "love", "like"};

class Reaction {
public:
	Reaction();

	explicit Reaction(const std::string &type_of_reaction, const std::string &author);

	void SetReaction(std::string type_of_reaction, const std::string &author);

	std::string SeeAuthor() const;

	std::string GetReaction() const;;

private:
	std::string type_of_reaction_;
	std::string date_time_;
	std::string author_;
};
#endif //REACTION_H
