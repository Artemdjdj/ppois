#include "include_electric_details.h"
#include <gtest/gtest.h>

class TestElectroDetails : public ::testing::Test {
public:
    void SetUp() override {
        starter = Starter(100, 200, 300, true, 9);
        battery = Battery(100, 200, 300, 300);
    }
    Starter starter;
    Battery battery;
};

TEST_F(TestElectroDetails, TestChooseLeftDirection) {
    starter.choose_left_direction();
    ASSERT_TRUE(starter.get_direction());
}

TEST_F(TestElectroDetails, TestChooseRightDirection) {
    starter.choose_right_direction();
    ASSERT_FALSE(starter.get_direction());
}

TEST_F(TestElectroDetails, TestSetCountOfProng) {
    starter.set_count_of_prog(10);
    ASSERT_EQ(starter.get_count_of_prog(), 10);
}

TEST_F(TestElectroDetails, TestSetCountOfProngNegative) {
    starter.set_count_of_prog(-10);
    ASSERT_EQ(starter.get_count_of_prog(), 9);
}

TEST_F(TestElectroDetails, TestStarterPurpose) {
    ASSERT_EQ(starter.get_purpose(), "This electro part has name Starter!");
}

TEST_F(TestElectroDetails, TestSetColdCrankingCurrent) {
    battery.set_cold_cranking_current(111);
    ASSERT_EQ(battery.get_cold_cranking_current(), 111);
}

TEST_F(TestElectroDetails, TestSetColdCrankingCurrentNegative) {
    battery.set_cold_cranking_current(-111);
    ASSERT_EQ(battery.get_cold_cranking_current(), 300);
}

TEST_F(TestElectroDetails, TestBatteryPurpose) {
    ASSERT_EQ(battery.get_purpose(), "This electro part has name Battery!");
}

