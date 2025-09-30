#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#include <string>
const std::string main_log_file = "../Logs/main_log.txt";

void LogFile(const char *msg, const std::string &file_name);

void ClearFile(const std::string &file_name);
#endif
