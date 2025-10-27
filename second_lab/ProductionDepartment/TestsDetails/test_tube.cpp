#include "../Engine/tube.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

TEST(TestTube, TestTubeGetHeight) {
    const auto tube = Tube(10, 10);
    ASSERT_EQ(tube.GetHeight(), 10);
}

TEST(TestTube, TestTubeSetHeight) {
    auto tube = Tube();
    tube.SetHeight(120);
    ASSERT_EQ(tube.GetHeight(), 120);
}

TEST(TestTube, TestTubeSetHeightNegative) {
    auto tube = Tube();
    ASSERT_THROW(
        tube.SetHeight(-120),
        ExceptionIncorrectSize
    );
    ASSERT_EQ(tube.GetHeight(), 0);
}

TEST(TestTube, TestTubeSetRadiusNegative) {
    auto tube = Tube();
    ASSERT_THROW(
        tube.SetRadius(-120),
        ExceptionIncorrectSize
    );
    ASSERT_EQ(tube.GetRadius(), 0);
}

TEST(TestTube, TestTubeSetRadius) {
    auto tube = Tube();
    tube.SetRadius(12);
    ASSERT_EQ(tube.GetRadius(), 12);
}

TEST(TestTube, TubeDescription) {
    Tube tube = Tube();
    EXPECT_EQ(tube.GetInfoAboutPart(), "This detail name is tube");
}

TEST(TestTube, TestSetAndGetManufacturer) {
    auto tube = Tube();
    tube.SetManufacturer("Firma");
    ASSERT_EQ(tube.GetManufacturer(), "Firma");
}

TEST(TestTube, TestSetEmptyManufacturer) {
    auto tube = Tube();
    tube.SetManufacturer("");
    ASSERT_TRUE(tube.GetManufacturer().empty());
}

TEST(TestTube, TestSetAndGetWeight) {
    auto tube = Tube();
    tube.SetWeight(500);
    ASSERT_EQ(tube.GetWeight(), 500);
}

TEST(TestTube, TestSetNegativeWeight) {
    auto tube = Tube();
    ASSERT_THROW(
        tube.SetWeight(-100),
        ExceptionRuntimeError
    );
    ASSERT_EQ(tube.GetWeight(), 0);
}

TEST(TestTube, TestSetAndGetMaxPressure) {
    auto tube = Tube();
    tube.SetMaxPressure(100);
    ASSERT_EQ(tube.GetMaxPressure(), 100);
}

TEST(TestTube, TestSetNegativeMaxPressure) {
    auto tube = Tube();
    ASSERT_THROW(
        tube.SetMaxPressure(-50),
        ExceptionRuntimeError
    );
    ASSERT_EQ(tube.GetMaxPressure(), 0);
}

TEST(TestTube, TestSetAndGetFlexibility) {
    auto tube = Tube();
    tube.SetFlexibility(true);
    ASSERT_TRUE(tube.IsFlexible());
    tube.SetFlexibility(false);
    ASSERT_FALSE(tube.IsFlexible());
}

TEST(TestTube, TestSetAndGetOperatingTemperature) {
    auto tube = Tube();
    tube.SetOperatingTemperature(80);
    ASSERT_EQ(tube.GetOperatingTemperature(), 80);
}

TEST(TestTube, TestSetNegativeOperatingTemperature) {
    auto tube = Tube();
    tube.SetOperatingTemperature(-20);
    ASSERT_EQ(tube.GetOperatingTemperature(), -20);
}

TEST(TestTube, TestSetAndGetLifespan) {
    auto tube = Tube();
    tube.SetLifespan(10000);
    ASSERT_EQ(tube.GetLifespan(), 10000);
}

TEST(TestTube, TestSetNegativeLifespan) {
    auto tube = Tube();
    ASSERT_THROW(
        tube.SetLifespan(-1000),
        ExceptionRuntimeError
    );
    ASSERT_EQ(tube.GetLifespan(), 0);
}

TEST(TestTube, TestSetAndGetWallThickness) {
    auto tube = Tube();
    tube.SetWallThickness(5);
    ASSERT_EQ(tube.GetWallThickness(), 5);
}

TEST(TestTube, TestSetNegativeWallThickness) {
    auto tube = Tube();
    ASSERT_THROW(
        tube.SetWallThickness(-2),
        ExceptionRuntimeError
    );
    ASSERT_EQ(tube.GetWallThickness(), 0);
}
