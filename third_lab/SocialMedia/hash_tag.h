#ifndef HASH_TAG_H
#define HASH_TAG_H
#include <string>

class HashTag {
public:
	HashTag();

	explicit HashTag(const std::string &hash_tag);

	void SetHashTag(const std::string &hash_tag);

	std::string GetHashTag() const;

private:
	std::string hash_tag_;
};

#endif //HASH_TAG_H
