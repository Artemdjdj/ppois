#include "project_utils.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include "../Exceptions/exceptions.h"
void Info::SetName(const std::string &name) {
    DefaultProjectSettings::SetValue(this->name_, name,
                                               "You can't set empty name!");
}

void Info::SetInfo(const std::string &info) {
    DefaultProjectSettings::SetValue(this->info_, info,
                                               "You can't set empty info!");
}

std::string Info::GetName() const {
    return this->name_;
}

std::string Info::GetInfo() const {
    return this->info_;
}

void DefaultProjectSettings::LogFile(const char *msg, const std::string &file_name) {
    try {
        std::ofstream file(file_name, std::ios::app);
        file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
        file << std::endl << msg << std::endl;
        file.close();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void DefaultProjectSettings::ClearFile(const std::string &file_name) {
    try {
        std::ofstream file(file_name, std::ios::trunc);
        file.exceptions(std::ofstream::badbit | std::ofstream::failbit);
        file.close();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

bool DefaultProjectSettings::CheckIsStatementInAllowed(const std::string &statement,
                                                       const std::unordered_set<std::string> &allowed_values) {
    return allowed_values.contains(statement);
}

void DefaultProjectSettings::ToLower(std::string &str) {
    std::ranges::transform(str, str.begin(), ::tolower);
}

void DefaultProjectSettings::SetValueWithAuthor(std::string &property, const std::string &value, const std::string &user,
                                                const std::string &user_checked,
                                                const std::string &error_incorrect_author,
                                                const std::string &error_invalid_value) {
    if (user != user_checked) {
        throw ExceptionAccess(error_incorrect_author.c_str());
    }
    if (value.empty()) {
        throw std::invalid_argument(error_invalid_value.c_str());
    }
    property = value;
}

void DefaultProjectSettings::SetValue(std::string &property, const std::string &value,
                                      const std::string &error_invalid_value) {
    if (value.empty()) {
        throw std::invalid_argument(error_invalid_value.c_str());
    }
    property = value;
}

std::string DefaultProjectSettings::GetRealTime() {
    const time_t realtime = time(nullptr);
    const struct tm tm = *localtime(&realtime);
    return std::to_string(tm.tm_hour) + ":" + std::to_string(tm.tm_min);
}
