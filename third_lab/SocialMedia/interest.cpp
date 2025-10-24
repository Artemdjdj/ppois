#include "interest.h"
#include "../Utils/validator.h"
Interest::Interest(const std::string &name, const std::string &info, const std::string &duration, int level) {
    Info::SetName(name);
    Info::SetInfo(info);
    SetDuration(duration);
    SetLevel(level);
}

void Interest::SetDuration(const std::string &duration) {
    this->duration_ = duration;
}

std::string Interest::GetDuration() {
    return this->duration_;
}

void Interest::SetLevel(const int level) {
    if (ValidatorLevel validator; validator.Validate(level)) {
        throw ExceptionIncorrectLevelOfInterest("Incorrect level of interest");
    }
    this->level_ = level;
}

int Interest::GetLevel() const {
    return this->level_;
}

Book::Book(const std::string &title, const std::string &genre, const int reader_age) {
    SetTitle(title);
    SetGenre(genre);
    SetReaderAge(reader_age);
}

void Book::SetTitle(const std::string &title) {
    DefaultProjectSettings::SetValue(this->title_, title, "The title can't be empty");
}

void Book::SetGenre(const std::string &genre) {
    DefaultProjectSettings::SetValue(this->genre_, genre, "The genre can't be empty");
}

void Book::SetCountOfPages(const int count_of_pages) {
    if (ValidatorCountOfPages validator; validator.Validate(count_of_pages)) {
        throw ExceptionIncorrectNumber("The count of pages is incorrect");
    }
    this->count_of_pages_ = count_of_pages;
}

void Book::SetInfoAboutAuthors(const std::string &base_info) {
    DefaultProjectSettings::SetValue(this->authors_, base_info, "The info about author can't be empty");
}

void Book::SetPublicationYear(const int publication_year) {
    if (ValidatorMaxYear validator; validator.Validate(publication_year)) {
        throw ExceptionIncorrectYear("The book can't be published in this year");
    }
    this->publication_year_ = publication_year;
}

void Book::SetReaderAge(const int reader_age) {
    if (ValidatorReaderAge validator; validator.Validate(reader_age)) {
        throw ExceptionIncorrectYear("The reader age is incorrect!");
    }
    this->reader_age_ = reader_age;
}

std::string Book::GetTitle() const {
    return this->title_;
}

std::string Book::GetGenre() const {
    return this->genre_;
}

std::string Book::GetInfoAboutAuthors() const {
    return this->authors_;
}

std::optional<int> Book::GetCountOfPages() const {
    if (this->count_of_pages_ == 0) {
        return std::nullopt;
    }
    return this->count_of_pages_;
}

std::optional<int> Book::GetPublicationYear() const {
    if (this->publication_year_ == 0) {
        return std::nullopt;
    }
    return this->publication_year_;
}

std::optional<int> Book::GetReaderAge() const {
    if (this->reader_age_ == 0) {
        return std::nullopt;
    }
    return this->reader_age_;
}


Song::Song(const std::vector<std::string> &performers, const std::string &title, const std::string &language,
           const int year,
           const double time) : performers_(performers) {
    SetTitle(title);
    SetLanguage(language);
    SetYear(year);
    SetTime(time);
};

void Song::AddPerformer(const std::string &performer) {
    DefaultWorkingWithVector::AddElementToVector(this->performers_, performer);
}

void Song::DeletePerformer(const int number_of_performer) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->performers_, number_of_performer);
}

void Song::SetTitle(const std::string &title) {
    DefaultProjectSettings::SetValue(this->title_, title, "The title of the song can't be empty");
}

void Song::SetLanguage(const std::string &language) {
    DefaultProjectSettings::SetValue(this->language_, language, "The language of the song can't be empty");
}

void Song::SetYear(const int year) {
    if (ValidatorYearSong validator; validator.Validate(year)) {
        throw ExceptionIncorrectYear("The song can't be made before first song");
    }
    if (ValidatorMaxYear validator; validator.Validate(year)) {
        throw ExceptionIncorrectYear("The song can't be made in this year");
    }
    this->year_ = year;
}

