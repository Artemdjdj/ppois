#include "reaction.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"


Reaction::Reaction(const std::string &type_of_reaction, const std::string &author) {
	SetReaction(type_of_reaction, author);
}

void Reaction::SetReaction(std::string type_of_reaction, const std::string &author) {
	DefaultProjectSettings::ToLower(type_of_reaction);
	if (!DefaultProjectSettings::CheckIsStatementInAllowed(type_of_reaction, kReactions)) {
		throw ExceptionIncorrectReaction("This reaction is not allowed!");
	}
	this->type_of_reaction_ = type_of_reaction;
	this->date_time_ = DefaultProjectSettings::GetRealTime();
	this->author_ = author;
}

std::string Reaction::GetReaction() const {
	return this->type_of_reaction_;
}

std::string Reaction::SeeAuthor() const {
	return  this->author_;
}

