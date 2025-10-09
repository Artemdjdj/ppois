#include "../CarBody/radiator_grille.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestRadiatorGrille : public ::testing::Test {
public:
	void SetUp() override {
		grille = RadiatorGrille();
		grille.SetCountOfHoles(210);
		grille.SetDiameter(7);
	}

	RadiatorGrille grille;
};

TEST_F(TestRadiatorGrille, TestSetCountOfHoles) {
	grille.SetCountOfHoles(10);
	ASSERT_EQ(grille.GetCountOfHoles(), 10);
}

TEST_F(TestRadiatorGrille, TestSetNegativeCountOfHoles) {
	ASSERT_THROW(
		grille.SetCountOfHoles(-10),
		ExceptionIncorrectSize
	);
	ASSERT_EQ(grille.GetCountOfHoles(), 210);
}

TEST_F(TestRadiatorGrille, TestSetDiameter) {
	grille.SetDiameter(11);
	ASSERT_EQ(grille.GetDiameter(), 11);
}

TEST_F(TestRadiatorGrille, TestReabilityOfGrille) {
	ASSERT_TRUE(grille.CheckReliabilityOfGrille());
}

TEST_F(TestRadiatorGrille, TestReabilityOfGrilleNegativeCountOfHoles) {
	grille.SetCountOfHoles(200);
	ASSERT_FALSE(grille.CheckReliabilityOfGrille());
}

TEST_F(TestRadiatorGrille, TestReabilityOfGrilleNegativeDiameter) {
	grille.SetDiameter(10);
	ASSERT_FALSE(grille.CheckReliabilityOfGrille());
}

TEST_F(TestRadiatorGrille, TestSetSize) {
	grille.SetSize(10, 10);
}

TEST_F(TestRadiatorGrille, TestSetIncorrectSize) {
	ASSERT_THROW(
		grille.SetSize(-10,10),
		ExceptionIncorrectSize
	);
}

TEST_F(TestRadiatorGrille, RadiatorGrilleDescription) {
	EXPECT_EQ(grille.GetInfoAboutPart(), "This detail name is radiator grille");
}
