#include "post.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"


Post::Post(const std::string &name, const std::string &info, User *author): name_(name), info_(info), author_(author) {
};

void Post::SetName(const std::string &name, const User *author) {
	if (author_ != author) {
		throw ExceptionAccess("You don't have access to changing this post");
	}
	this->name_ = name;
}

void Post::SetInfo(const std::string &info, const User *author) {
	if (author_ != author) {
		throw ExceptionAccess("You don't have access to changing this post");
	}
	this->info_ = info;
}

std::string Post::GetName() const {
	return this->name_;
}

std::string Post::GetInfo() const {
	return this->info_;
}

void Post::AddReaction(const std::string &reaction_of_user, User *author) {
	const auto reaction = Reaction(reaction_of_user, author);
	if (!reaction.GetReaction().empty()) {
		this->reactions_[author->GetUserName()] = reaction;
	}
}

void Post::RemoveReaction(const std::string &username) {
	auto it = reactions_.erase(username);
	if (it == 0) {
		DefaultProjectSettings::LogFile("Such reaction is not exist", main_log_file);
	}
}

void Post::AddHashTag(const std::string &hash_tag_of_user, User *author) {
	const auto hash_tag = HashTag(hash_tag_of_user, author);
	if (!hash_tag.GetHashTag().empty()) {
		this->hash_tags_[author->GetUserName()] = hash_tag;
	}
}

void Post::RemoveHashTag(const std::string &username) {
	auto it = hash_tags_.erase(username);
	if (it == 0) {
		DefaultProjectSettings::LogFile("Such hash tag is not exist", main_log_file);
	}
}
