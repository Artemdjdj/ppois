#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#define NUMBER_OF_VERSION "1.0.0"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#include <string>
#include <unordered_set>
#include <../User/user.h>

const std::string main_log_file = "../Logs/main_log.txt";

class DefaultProjectSettings {
public:
    static void LogFile(const char *msg, const std::string &file_name);

    static void ClearFile(const std::string &file_name);

    static bool CheckIsStatementInAllowed(const std::string &statement,
                                          const std::unordered_set<std::string> &allowed_values);

    static void ToLower(std::string &str);

    static void SetValue(std::string &property, const std::string &value, const User *user, const User *user_checked,
                         const std::string &error_incorrect_author,
                         const std::string &error_invalid_value);

    static std::string GetRealTime();
};

class Menu {
public:
    static void PrintMainMenu();

    static void PrintHelp();

    static void PrintVersion();
};

#endif
