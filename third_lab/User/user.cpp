#include "user.h"
#include <string>
#include "../Utils/project_utils.h"
#include "exceptions.h"


User::User(const std::string &username, const std::string &password, const std::string &name) : name_(name) {
    SetUserName(username);
    SetPassword(password);
    CreateProfile();
}

User::User(const User &other) {
    this->username_ = other.username_;
    this->name_ = other.name_;
    this->surname_ = other.surname_;
    this->email_ = other.email_;
    this->phone_number_ = other.phone_number_;
    this->password_ = other.password_;
}

bool User::operator==(const User &other) const {
    return username_ == other.username_ &&
           name_ == other.name_ &&
           surname_ == other.surname_ &&
           email_ == other.email_ &&
           phone_number_ == other.phone_number_;
}

bool User::operator!=(const User &other) const {
    return !(*this == other);
}

void User::SetUserName(const std::string &username) {
    if (ValidatorUsername validator; !validator.Validate(username)) {
        throw ExceptionUserName("Your username is not correct the length should be between 3 and 17 and starts with @");
    }
    this->username_ = username;
}

void User::SetName(const std::string &name) {
    if (ValidatorName validator; !validator.Validate(name)) {
        throw ExceptionName("Your name or surname is not correct the length should be between 3 and 25");
    }
    this->name_ = name;
}

void User::SetSurname(const std::string &surname) {
    if (ValidatorName validator; !validator.Validate(surname)) {
        throw ExceptionSurName("Your name or surname is not correct the length should be between 3 and 25");
    }
    this->surname_ = surname;
}

void User::SetEmail(const std::string &email) {
    if (ValidatorEmail validator; !validator.Validate(email)) {
        throw ExceptionEmail("Your E-mail address is not valid");
    }
    this->email_ = email;
}

void User::SetPhoneNumber(const std::string &phone_number) {
    if (ValidatorPhoneNumber validator; !validator.Validate(phone_number)) {
        throw ExceptionPhoneNumber("Your phone number is not valid");
    }
    this->phone_number_ = phone_number;
}

void User::SetPassword(const std::string &password) {
    if (ValidatorPassword validator; !validator.Validate(password)) {
        throw ExceptionPassword("Your password is not valid");
    }
    const std::string res_password = password;
    this->password_ = HashPassword::HashInputPassword(res_password);
}

void User::CreateProfile() {
    if (!this->profile_) {
        this->profile_ = std::make_unique<Profile>(this->GetUsername());
    }
}

void User::SetRole(const Role &role) {
    this->role_ = role;
}

std::string User::GetUsername() const {
    return this->username_;
}

std::string User::GetName() const {
    return this->name_;
}

std::string User::GetSurName() const {
    return this->surname_;
}

std::string User::GetEmail() const {
    return this->email_;
}

std::string User::GetPhoneNumber() const {
    return this->phone_number_;
}

Hash User::GetPassword() const {
    return this->password_;
}

std::string User::GetRole() const {
    return this->role_.GetRole();
}

const std::unique_ptr<Profile> &User::GetProfile() const {
    return this->profile_;
}

Profile::Profile(const std::string &username, const std::string &location,
                 const std::string &biography) : username_(username), location_(location), biography_(biography) {
}

void Profile::SetLocation(const std::string &location) {
    this->location_ = location;
}

void Profile::SetBiography(const std::string &biography) {
    this->biography_ = biography;
}

void Profile::SetGender(const bool is_man) {
    this->is_man_ = is_man;
}

void Profile::SetAge(const int age) {
    if (age < MIN_AGE) {
        throw ExceptionIncorrectYear("Age can't be smaller than zero");
    }
    if (age > MAX_LENGTH_OF_LIFE) {
        throw ExceptionIncorrectYear("Age can't be so big");
    }
    this->age_ = age;
}

bool Profile::GetGender() const {
    return this->is_man_;
}

std::string Profile::GetLocation() const {
    return this->location_;
}

std::string Profile::GetBiography() const {
    return this->biography_;
}

int Profile::GetAge() const {
    return this->age_;
}

void Profile::AddUserToBlackList(const std::string &user) {
    this->black_list_.AddUser(user);
}

void Profile::DeleteUserFromBlackList(const std::string &user) {
    this->black_list_.DeleteUser(user);
}

void Profile::DeleteAllFromBlackList() {
    this->black_list_.DeleteAll();
}

std::vector<std::string> Profile::GetBlockedUsersNamesFromBlackList() {
    return this->black_list_.GetBlockedUsersNames();
}

void Profile::AddBook(const Book &book) {
    WorkingWithVector::AddElementToVector(this->books_, book);
}

void Profile::DeleteBook(const int number_of_book) {
    WorkingWithVector::DeleteElementFromVectorByPos(this->books_, number_of_book);
}

void Profile::AddFilm(const Film &film) {
    WorkingWithVector::AddElementToVector(this->films_, film);
}

void Profile::DeleteFilm(const int number_of_film) {
    WorkingWithVector::DeleteElementFromVectorByPos(this->films_, number_of_film);
}

void Profile::AddVideoGame(const VideoGame &video_game) {
    WorkingWithVector::AddElementToVector(this->games_, video_game);
}

void Profile::DeleteVideoGame(const int number_of_game) {
    WorkingWithVector::DeleteElementFromVectorByPos(this->games_, number_of_game);
}

std::vector<Book> Profile::GetAllBooks() const {
    return this->books_;
}

std::vector<Film> Profile::GetAllFilms() const {
    return this->films_;
}

std::vector<VideoGame> Profile::GetAllVideoGames() const {
    return this->games_;
}
