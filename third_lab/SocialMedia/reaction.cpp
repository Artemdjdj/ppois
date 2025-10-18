#include "reaction.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"

Reaction::Reaction() {
	// author_ = nullptr;
}

Reaction::Reaction(const std::string &type_of_reaction, const std::shared_ptr<User> &author) {
	SetReaction(type_of_reaction, author);
}

void Reaction::SetReaction(std::string type_of_reaction, const std::shared_ptr<User> &author) {
	DefaultProjectSettings::ToLower(type_of_reaction);
	if (!DefaultProjectSettings::CheckIsStatementInAllowed(type_of_reaction, reactions)) {
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
	if (!this->author_.lock()) {
		throw ExceptionAccess("Try to add author!");
	}
	return  this->author_.lock()->GetUserName();
}

