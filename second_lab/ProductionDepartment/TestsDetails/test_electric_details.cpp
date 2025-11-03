#include "../ElectricDetails/electric_details.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestElectroDetails : public ::testing::Test {
public:
    void SetUp() override {
        starter = Starter(100, 200, 300, 10, 20, true, 9);
        battery = Battery(100, 200, 300, 10, 20, 300);
    }

    Starter starter;
    Battery battery;
};

TEST_F(TestElectroDetails, TestSetVoltage) {
    starter.SetVoltage(10);
    ASSERT_EQ(starter.GetVoltage(), 10);
}

TEST_F(TestElectroDetails, TestSetIncorrectVoltage) {
    ASSERT_THROW(
        starter.SetVoltage(-10),
        ExceptionIncorrectSize
    );
}

TEST_F(TestElectroDetails, TestSetPower) {
    starter.SetPower(20);
    ASSERT_EQ(starter.GetPower(), 20);
}

TEST_F(TestElectroDetails, TestSetIncorrectPower) {
    ASSERT_THROW(
        starter.SetPower(-10),
        ExceptionIncorrectSize
    );
}

TEST_F(TestElectroDetails, TestSetCurrentStrength) {
    starter.SetCurrentStrength(5);
    ASSERT_EQ(starter.GetCurrentStrength(), 5);
}

TEST_F(TestElectroDetails, TestSetIncorrectCurrrentStrength) {
    ASSERT_THROW(
        starter.SetCurrentStrength(-10),
        ExceptionIncorrectSize
    );
}

TEST_F(TestElectroDetails, TestSetResistance) {
    starter.SetResistance(5);
    ASSERT_EQ(starter.GetResistance(), 5);
}

TEST_F(TestElectroDetails, TestSetIncorrectResistance) {
    ASSERT_THROW(
        starter.SetResistance(-10),
        ExceptionIncorrectSize
    );
}

TEST_F(TestElectroDetails, TestSetPositiveTemperature) {
    starter.SetTemperature(5);
    ASSERT_EQ(starter.GetTemperature(), 5);
}

TEST_F(TestElectroDetails, TestSetNegativeTemperature) {
    starter.SetTemperature(-5);
    ASSERT_EQ(starter.GetTemperature(), -5);
}

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

TEST_F(TestElectroDetails, TestNormTemperatureInStarter) {
    ASSERT_TRUE(starter.CheckIsTemperatureInNorm());
}

TEST_F(TestElectroDetails, TestNormTemperatureInStarter2) {
    starter.SetTemperature(-100);
    ASSERT_FALSE(starter.CheckIsTemperatureInNorm());
}

TEST_F(TestElectroDetails, TestNormTemperatureInStarter3) {
    starter.SetTemperature(200);
    ASSERT_FALSE(starter.CheckIsTemperatureInNorm());
}

TEST_F(TestElectroDetails, TestNormTemperatureInBattery) {
    ASSERT_TRUE(battery.CheckIsTemperatureInNorm());
}

TEST_F(TestElectroDetails, TestNormTemperatureInBattery2) {
    battery.SetTemperature(-100);
    ASSERT_FALSE(battery.CheckIsTemperatureInNorm());
}

TEST_F(TestElectroDetails, TestNormTemperatureInBattery3) {
    battery.SetTemperature(200);
    ASSERT_FALSE(battery.CheckIsTemperatureInNorm());
}
