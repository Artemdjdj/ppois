#include "place_of_working.h"
#include "../Utils/project_utils.h"

PlaceOfWorking::PlaceOfWorking(const std::string &name_of_company, const std::string &country, const std::string &city,
                               const std::string &job_title) {
    SetNameOfCompany(name_of_company);
    SetCountry(country);
    SetCity(city);
    SetJobTitle(job_title);
}

void PlaceOfWorking::SetNameOfCompany(const std::string &name_of_company) {
    DefaultProjectSettings::SetValue(this->name_of_company_, name_of_company, "Name of company can't be empty");
}

void PlaceOfWorking::SetCountry(const std::string &country) {
    DefaultProjectSettings::SetValue(this->country_, country, "The country can't be empty");
}

void PlaceOfWorking::SetCity(const std::string &city) {
    DefaultProjectSettings::SetValue(this->city_, city, "The city can't be empty");
}

void PlaceOfWorking::SetStartYear(int start_year) {
    if (start_year < MIN_YEAR or start_year > MAX_YEAR) {
        throw ExceptionIncorrectYear("This year is not allowed");
    }
    this->start_year_ = start_year;
}

void PlaceOfWorking::SetEndYear(int end_year) {
    if (end_year < MIN_YEAR or end_year > MAX_YEAR) {
        throw ExceptionIncorrectYear("This year is not allowed");
    }
    this->end_year_ = end_year;
}

void PlaceOfWorking::SetJobTitle(const std::string &job_title) {
    DefaultProjectSettings::SetValue(this->job_title_, job_title, "Job title can't be empty");
}

std::string PlaceOfWorking::GetNameOfCompany() const {
    return this->name_of_company_;
}

std::string PlaceOfWorking::GetCountry() const {
    return this->country_;
}

std::string PlaceOfWorking::GetCity() const {
    return this->city_;
}

std::optional<int> PlaceOfWorking::GetStartYear() const {
    if (this->start_year_ == 0) {
        return std::nullopt;
    }
    return this->start_year_;
}

std::optional<int> PlaceOfWorking::GetEndYear() const {
    if (this->end_year_ == 0) {
        return std::nullopt;
    }
    return this->end_year_;
}

std::string PlaceOfWorking::GetJobTitle() const {
    return this->job_title_;
}