void Song::SetTime(const double time) {
    if (ValidatorLengthOfSong validator; validator.Validate(time)) {
        throw ExceptionIncorrectTime("The song can't has this length, check it please");
    }
    this->time_ = time;
}

std::vector<std::string> Song::GetPerformers() const {
    return this->performers_;
}

std::string Song::GetTitle() const {
    return this->title_;
}

std::string Song::GetLanguage() const {
    return this->language_;
}

std::optional<int> Song::GetYear() const {
    if (this->year_ == 0) {
        return std::nullopt;
    }
    return this->year_;
}

std::optional<double> Song::GetTime() const {
    if (this->time_ == 0) {
        return std::nullopt;
    }
    return this->time_;
}

void Album::AddSong(const Song &song) {
    DefaultWorkingWithVector::AddElementToVector(this->songs_, song);
}

void Album::DeleteSong(const int number_of_song) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->songs_, number_of_song);
}

std::vector<Song> Album::GetAlbum() const {
    return this->songs_;
}

Film::Film(const std::string &title, const std::string &director, const std::string &genre,
           const std::vector<std::string> &actors) : actors_(actors) {
    SetTitle(title);
    SetDirector(director);
    SetGenre(genre);
}

void Film::SetTitle(const std::string &title) {
    DefaultProjectSettings::SetValue(this->title_, title, "The title of film can't be empty");
}

void Film::SetDirector(const std::string &director) {
    DefaultProjectSettings::SetValue(this->director_, director, "The director of film can't be empty");
}

void Film::SetGenre(const std::string &genre) {
    DefaultProjectSettings::SetValue(this->genre_, genre, "The genre of film can't be empty");
}

void Film::SetPlot(const std::string &plot) {
    DefaultProjectSettings::SetValue(this->plot_, plot, "The plot of film can't be empty");
}

void Film::SetTime(const double time) {
    if (ValidatorLengthOfFilm validator; validator.Validate(time)) {
        throw ExceptionIncorrectTime("The length of film can't be such this, try again");
    }
    this->time_ = time;
}

void Film::SetRating(const int rating) {
    if (ValidatorLevel validator; validator.Validate(rating)) {
        throw ExceptionIncorrectNumber("The rating can't be so smaller then zero");
    }
    this->rating_ = rating;
}

void Film::SetOscar() {
    this->is_oscar_ = true;
}

void Film::TakeOscar() {
    this->is_oscar_ = false;
}

void Film::UseComputerGraphic() {
    this->is_computer_graphic_ = true;
}

void Film::DoNotUseComputerGraphic() {
    this->is_computer_graphic_ = false;
}

void Film::SetYear(const int year) {
    if (ValidatorFilmCreation validator; validator.Validate(year)) {
        throw ExceptionIncorrectYear("The year of producing can't be such this, try again");
    }
    this->year_ = year;
}

void Film::AddActor(const std::string &actor) {
    DefaultWorkingWithVector::AddElementToVector(this->actors_, actor);
}

void Film::DeleteActor(int number_of_actor) {
    DefaultWorkingWithVector::DeleteElementFromVectorByPos(this->actors_, number_of_actor);
}

std::string Film::GetTitle() const {
    return this->title_;
}

std::string Film::GetDirector() const {
    return this->director_;
}

std::string Film::GetGenre() const {
    return this->genre_;
}

std::string Film::GetPlot() const {
    return this->plot_;
}

std::optional<double> Film::GetTime() const {
    if (this->time_ == 0) {
        return std::nullopt;
    }
    return this->time_;
}

std::optional<int> Film::GetRating() const {
    if (this->rating_ == 0) {
        return std::nullopt;
    }
    return this->rating_;
}

bool Film::GetIsOscar() const {
    return this->is_oscar_;
}

bool Film::GetIsComputerGraphic() const {
    return this->is_computer_graphic_;
}

std::optional<int> Film::GetYear() const {
    if (this->year_ == 0) {
        return std::nullopt;
    }
    return this->year_;
}

std::vector<std::string> Film::GetActors() const {
    return this->actors_;
}

bool Film::CheckIsFilmGood() const {
    return this->rating_ > 6;
}
