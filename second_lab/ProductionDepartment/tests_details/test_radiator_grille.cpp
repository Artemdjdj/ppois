#include "include_radiator_grille.h"
#include <gtest/gtest.h>

class TestRadiatorGrille : public ::testing::Test {
public:
    void SetUp() {
        grille = RadiatorGrille();
        grille.set_count_of_holes(210);
        grille.set_diameter(7);
    }
    RadiatorGrille grille;
};

TEST_F(TestRadiatorGrille, TestSetCountOfHoles) {
    grille.set_count_of_holes(10);
    ASSERT_EQ(grille.get_count_of_holes(), 10);
}

TEST_F(TestRadiatorGrille, TestSetNegativeCountOfHoles) {
    grille.set_count_of_holes(-10);
    ASSERT_EQ(grille.get_count_of_holes(), 210);
}

TEST_F(TestRadiatorGrille, TestSetDiameter) {
    grille.set_diameter(11);
    ASSERT_EQ(grille.get_diameter(), 11);
}

TEST_F(TestRadiatorGrille, TestReabilityOfGrille) {
    ASSERT_TRUE(grille.check_reliability_of_grille());
}

TEST_F(TestRadiatorGrille, TestReabilityOfGrilleNegativeCountOfHoles) {
    grille.set_count_of_holes(200);
    ASSERT_FALSE(grille.check_reliability_of_grille());
}

TEST_F(TestRadiatorGrille, TestReabilityOfGrilleNegativeDiameter) {
    grille.set_diameter(10);
    ASSERT_FALSE(grille.check_reliability_of_grille());
}