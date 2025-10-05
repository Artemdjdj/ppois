#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#define NUMBER_OF_VERSION "1.0.0"
#include <string>
#include <unordered_set>
const std::string main_log_file = "../Logs/main_log.txt";

class DefaultProjectSettings {
public:
	static void LogFile(const char *msg, const std::string &file_name);

	static void ClearFile(const std::string &file_name);

	static bool CheckIsStatementInAllowed(const std::string &statement, std::unordered_set<std::string> allowed_values);

	static void ToLower(std::string &str);

};

class Menu {
public:
	static void PrintMainMenu();

	static void PrintHelp();

	static void PrintVersion();
};

#endif
