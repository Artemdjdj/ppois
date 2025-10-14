#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#define NUMBER_OF_VERSION "1.0.0"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#include <string>
#include <unordered_set>
#include <vector>
#include <../User/user.h>
#include "../SocialMedia/reaction.h"
#include "../SocialMedia/hash_tag.h"
#include "../SocialMedia/poll.h"
#include <stdexcept>

#include "../Exceptions/exceptions.h"

const std::string main_log_file = "../Logs/main_log.txt";

class BaseInfo {
protected:
    BaseInfo() = default;

public:
    virtual ~BaseInfo() = default;

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
    static void AddElementToVector(std::vector<T> &, const T &) = delete;

    static void AddElementToVector(std::vector<std::string> &vec, const std::string &element) {
        if (element.empty()) {
            throw std::invalid_argument("Invalid input!");
        }
        vec.push_back(element);
    }

    static void AddElementToVector(std::vector<Reaction *> &vec, Reaction *reaction) {
        vec.push_back(reaction);
    }

    static void AddElementToVector(std::vector<HashTag *> &vec, HashTag *hash_tag) {
        vec.push_back(hash_tag);
    }

    static void AddElementToVector(std::vector<Poll *> &vec, Poll *poll) {
        vec.push_back(poll);
    }

    static void AddElementToVector(std::vector<User *> &vec, User *user) {
        vec.push_back(user);
    }

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

class Menu {
public:
    static void PrintMainMenu();

    static void PrintHelp();

    static void PrintVersion();
};

#endif
