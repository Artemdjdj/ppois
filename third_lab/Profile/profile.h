#ifndef PROFILE_H
#define PROFILE_H
#include <map>
#include <string>

#include "../Communication/chat.h"
#include "../Generator/generator.h"
#include "../SocialMedia/reaction.h"
#include "../User/user.h"

class Profile {
public:
	Profile();

	explicit Profile(const User &user, const std::string &location, const std::string &biography);

	void SetUserUserName(const std::string &username);

	void SetUserName(const std::string &name);

	void SetUserSurname(const std::string &surname);

	void SetUserEmail(const std::string &email);

	void SetUserPhoneNumber(const std::string &phone_number);

	void SetUserPassword(const std::string &password);

	void SetLocation(const std::string &location);

	void SetBiography(const std::string &biography);

	void SetGender(const std::string &gender);

	void SetAge(int age);

	std::string GetUserUserName() const;

	std::string GetUserName() const;

	std::string GetUserSurname() const;

	std::string GetUserEmail() const;

	std::string GetUserPhoneNumber() const;

	std::string GetGender() const;

	std::string GetLocation() const;

	std::string GetBiography() const;

	int GetAge() const;

	void AddReaction(const std::string &type_of_reaction);

	void RemoveReaction(const std::string &date_time);

	void RemoveAllReactions();

	void CreateNewChat(User *user2);

	void RemoveChat(const std::string &chat_id);

	void CreateNewGroup(const std::string &name_of_group);

	void RemoveGroup(const std::string &group_id);

private:
	User user_;
	std::string location_;
	std::string biography_;
	std::string gender_;
	int age_;
	std::vector<std::string> interests_;
	std::map<std::string, Group> groups_;
	std::map<std::string, Chat> chats_;
	GeneratorId generator_id_for_groups_;
	GeneratorId generator_id_for_chats_;
};

#endif //PROFILE_H
