#include "place_of_study.h"

void PlaceStudy::SetCountry(const std::string &country) {
    this->country_ = country;
}

void PlaceStudy::SetCity(const std::string &city) {
    this->city_ = city;
}

void PlaceStudy::SetStartYear(const int start_year) {
    this->start_year_ = start_year;
}

void PlaceStudy::SetEndYear(const int end_year) {
    this->end_year_ = end_year;
}

void PlaceStudy::SetYearCreation(const int year_of_creation) {
    this->year_of_creation_ = year_of_creation;
}

std::string PlaceStudy::GetCountry() const {
    return this->country_;
}

std::string PlaceStudy::GetCity() const {
    return this->city_;
}

int PlaceStudy::GetStartYear() const {
    return this->start_year_;
}

int PlaceStudy::GetEndYear() const {
    return this->end_year_;
}

int PlaceStudy::GetYearOfCreation() const {
    return this->year_of_creation_;
}

void University::SetInfo(const std::string &info) {
    this->info_ = info;
}

std::string University::GetInfo() const {
    return this->info_;
}

void University::SetName(const std::string &name) {
    this->name_ = name;
}

void University::SetFaculty(const std::string &faculty) {
    this->faculty_ = faculty;
}

void University::SetSpeciality(const std::string &speciality) {
    this->speciality_ = speciality;
}

void University::SetGroup(const std::string &group) {
    this->group_ = group;
}

std::string University::GetName() const {
    return this->name_;
}

std::string University::GetFaculty() const {
    return this->faculty_;
}

std::string University::GetSpeciality() const {
    return this->speciality_;
}

std::string University::GetGroup() const {
    return this->group_;
}

void School::SetInfo(const std::string &info) {
    this->info_ = info;
}

std::string School::GetInfo() const {
    return this->info_;
}

void School::SetNumber(const int number) {
    this->number_ = number;
}

int School::GetNumber() const {
    return this->number_;
}
