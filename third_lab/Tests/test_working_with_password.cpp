#include <gtest/gtest.h>
#include "../WorkingWithUser/working_with_password.h"

TEST(TestHashPasswortd, TestCheckClassHashPassword) {
    const auto new_password = HashPassword::HashInputPassword("123436sgskdh");
    ASSERT_TRUE(HashPassword::IsPasswordMatch("123436sgskdh",new_password));
}

TEST(TestHashPasswortd, TestCheckClassHashPasswordIncorrect) {
    const auto new_password = HashPassword::HashInputPassword("123436sgskdh");
    ASSERT_FALSE(HashPassword::IsPasswordMatch("123436sgskd",new_password));
}