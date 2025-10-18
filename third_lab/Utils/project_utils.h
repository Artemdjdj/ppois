#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#define NUMBER_OF_VERSION "1.0.0"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define MIN_YEAR 1930
#define MAX_YEAR 2025
#define MIN_COUNT_OF_PAGES 6
#define MAX_COUNT_OF_PAGES 22000
#define MIN_READER_YEAR 3
#define MAX_READER_YEAR 18
#define YEAR_OF_FIRST_SONG 1860
#define MAX_LENGTH_OF_SONG 10.0
#define MIN_LENGTH_OF_SONG 0.02
#define MAX_LENGTH_OF_FILM 48.0
#define MIN_LENGTH_OF_FILM 0.017
#define RATING 10
#define FIRST_FILM 1888
#include <string>
#include <unordered_set>
#include <vector>
#include <optional>
#include <../User/user.h>
#include "../Exceptions/exceptions.h"
#include <stdexcept>

const std::string main_log_file = "../Logs/main_log.txt";

class Info {
protected:
    Info() = default;

public:
    virtual ~Info() = default;

    virtual void SetName(const std::string &name);

    virtual void SetInfo(const std::string &info);

    virtual std::string GetName() const;

    virtual std::string GetInfo() const;

protected:
    std::string name_;
    std::string info_;
};

class DefaultProjectSettings {
public:
    static void LogFile(const char *msg, const std::string &file_name);

    static void ClearFile(const std::string &file_name);

    static bool CheckIsStatementInAllowed(const std::string &statement,
                                          const std::unordered_set<std::string> &allowed_values);

    static void ToLower(std::string &str);

    static void SetValueWithAuthor(std::string &property, const std::string &value, const User *user,
                                   const User *user_checked,
                                   const std::string &error_incorrect_author,
                                   const std::string &error_invalid_value);

    static void SetValue(std::string &property, const std::string &value,
                         const std::string &error_invalid_value);


    static std::string GetRealTime();
};

class DefaultWorkingWithVector {
public:
    template<typename T>
    static void AddElementToVector(std::vector<T> & vec, const T & val) {
        vec.push_back(val);
    }

    static void AddElementToVector(std::vector<std::string> &vec, const std::string &element) {
        if (element.empty()) {
            throw std::invalid_argument("Invalid input!");
        }
        vec.push_back(element);
    }
    //
    // static void AddElementToVector(std::vector<Reaction *> &vec, Reaction *reaction) {
    //     vec.push_back(reaction);
    // }
    //
    // static void AddElementToVector(std::vector<HashTag *> &vec, HashTag *hash_tag) {
    //     vec.push_back(hash_tag);
    // }
    //
    // static void AddElementToVector(std::vector<Poll *> &vec, Poll *poll) {
    //     vec.push_back(poll);
    // }
    //
    // static void AddElementToVector(std::vector<User *> &vec, User *user) {
    //     vec.push_back(user);
    // }
    //
    // static void AddElementToVector(std::vector<Song> &vec, const Song &song) {
    //     vec.push_back(song);
    // }

    template<typename T>
    static void DeleteElementFromVectorByPos(std::vector<T> &vec, int pos) {
        if (pos < 0 or pos >= vec.size()) {
            throw ExceptionIncorrectNumber("Incorrect number of del element");
        }
        vec.erase(vec.begin() + pos);
    }

    template<typename T>
    static void RefactorElement(std::vector<T> &vec, const T &value, int pos) {
        if (pos < 0 or pos >= vec.size()) {
            throw ExceptionIncorrectNumber("Incorrect number of del element");
        }
        vec[pos] = value;
    }

    template<typename T>
    static void DeleteAll(std::vector<T> &vec) {
        vec.clear();
    }
};

#endif
