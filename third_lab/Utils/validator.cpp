#include "validator.h"
#include "project_utils.h"
#include <regex>


bool ValidatorUsername::Validate(const std::string &str) {
    const std::regex rx(R"(^@[a-zA-Z0-9\_\-]{3,17}$)");
    return std::regex_match(str, rx);
}

bool ValidatorName::Validate(const std::string &str) {
    const std::regex rx(R"(^[a-zA-Z]{1,}[a-zA-Z\-]{3,50}\w{1,}$)");
    return std::regex_match(str, rx);
}

bool ValidatorEmail::Validate(const std::string &str) {
    const std::regex rx(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    return std::regex_match(str, rx);
}

bool ValidatorPhoneNumber::Validate(const std::string &str) {
    const std::regex rx(R"(\+375(?:29|25|33)\d{7}|80(?:29|44|25)\d{7})");
    return std::regex_match(str, rx);
}

bool ValidatorPassword::Validate(const std::string &str) {
    const std::regex rx(R"(^[a-zA-Z0-9.-@]{8,25}$)");
    return std::regex_match(str, rx);
}

bool ValidatorHashTag::Validate(const std::string &str) {
    const std::regex rx(R"(^#[a-zA-Z0-9]{3,17}(?:[-][a-zA-Z0-9]{3,10})?$)");
    return std::regex_match(str, rx);
}

bool ValidatorString::Validate(const std::string &str) {
    return str.empty();
}

bool ValidatorLevel::Validate(const int &level) {
    return level < 1 or level > 10;
}

bool ValidatorCountOfPages::Validate(const int &count_of_pages) {
    return count_of_pages < MIN_COUNT_OF_PAGES or count_of_pages > MAX_COUNT_OF_PAGES;
}

bool ValidatorMaxYear::Validate(const int &max_year) {
    return max_year > MAX_YEAR;
}

bool ValidatorReaderAge::Validate(const int &age) {
    return age < MIN_READER_YEAR or age > MAX_READER_YEAR;
}

bool ValidatorYearSong::Validate(const int &year) {
    return year < YEAR_OF_FIRST_SONG;
}

bool ValidatorLengthOfSong::Validate(const double &length) {
    return length < MIN_LENGTH_OF_SONG or length > MAX_LENGTH_OF_SONG;
}

bool ValidatorLengthOfFilm::Validate(const double &length) {
    return length < MIN_LENGTH_OF_FILM or length > MAX_LENGTH_OF_FILM;
}

bool ValidatorFilmCreation::Validate(const int &year) {
    return year < FIRST_FILM or year > MAX_YEAR;
}

bool ValidatorWorkingYear::Validate(const int &year) {
    return year < MIN_YEAR or year > MAX_YEAR;
}
