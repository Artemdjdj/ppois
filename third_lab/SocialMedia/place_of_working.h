//
// Created by Redmi on 16.10.2025.
//

#ifndef THIRD_LAB_PLACE_OF_WORKING_H
#define THIRD_LAB_PLACE_OF_WORKING_H
#include <string>
#include <optional>

class PlaceOfWorking {
public:
    PlaceOfWorking() = default;

    PlaceOfWorking(const std::string &name_of_company, const std::string &country, const std::string &city,
                   const std::string &job_title);

    void SetNameOfCompany(const std::string &name_of_company);

    void SetCountry(const std::string &country);

    void SetCity(const std::string &city);

    void SetStartYear(int start_year);

    void SetEndYear(int end_year);

    void SetJobTitle(const std::string &job_title);

    std::string GetNameOfCompany() const;

    std::string GetCountry() const;

    std::string GetCity() const;

    std::optional<int> GetStartYear() const;

    std::optional<int> GetEndYear() const;

    std::string GetJobTitle() const;

private:
    std::string name_of_company_;
    std::string country_;
    std::string city_;
    int start_year_{0};
    int end_year_{0};
    std::string job_title_;
};
#endif //THIRD_LAB_PLACE_OF_WORKING_H
