#include "hash_tag.h"
#include "exceptions.h"
#include "../User/user_utils.h"
#include "../Utils/project_utils.h"

HashTag::HashTag() = default;

HashTag::HashTag(const std::string &hash_tag, const std::shared_ptr<User> &author) {
	SetHashTag(hash_tag, author);
}

void HashTag::SetHashTag(const std::string &hash_tag, const std::shared_ptr<User> &author) {
	DataSyntax::CheckHashTagForSyntaxError(hash_tag, "Your hash tag is not correct!", this->hash_tag_);
	this->date_time_ = DefaultProjectSettings::GetRealTime();
	this->author_ = author;
}

std::string HashTag::GetHashTag() const {
	return this->hash_tag_;
}

std::string HashTag::SeeAuthor() const {
	return this->author_.lock()->GetUsername();
}
