#include <gtest/gtest.h>
#include "../SocialMedia/interest.h"

class TestInterestAndOther : public ::testing::Test {
public:
    void SetUp() override {
        book = Book("Harry Potter", "fantasy", 6);
        song.AddPerformer("Genious2006");
    }
    Interest interest = Interest();
    Book book;
    Song song;
    Album album;
    Film film;
};

TEST_F(TestInterestAndOther, TestSetDuration) {
    interest.SetDuration("football");
    ASSERT_EQ("football", interest.GetDuration());
}

TEST_F(TestInterestAndOther, TestSetDurationEmpty) {
    ASSERT_EQ("", interest.GetDuration());
}

TEST_F(TestInterestAndOther, TestSetLevelLeftBoard) {
    interest.SetLevel(1);
    ASSERT_EQ(1, interest.GetLevel());
}

TEST_F(TestInterestAndOther, TestSetLevelRightBoard) {
    interest.SetLevel(10);
    ASSERT_EQ(10, interest.GetLevel());
}

TEST_F(TestInterestAndOther, TestSetLevelDefaultValue) {
    interest.SetLevel(5);
    ASSERT_EQ(5, interest.GetLevel());
}

TEST_F(TestInterestAndOther, TestSetLevelLeftBoardIncorrect) {
    ASSERT_THROW(
        interest.SetLevel(0),
        ExceptionIncorrectLevelOfInterest
    );
}

TEST_F(TestInterestAndOther, TestSetLevelRightBoardIncorrect) {
    ASSERT_THROW(
        interest.SetLevel(11),
        ExceptionIncorrectLevelOfInterest
    );
}

TEST_F(TestInterestAndOther, TestAddPerformer) {
    song.AddPerformer("Human");
    ASSERT_EQ((std::vector<std::string>{"Genious2006","Human"}),song.GetPerformers());
}

TEST_F(TestInterestAndOther, TestAddPerformerIncorrect) {
    ASSERT_THROW(
        song.AddPerformer(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestDeletePerformer) {
    song.DeletePerformer(0);
    ASSERT_EQ((std::vector<std::string>{}),song.GetPerformers());
}

TEST_F(TestInterestAndOther, TestDeletePerformerIncorrect1) {
    ASSERT_THROW(
        song.DeletePerformer(-1),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestInterestAndOther, TestDeletePerformerIncorrect2) {
    ASSERT_THROW(
        song.DeletePerformer(10),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestInterestAndOther, TestSetTitle) {
    song.SetTitle("Hello");
    ASSERT_EQ(song.GetTitle(), "Hello");
}

TEST_F(TestInterestAndOther, TestSetTitleIncorrect) {
    ASSERT_THROW(
        song.SetTitle(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetLanguage) {
    song.SetLanguage("Russian");
    ASSERT_EQ(song.GetLanguage(), "Russian");
}

TEST_F(TestInterestAndOther, TestSetLanguageIncorrect) {
    ASSERT_THROW(
        song.SetLanguage(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestYear) {
    song.SetYear(2006);
    ASSERT_EQ(song.GetYear(), 2006);
}

TEST_F(TestInterestAndOther, TestYearNullopt) {
    ASSERT_EQ(song.GetYear(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestSetStartYearIncorrect) {
    ASSERT_THROW(
        song.SetYear(0),
        ExceptionIncorrectYear
    );
}

TEST_F(TestInterestAndOther, TestSetStartYearIncorrect2) {
    ASSERT_THROW(
        song.SetYear(2026),
        ExceptionIncorrectYear
    );
}

TEST_F(TestInterestAndOther, TestSetTime) {
    song.SetTime(0.1);
    ASSERT_EQ(song.GetTime(), 0.1);
}

TEST_F(TestInterestAndOther, TestTimeNullopt) {
    ASSERT_EQ(song.GetTime(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestSetTimeIncorrect) {
    ASSERT_THROW(
        song.SetTime(0),
        ExceptionIncorrectTime
    );
}

TEST_F(TestInterestAndOther, TestSetTimeIncorrect2) {
    ASSERT_THROW(
        song.SetTime(20000),
        ExceptionIncorrectTime
    );
}