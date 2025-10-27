#include "../Engine/piston.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

TEST(TestPiston, TestSetAllParams) {
    auto piston = Piston();
    piston.SetAllParameters(2, 3, 4, 5, 6);
}

TEST(TestPiston, TestSetAllParamsNegative) {
    auto piston = Piston();
    ASSERT_THROW(
        piston.SetAllParameters(-2,3,4,5,6),
        ExceptionIncorrectSize
    );
}

TEST(TestPiston, TestGetWeight) {
    auto piston = Piston(2, 3, 4, 5, 6);
    ASSERT_EQ(piston.GetWeight(), 6);
}

TEST(TestPiston, TestWorkPiston) {
    auto piston = Piston(2, 3, 4, 5, 6);
    ASSERT_TRUE(piston.CheckIsPistonInWorkingCondition());
}

TEST(TestPiston, PistonDescription) {
    auto piston = Piston();
    EXPECT_EQ(piston.GetInfoAboutPart(), "This detail name is piston");
}

TEST(TestPiston, TestGetCompressionHeight) {
    auto piston = Piston(2, 3, 4, 5, 6);
    ASSERT_EQ(piston.GetCompressionHeight(), 4);
}

TEST(TestPiston, TestSetAndGetManufacturer) {
    auto piston = Piston();
    piston.SetManufacturer("Bosch");
    ASSERT_EQ(piston.GetManufacturer(), "Bosch");
}

TEST(TestPiston, TestSetAndGetPistonType) {
    auto piston = Piston();
    piston.SetPistonType("Flat");
    ASSERT_EQ(piston.GetPistonType(), "Flat");
}

TEST(TestPiston, TestSetAndGetPinDiameter) {
    auto piston = Piston();
    piston.SetPinDiameter(20);
    ASSERT_EQ(piston.GetPinDiameter(), 20);
}

TEST(TestPiston, TestSetNegativePinDiameter) {
    auto piston = Piston();
    ASSERT_THROW(
        piston.SetPinDiameter(-5),
        ExceptionRuntimeError
    );
}

TEST(TestPiston, TestSetAndGetOperatingTemperature) {
    auto piston = Piston();
    piston.SetOperatingTemperature(200);
    ASSERT_EQ(piston.GetOperatingTemperature(), 200);
}

TEST(TestPiston, TestSetAndGetMaxPressure) {
    auto piston = Piston();
    piston.SetMaxPressure(100);
    ASSERT_EQ(piston.GetMaxPressure(), 100);
}

TEST(TestPiston, TestSetNegativeMaxPressure) {
    auto piston = Piston();
    ASSERT_THROW(
        piston.SetMaxPressure(-10),
        ExceptionRuntimeError
    );
}

TEST(TestPiston, TestSetAndGetCompressionRatio) {
    auto piston = Piston();
    piston.SetCompressionRatio(10.5);
    ASSERT_DOUBLE_EQ(piston.GetCompressionRatio(), 10.5);
}

TEST(TestPiston, TestSetNegativeCompressionRatio) {
    auto piston = Piston();
    ASSERT_THROW(
        piston.SetCompressionRatio(-2.5),
        ExceptionRuntimeError
    );
}

TEST(TestPiston, TestSetAndGetOilGroovesCount) {
    auto piston = Piston();
    piston.SetOilGroovesCount(3);
    ASSERT_EQ(piston.GetOilGroovesCount(), 3);
}

TEST(TestPiston, TestSetNegativeOilGroovesCount) {
    auto piston = Piston();
    ASSERT_THROW(
        piston.SetOilGroovesCount(-1),
        ExceptionRuntimeError
    );
}

TEST(TestPiston, TestSetAndGetHasThermalCoating) {
    auto piston = Piston();
    piston.SetHasThermalCoating(true);
    ASSERT_TRUE(piston.IsThermalCoating());
}

TEST(TestPiston, TestSetAndGetLifespan) {
    auto piston = Piston();
    piston.SetLifespan(5000);
    ASSERT_EQ(piston.GetLifespan(), 5000);
}

TEST(TestPiston, TestSetNegativeLifespan) {
    auto piston = Piston();
    ASSERT_THROW(
        piston.SetLifespan(-100),
        ExceptionRuntimeError
    );
}

TEST(TestPiston, TestSetAndGetSpeed) {
    auto piston = Piston();
    piston.SetSpeed(15);
    ASSERT_EQ(piston.GetSpeed(), 15);
}

TEST(TestPiston, TestSetNegativeSpeed) {
    auto piston = Piston();
    ASSERT_THROW(
        piston.SetSpeed(-5),
        ExceptionRuntimeError
    );
}
