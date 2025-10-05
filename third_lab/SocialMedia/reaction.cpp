#include "reaction.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"

Reaction::Reaction() {
	// author_ = nullptr;
}

Reaction::Reaction(const std::string &type_of_reaction) {
	SetReaction(type_of_reaction);
}

void Reaction::SetReaction(std::string type_of_reaction) {
	try {
		DefaultProjectSettings::ToLower(type_of_reaction);
		if (!DefaultProjectSettings::CheckIsStatementInAllowed(type_of_reaction, reactions)) {
			throw ExceptionIncorrectReaction("This reaction is not allowed!");
		}
		this->type_of_reaction_ = type_of_reaction;
		// author_ = user;
	} catch (const ExceptionIncorrectReaction &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const Exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

std::string Reaction::GetReaction() {
	return this->type_of_reaction_;
}

void Reaction::DeleteReaction() {
	this->type_of_reaction_ = "";
}
