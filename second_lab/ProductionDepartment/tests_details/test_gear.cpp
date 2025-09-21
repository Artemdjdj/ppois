#include "../Engine/gear.h"
#include <gtest/gtest.h>

class TestGear: public testing::Test {
public:
    Triangle triangle = Triangle(7,8,9);
    Circle circle = Circle(3);
    Prong prong = Prong(7,8,9,2, 7850);
    Rim rim = Rim(2,2,7850);
};

TEST_F(TestGear, SetSides) {
    triangle.set_sides(3,4,5);
    ASSERT_EQ(triangle.get_one_of_sides(1),3);
    ASSERT_EQ(triangle.get_one_of_sides(2),4);
    ASSERT_EQ(triangle.get_one_of_sides(3),5);
    ASSERT_EQ(triangle.get_one_of_sides(4),std::nullopt);
}

TEST_F(TestGear, TestCalculateSquareTriangle) {
    triangle.set_sides(3,4,5);
    ASSERT_EQ(triangle.get_square(),6);
}

TEST_F(TestGear, TestCalculatePerimeterTriangle) {
    ASSERT_EQ(triangle.get_perimeter(), 24);
}

TEST_F(TestGear, TestSetRadiusNegative) {
    circle.set_radius(-3);
    ASSERT_EQ(circle.get_radius(),3);
}

TEST_F(TestGear, TestCalculateSquareCircle) {
    ASSERT_EQ(circle.get_square(),28.274333882308138);
}

TEST_F(TestGear, TestCalculatePerimeterCircle) {
    ASSERT_EQ(circle.get_perimeter(), 18.849555921538759);
}


TEST_F(TestGear, TestSetValueProng) {
    ASSERT_TRUE(prong.set_data_prong(1,2,3,2,8000));
}

TEST_F(TestGear, TestSetValueProngNegative) {
    prong.set_data_prong(-3,2,3,2,8000);
    ASSERT_EQ(prong.get_one_of_sides(1),7);
    ASSERT_EQ(prong.get_one_of_sides(2),8);
}


TEST_F(TestGear, TestWeightProng) {
    ASSERT_EQ(prong.get_weight(), 0.42127520696096038);
}

TEST_F(TestGear, TestSetValueRim) {
    ASSERT_TRUE(rim.set_data_rim(1,2,8888));
}

TEST_F(TestGear, TestSetValueRimNegative) {
    ASSERT_FALSE(rim.set_data_rim(-3,2,8000));
}

TEST_F(TestGear, TestWeightRim) {
    ASSERT_EQ(rim.get_weight(), 0.19729201864543899);
}