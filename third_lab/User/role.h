#ifndef ROLE_H
#define ROLE_H
#include <string>
#include <unordered_set>
const std::unordered_set<std::string> alloud_roles{"admin", "user"};

class Role {
public:
	Role();

	explicit Role(const std::string &name_of_role);

	void ChooseRole(const std::string &name_of_role);

	std::string GetRole() const;

private:
	std::string name_of_role_;
};
#endif //ROLE_H
