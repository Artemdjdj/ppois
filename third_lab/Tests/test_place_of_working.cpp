#include <gtest/gtest.h>
#include "../SocialMedia/place_of_working.h"
#include "../Exceptions/exceptions.h"
class TestPlaceOfWorking : public::testing::Test {
public:
    void SetUp() override {
        place_of_working = PlaceOfWorking("Google", "England", "London", "soft-engineer");
    }

    PlaceOfWorking place_of_working;
};

TEST_F(TestPlaceOfWorking, TestSetNameOfCompany) {
    place_of_working.SetNameOfCompany("Yandex");
    ASSERT_EQ(place_of_working.GetNameOfCompany(), "Yandex");
}

TEST_F(TestPlaceOfWorking, TestSetNameOfCompanyIncorrect) {
    ASSERT_THROW(
        place_of_working.SetNameOfCompany(""),
        std::invalid_argument
    );
}

TEST_F(TestPlaceOfWorking, TestSetCountry) {
    place_of_working.SetCountry("Brazil");
    ASSERT_EQ(place_of_working.GetCountry(), "Brazil");
}

TEST_F(TestPlaceOfWorking, TestSetCountryIncorrect) {
    ASSERT_THROW(
        place_of_working.SetCountry(""),
        std::invalid_argument
    );
}

TEST_F(TestPlaceOfWorking, TestSetCity) {
    place_of_working.SetCity("Soligorsk");
    ASSERT_EQ(place_of_working.GetCity(), "Soligorsk");
}

TEST_F(TestPlaceOfWorking, TestSetCityIncorrect) {
    ASSERT_THROW(
        place_of_working.SetCity(""),
        std::invalid_argument
    );
}

TEST_F(TestPlaceOfWorking, TestStartYear) {
    place_of_working.SetStartYear(2006);
    ASSERT_EQ(place_of_working.GetStartYear(), 2006);
}

TEST_F(TestPlaceOfWorking, TestSetStartYearIncorrect) {
    ASSERT_THROW(
        place_of_working.SetStartYear(0),
        ExceptionIncorrectYear
    );
}

TEST_F(TestPlaceOfWorking, TestSetStartYearIncorrect2) {
    ASSERT_THROW(
        place_of_working.SetStartYear(2026),
        ExceptionIncorrectYear
    );
}


TEST_F(TestPlaceOfWorking, TestEndYear) {
    place_of_working.SetStartYear(2000);
    place_of_working.SetEndYear(2006);
    ASSERT_EQ(place_of_working.GetEndYear(), 2006);
}

TEST_F(TestPlaceOfWorking, TestSetEndYearIncorrect) {
    place_of_working.SetStartYear(2000);
    ASSERT_THROW(
        place_of_working.SetEndYear(0),
        ExceptionIncorrectYear
    );
}

TEST_F(TestPlaceOfWorking, TestSetEndYearIncorrect2) {
    place_of_working.SetStartYear(2000);
    ASSERT_THROW(
        place_of_working.SetStartYear(2026),
        ExceptionIncorrectYear
    );
}

TEST_F(TestPlaceOfWorking, TestSetEndYeaLogicError) {
    ASSERT_THROW(
        place_of_working.SetEndYear(2023),
        std::logic_error
    );
}

TEST_F(TestPlaceOfWorking, TestSetEndYearIncorrect3) {
    place_of_working.SetStartYear(2000);
    ASSERT_THROW(
        place_of_working.SetEndYear(1999),
        ExceptionIncorrectYear
    );
}

TEST_F(TestPlaceOfWorking, TestSetJobTitle) {
    place_of_working.SetJobTitle("AI engineer");
    ASSERT_EQ(place_of_working.GetJobTitle(), "AI engineer");
}

TEST_F(TestPlaceOfWorking, TestSetJobTitleIncorrect) {
    ASSERT_THROW(
        place_of_working.SetJobTitle("");,
        std::invalid_argument
    );
}

