#include "reaction.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"

Reaction::Reaction() {
	// author_ = nullptr;
}

Reaction::Reaction(const std::string &type_of_reaction, User * author) {
	SetReaction(type_of_reaction, author);
}

void Reaction::SetReaction(std::string type_of_reaction, User * author) {
	try {
		DefaultProjectSettings::ToLower(type_of_reaction);
		if (!DefaultProjectSettings::CheckIsStatementInAllowed(type_of_reaction, reactions)) {
			throw ExceptionIncorrectReaction("This reaction is not allowed!");
		}
		this->type_of_reaction_ = type_of_reaction;
		this->date_time_ = DefaultProjectSettings::GetRealTime();
		author_ = author;
	} catch (const ExceptionIncorrectReaction &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const Exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

std::string Reaction::GetReaction() const {
	return this->type_of_reaction_;
}

std::string Reaction::SeeAuthor() const {
	return  this->author_->GetUserName();
}

