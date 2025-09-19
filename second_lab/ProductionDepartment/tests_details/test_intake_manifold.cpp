#include "include_intake_manifold.h"
#include <gtest/gtest.h>

class TestIntakeManifold : public ::testing::Test {
    public:
    void SetUp() override {
        intake_manifold_1 = IntakeManifold();
        intake_manifold_2 = IntakeManifold(12, 12, 400, 5);
    }
    IntakeManifold intake_manifold_1;
    IntakeManifold intake_manifold_2;
};

TEST_F(TestIntakeManifold, TestSetMainVolume) {
    ASSERT_TRUE(intake_manifold_1.set_main_volume(100));
}

TEST_F(TestIntakeManifold, TestSetMainVolumeNegative) {
    ASSERT_FALSE(intake_manifold_1.set_main_volume(-100));
}

TEST_F(TestIntakeManifold, TestPlenumVolume) {
    intake_manifold_2.set_plenum_volume();
    ASSERT_EQ(intake_manifold_2.get_plenum_volume(), 8);
}

TEST_F(TestIntakeManifold, TestSetRadiusCanal) {
    intake_manifold_2.set_radius_canal(66);
    ASSERT_EQ(intake_manifold_2.get_radius_canal(), 66);
}

TEST_F(TestIntakeManifold, TestCalculateFunctionNulopt) {
    ASSERT_EQ(intake_manifold_1.calculate_response_frequency(0.0), std::nullopt);
}

TEST_F(TestIntakeManifold, TestCalculateFunction) {
    intake_manifold_2.set_plenum_volume();
    ASSERT_EQ(intake_manifold_2.calculate_response_frequency(0.0), 931.26468952500659);
}

