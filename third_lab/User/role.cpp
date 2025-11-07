
#include "role.h"

#include "exceptions.h"
#include "../Utils/validator.h"

Role::Role() = default;

Role::Role(const std::string& name_of_role) {
	ChooseRole(name_of_role);
}

void Role::ChooseRole(const std::string& name_of_role) {
	if (!ValidatorString::CheckIsStatementInAllowed(name_of_role, kAloudRoles)) {
		throw ExceptionIncorrectRole("Such role is not exist");
	}
	this->name_of_role_ = name_of_role;
}

std::string Role::GetRole() const{
	return this->name_of_role_;
}