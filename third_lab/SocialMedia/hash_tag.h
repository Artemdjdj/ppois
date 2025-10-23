#ifndef HASH_TAG_H
#define HASH_TAG_H
#include <string>
#include "../User/user.h"

class HashTag {
public:
	HashTag();

	explicit HashTag(const std::string &hash_tag, const std::string &author);

	void SetHashTag(const std::string &hash_tag, const std::string &author);

	std::string GetHashTag() const;

	std::string SeeAuthor() const;

private:
	std::string hash_tag_;
	std::string date_time_;
	std::string author_;
};

#endif //HASH_TAG_H
