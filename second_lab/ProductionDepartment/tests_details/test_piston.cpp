#include "../Engine/piston.h"
#include <gtest/gtest.h>

TEST(TestPiston, TestSetAllParams) {
    Piston piston = Piston();
    ASSERT_TRUE(piston.set_all_parameters(2,3,4,5,6));
}

TEST(TestPiston, TestSetAllParamsNegative) {
    Piston piston = Piston();
    ASSERT_FALSE(piston.set_all_parameters(-2,3,4,5,6));
}

TEST(TestPiston, TestGetWeight) {
    Piston piston = Piston(2,3,4,5,6);
    ASSERT_EQ(piston.get_weight(),6);
}

TEST(TestPiston, TestWorkPiston) {
    Piston piston = Piston(2,3,4,5,6);
    ASSERT_TRUE(piston.check_is_piston_in_working_condition());
}
