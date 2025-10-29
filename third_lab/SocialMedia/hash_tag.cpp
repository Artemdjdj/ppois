#include "hash_tag.h"
#include "exceptions.h"
#include "../Utils/project_utils.h"
#include "../Utils/validator.h"

HashTag::HashTag() = default;

HashTag::HashTag(const std::string &hash_tag, const std::string &author) {
	SetHashTag(hash_tag, author);
}

void HashTag::SetHashTag(const std::string &hash_tag, const std::string &author) {
	if (ValidatorHashTag validator; !validator.Validate(hash_tag)) {
		throw ExceptionIncorrectHashTag("Your hash tag is not correct!");
	}
	this->hash_tag_ = hash_tag;
	this->date_time_ = TimeProvider::GetRealTime();
	this->author_ = author;
}

std::string HashTag::GetHashTag() const {
	return this->hash_tag_;
}

std::string HashTag::SeeAuthor() const {
	return this->author_;
}
