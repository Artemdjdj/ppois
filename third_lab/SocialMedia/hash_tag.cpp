#include "hash_tag.h"
#include "exceptions.h"
#include "../User/user_utils.h"
#include "../Utils/project_utils.h"

HashTag::HashTag() = default;

HashTag::HashTag(const std::string &hash_tag) {
	SetHashTag(hash_tag);
}

void HashTag::SetHashTag(const std::string &hash_tag) {
	try {
		DataSyntax::CheckHashTagForSyntaxError(hash_tag, "Your hash tag is not correct!", this->hash_tag_);
	} catch (const ExceptionIncorrectHashTag &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
	catch (const std::exception &e) {
		DefaultProjectSettings::LogFile(e.what(), main_log_file);
	}
}

std::string HashTag::GetHashTag() const {
	return this->hash_tag_;
}