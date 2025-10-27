#include <gtest/gtest.h>
#include "../SocialMedia/place_of_study.h"

class TestPlaceStudy : public ::testing::Test {
public:
    University university;
    School school;
};

TEST_F(TestPlaceStudy, UniversitySetCountry) {
    university.SetCountry("Belarus");
    EXPECT_EQ(university.GetCountry(), "Belarus");
}

TEST_F(TestPlaceStudy, UniversitySetCity) {
    university.SetCity("Minsk");
    EXPECT_EQ(university.GetCity(), "Minsk");
}

TEST_F(TestPlaceStudy, UniversitySetStartYear) {
    university.SetStartYear(2024);
    EXPECT_EQ(university.GetStartYear(), 2024);
}

TEST_F(TestPlaceStudy, UniversitySetEndYear) {
    university.SetEndYear(2028);
    EXPECT_EQ(university.GetEndYear(), 2028);
}

TEST_F(TestPlaceStudy, UniversitySetYearCreation) {
    university.SetYearCreation(1964);
    EXPECT_EQ(university.GetYearOfCreation(), 1964);
}


TEST_F(TestPlaceStudy, UniversitySetInfo) {
    university.SetInfo("info");
    EXPECT_EQ(university.GetInfo(), "info");
}

TEST_F(TestPlaceStudy, UniversitySetName) {
    university.SetName("BSUIR");
    EXPECT_EQ(university.GetName(), "BSUIR");
}

TEST_F(TestPlaceStudy, UniversitySetFaculty) {
    university.SetFaculty("FITU");
    EXPECT_EQ(university.GetFaculty(), "FITU");
}

TEST_F(TestPlaceStudy, UniversitySetSpeciality) {
    university.SetSpeciality("artificial intelligence");
    EXPECT_EQ(university.GetSpeciality(), "artificial intelligence");
}

TEST_F(TestPlaceStudy, UniversitySetGroup) {
    university.SetGroup("421702");
    EXPECT_EQ(university.GetGroup(), "421702");
}

TEST_F(TestPlaceStudy, SchoolSetCountry) {
    school.SetCountry("Belarus");
    EXPECT_EQ(school.GetCountry(), "Belarus");
}

TEST_F(TestPlaceStudy, SchoolSetCity) {
    school.SetCity("Soligorsk");
    EXPECT_EQ(school.GetCity(), "Soligorsk");
}

TEST_F(TestPlaceStudy, SchoolSetStartYear) {
    school.SetStartYear(2020);
    EXPECT_EQ(school.GetStartYear(), 2020);
}

TEST_F(TestPlaceStudy, SchoolSetEndYear) {
    school.SetEndYear(2024);
    EXPECT_EQ(school.GetEndYear(), 2024);
}

TEST_F(TestPlaceStudy, SchoolSetYearCreation) {
    school.SetYearCreation(1990);
    EXPECT_EQ(school.GetYearOfCreation(), 1990);
}

TEST_F(TestPlaceStudy, SchoolSetInfo) {
    school.SetInfo("Test info");
    EXPECT_EQ(school.GetInfo(), "Test info");
}

TEST_F(TestPlaceStudy, SchoolSetNumber) {
    school.SetNumber(42);
    EXPECT_EQ(school.GetNumber(), 42);
}
