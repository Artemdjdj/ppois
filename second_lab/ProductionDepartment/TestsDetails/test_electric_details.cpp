#include "../ElectricDetails/electric_details.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

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
	starter.ChooseLeftDirection();
	ASSERT_TRUE(starter.GetDirection());
}

TEST_F(TestElectroDetails, TestChooseRightDirection) {
	starter.ChooseRightDirection();
	ASSERT_FALSE(starter.GetDirection());
}

TEST_F(TestElectroDetails, TestSetCountOfProng) {
	starter.SetCountOfProg(10);
	ASSERT_EQ(starter.GetCountOfProg(), 10);
}

TEST_F(TestElectroDetails, TestSetCountOfProngNegative) {
	ASSERT_THROW(
		starter.SetCountOfProg(-10),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(starter.GetCountOfProg(), 9);
}


TEST_F(TestElectroDetails, TestSetColdCrankingCurrent) {
	battery.SetColdCrankingCurrent(111);
	ASSERT_EQ(battery.GetColdCrankingCurrent(), 111);
}

TEST_F(TestElectroDetails, TestSetColdCrankingCurrentNegative) {
	ASSERT_THROW(
		battery.SetColdCrankingCurrent(-111),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(battery.GetColdCrankingCurrent(), 300);
}

TEST_F(TestElectroDetails, BatteryDescription) {
	EXPECT_EQ(battery.GetInfoAboutPart(), "This detail name is battery");
}

TEST_F(TestElectroDetails, StarterDescription) {
	EXPECT_EQ(starter.GetInfoAboutPart(), "This detail name is starter");
}
