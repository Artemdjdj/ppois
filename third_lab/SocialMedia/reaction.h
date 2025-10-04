
#ifndef REACTION_H
#define REACTION_H
#include <string>
class Reaction {
	Reaction();
	explicit Reaction(const std::string& type_of_reaction);
	void SetReaction(std::string type_of_reaction);
	void GetReaction();
	void ChangReaction(std::string type_of_reaction);
private:
	std::string type_of_reaction_;
};
#endif //REACTION_H
