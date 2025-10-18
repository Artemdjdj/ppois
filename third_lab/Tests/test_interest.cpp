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
    Book book2 = Book();
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

TEST_F(TestInterestAndOther, TestSetTitle) {
    book.SetTitle("Learning algorithms");
    ASSERT_EQ(book.GetTitle(), "Learning algorithms");
}

TEST_F(TestInterestAndOther, TestSetTitleIncorrect) {
    ASSERT_THROW(
        book.SetTitle(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetGenre) {
    book.SetGenre("scientific");
    ASSERT_EQ(book.GetGenre(), "scientific");
}

TEST_F(TestInterestAndOther, TestSetGenreIncorrect) {
    ASSERT_THROW(
        book.SetGenre(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetCountOfPages) {
    book.SetCountOfPages(100);
    ASSERT_EQ(book.GetCountOfPages(), 100);
}

TEST_F(TestInterestAndOther, TestCountOfPagesNullopt) {
    ASSERT_EQ(book.GetCountOfPages(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestSetCountOfPagesIncorrect) {
    ASSERT_THROW(
        book.SetCountOfPages(0),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestInterestAndOther, TestSetCountOfPagesIncorrect2) {
    ASSERT_THROW(
        book.SetCountOfPages(2500000),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestInterestAndOther, TestSetInfo) {
    book.SetInfoAboutAuthors("Pushkin");
    ASSERT_EQ(book.GetInfoAboutAuthors(), "Pushkin");
}

TEST_F(TestInterestAndOther, TestSetInfoIncorrect) {
    ASSERT_THROW(
        book.SetInfoAboutAuthors(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetPublicationYear) {
    book.SetPublicationYear(2000);
    ASSERT_EQ(book.GetPublicationYear(), 2000);
}

TEST_F(TestInterestAndOther, TestPublicationYearNullopt) {
    ASSERT_EQ(book.GetPublicationYear(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestSetPublicationYearIncorrect) {
    ASSERT_THROW(
        book.SetPublicationYear(2026),
        ExceptionIncorrectYear
    );
}

TEST_F(TestInterestAndOther, TestSetReaderAge) {
    book.SetReaderAge(16);
    ASSERT_EQ(book.GetReaderAge(), 16);
}

TEST_F(TestInterestAndOther, TestReaderAgeNullopt) {
    ASSERT_EQ(book2.GetReaderAge(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestReaderAgeIncorrect) {
    ASSERT_THROW(
        book.SetPublicationYear(2026),
        ExceptionIncorrectYear
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

TEST_F(TestInterestAndOther, TestSetTitleSong) {
    song.SetTitle("Hello");
    ASSERT_EQ(song.GetTitle(), "Hello");
}

TEST_F(TestInterestAndOther, TestSetTitleSongIncorrect) {
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

TEST_F(TestInterestAndOther, TestDeleteSongFromAlbum) {
    album.AddSong(song);
    ASSERT_EQ(album.GetAlbum().size(),1);
    album.DeleteSong(0);
    ASSERT_EQ(album.GetAlbum().size(),0);
}

TEST_F(TestInterestAndOther, TestSetTitleFilm) {
    film.SetTitle("Shadow fight");
    ASSERT_EQ(film.GetTitle(), "Shadow fight");
}

TEST_F(TestInterestAndOther, TestSetTitleFilmIncorrect) {
    ASSERT_THROW(
        film.SetTitle(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetDirectorFilm) {
    film.SetDirector("Dmitriy");
    ASSERT_EQ(film.GetDirector(), "Dmitriy");
}

TEST_F(TestInterestAndOther, TestSetDirectorFilmIncorrect) {
    ASSERT_THROW(
        film.SetDirector(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetGenreFilm) {
    film.SetGenre("fantasy");
    ASSERT_EQ(film.GetGenre(), "fantasy");
}

TEST_F(TestInterestAndOther, TestSetGenreFilmIncorrect) {
    ASSERT_THROW(
        film.SetGenre(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetPlotFilm) {
    film.SetPlot("some info");
    ASSERT_EQ(film.GetPlot(), "some info");
}

TEST_F(TestInterestAndOther, TestSetPlotFilmIncorrect) {
    ASSERT_THROW(
        film.SetPlot(""),
        std::invalid_argument
    );
}

TEST_F(TestInterestAndOther, TestSetTimeFilm) {
    film.SetTime(2.0);
    ASSERT_EQ(film.GetTime(), 2.0);
}

TEST_F(TestInterestAndOther, TestTimeNulloptFilm) {
    ASSERT_EQ(film.GetTime(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestSetTimeFilmIncorrect) {
    ASSERT_THROW(
        film.SetTime(0),
        ExceptionIncorrectTime
    );
}

TEST_F(TestInterestAndOther, TestSetTimeFilmIncorrect2) {
    ASSERT_THROW(
        film.SetTime(20000),
        ExceptionIncorrectTime
    );
}

TEST_F(TestInterestAndOther, TestSetRatingFilm) {
    film.SetRating(4);
    ASSERT_EQ(film.GetRating(), 4);
    ASSERT_FALSE(film.CheckIsFilmGood());
}

TEST_F(TestInterestAndOther, TestRatingNulloptFilm) {
    ASSERT_EQ(film.GetRating(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestSetRatingFilmIncorrect) {
    ASSERT_THROW(
        film.SetRating(0),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestInterestAndOther, TestSetRatingFilmIncorrect2) {
    ASSERT_THROW(
        film.SetRating(11),
        ExceptionIncorrectNumber
    );
}

TEST_F(TestInterestAndOther, TestSetOrTakeOscar) {
    film.SetOscar();
    ASSERT_TRUE(film.GetIsOscar());
    film.TakeOscar();
    ASSERT_FALSE(film.GetIsOscar());
}

TEST_F(TestInterestAndOther, TestUseComputerGraphic) {
    film.UseComputerGraphic();
    ASSERT_TRUE(film.GetIsComputerGraphic());
    film.DoNotUseComputerGraphic();
    ASSERT_FALSE(film.GetIsComputerGraphic());
}

TEST_F(TestInterestAndOther, TestYearFilm) {
    film.SetYear(2006);
    ASSERT_EQ(film.GetYear(), 2006);
}

TEST_F(TestInterestAndOther, TestYearFilmNullopt) {
    ASSERT_EQ(film.GetYear(), std::nullopt);
}

TEST_F(TestInterestAndOther, TestYearFilmIncorrect) {
    ASSERT_THROW(
        film.SetYear(0),
        ExceptionIncorrectYear
    );
}

TEST_F(TestInterestAndOther, TestSetYearFilmIncorrect2) {
    ASSERT_THROW(
        film.SetYear(2026),
        ExceptionIncorrectYear
    );
}

TEST_F(TestInterestAndOther, TestAddActor) {
    film.AddActor("Petrov");
    ASSERT_EQ(film.GetActors().size(), 1);
    film.DeleteActor(0);
    ASSERT_EQ(film.GetActors().size(), 0);
    ASSERT_THROW(
        film.AddActor(""),
        std::invalid_argument
    );
}