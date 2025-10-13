#include <gtest/gtest.h>
#include "../User/role.h"
#include "../Exceptions/exceptions.h"

TEST(TestRole, TestCreationRole) {
    Role role = Role("admin");
    ASSERT_EQ(role.GetRole(), "admin");
}

TEST(TestRole, TestSetIncorrrectRole) {
    auto role = Role();
    ASSERT_THROW(
        role.ChooseRole("flksdjflks"),
        ExceptionIncorrectRole);
    ASSERT_EQ(role.GetRole(), "");
}
