#include "../Engine/gear.h"
#include <gtest/gtest.h>

class TestGear : public testing::Test {
public:
	Triangle triangle = Triangle(7, 8, 9);
	Circle circle = Circle(3);
	Prong prong = Prong(7, 8, 9, 2, 7850);
	Rim rim = Rim(2, 2, 7850);
};

TEST_F(TestGear, SetSides) {
	triangle.SetSides(3, 4, 5);
	ASSERT_EQ(triangle.GetOneOfSides(1), 3);
	ASSERT_EQ(triangle.GetOneOfSides(2), 4);
	ASSERT_EQ(triangle.GetOneOfSides(3), 5);
	ASSERT_EQ(triangle.GetOneOfSides(4), std::nullopt);
}

TEST_F(TestGear, TestCalculateSquareTriangle) {
	triangle.SetSides(3, 4, 5);
	ASSERT_EQ(triangle.GetSquare(), 6);
}

TEST_F(TestGear, TestCalculatePerimeterTriangle) {
	ASSERT_EQ(triangle.GetPerimeter(), 24);
}

TEST_F(TestGear, TestSetRadiusNegative) {
	circle.SetRadius(-3);
	ASSERT_EQ(circle.GetRadius(), 3);
}

TEST_F(TestGear, TestCalculateSquareCircle) {
	ASSERT_EQ(circle.GetSquare(), 28.274333882308138);
}

TEST_F(TestGear, TestCalculatePerimeterCircle) {
	ASSERT_EQ(circle.GetPerimeter(), 18.849555921538759);
}


TEST_F(TestGear, TestSetValueProng) {
	ASSERT_TRUE(prong.SetDataProng(1,2,3,2,8000));
}

TEST_F(TestGear, TestSetValueProngNegative) {
	prong.SetDataProng(-3, 2, 3, 2, 8000);
	ASSERT_EQ(prong.GetOneOfSides(1), 7);
	ASSERT_EQ(prong.GetOneOfSides(2), 8);
}


TEST_F(TestGear, TestWeightProng) {
	ASSERT_EQ(prong.GetWeight(), 0.42127520696096038);
}

TEST_F(TestGear, TestSetValueRim) {
	ASSERT_TRUE(rim.SetDataRim(1,2,8888));
}

TEST_F(TestGear, TestSetValueRimNegative) {
	ASSERT_FALSE(rim.SetDataRim(-3,2,8000));
}

TEST_F(TestGear, TestWeightRim) {
	ASSERT_EQ(rim.GetWeight(), 0.19729201864543899);
}

TEST_F(TestGear,RimDescription) {
	EXPECT_EQ(rim.GetInfoAboutPart(), "This detail name is rim");
}

TEST_F(TestGear,ProngDescription) {
	EXPECT_EQ(prong.GetInfoAboutPart(), "This detail name is prong");
}
