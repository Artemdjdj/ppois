#include "../Engine/intake_manifold.h"
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
	ASSERT_TRUE(intake_manifold_1.SetMainVolume(100));
}

TEST_F(TestIntakeManifold, TestSetMainVolumeNegative) {
	ASSERT_FALSE(intake_manifold_1.SetMainVolume(-100));
}

TEST_F(TestIntakeManifold, TestPlenumVolume) {
	intake_manifold_2.SetPlenumVolume();
	ASSERT_EQ(intake_manifold_2.GetPlenumVolume(), 8);
}

TEST_F(TestIntakeManifold, TestSetRadiusCanal) {
	intake_manifold_2.SetRadiusCanal(66);
	ASSERT_EQ(intake_manifold_2.GetRadiusCanal(), 66);
}

TEST_F(TestIntakeManifold, TestCalculateFunctionNulopt) {
	ASSERT_EQ(intake_manifold_1.CalculateResponseFrequency(0.0), std::nullopt);
}

TEST_F(TestIntakeManifold, TestCalculateFunction) {
	intake_manifold_2.SetPlenumVolume();
	ASSERT_EQ(intake_manifold_2.CalculateResponseFrequency(0.0), 931.26468952500659);
}

TEST_F(TestIntakeManifold,IntakeManifoldDescription) {
	EXPECT_EQ(intake_manifold_1.GetInfoAboutPart(), "This detail name is intake manifold");
}