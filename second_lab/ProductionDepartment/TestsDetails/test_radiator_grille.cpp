#include "../CarBody/radiator_grille.h"
#include <gtest/gtest.h>
#include "../../Exceptions/exceptions.h"

class TestRadiatorGrille : public ::testing::Test {
public:
    void SetUp() override {
        grille = RadiatorGrille();
        grille.SetCountOfHoles(210);
        grille.SetDiameter(7);
        grille.SetColor("black");
        grille.SetYearOfProducing(2023);
        grille.SetLedLighting(true);
        grille.SetStoneGuard(false);
        grille.MakeReinforced(true);
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
    ASSERT_EQ(grille.GetInfoAboutPart(), "This detail name is radiator grille");
}

TEST_F(TestRadiatorGrille, TestSetColor) {
    grille.SetColor("red");
    ASSERT_EQ(grille.GetColor(), "red");
}

TEST_F(TestRadiatorGrille, TestSetEmptyColor) {
    ASSERT_THROW(
        grille.SetColor(""),
        ExceptionIncorrectColor
    );
}

TEST_F(TestRadiatorGrille, TestSetYearOfProducing) {
    grille.SetYearOfProducing(2024);
    ASSERT_EQ(grille.GetYearOfProducing(), 2024);
}

TEST_F(TestRadiatorGrille, TestSetInvalidYearOfProducing) {
    ASSERT_THROW(
        grille.SetYearOfProducing(1800),
        ExceptionRuntimeError
    );
}

TEST_F(TestRadiatorGrille, TestSetFutureYearOfProducing) {
    ASSERT_THROW(
        grille.SetYearOfProducing(2030),
        ExceptionRuntimeError
    );
}

TEST_F(TestRadiatorGrille, TestSetLedLighting) {
    grille.SetLedLighting(false);
    ASSERT_FALSE(grille.HasLedLighting());
    grille.SetLedLighting(true);
    ASSERT_TRUE(grille.HasLedLighting());
}

TEST_F(TestRadiatorGrille, TestSetStoneGuard) {
    grille.SetStoneGuard(true);
    ASSERT_TRUE(grille.HasStoneGuard());
    grille.SetStoneGuard(false);
    ASSERT_FALSE(grille.HasStoneGuard());
}

TEST_F(TestRadiatorGrille, TestMakeReinforced) {
    grille.MakeReinforced(false);
    ASSERT_FALSE(grille.IsReinforced());
    grille.MakeReinforced(true);
    ASSERT_TRUE(grille.IsReinforced());
}
