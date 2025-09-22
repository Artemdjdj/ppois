/*! \file project_settings.h
 *  \brief Файл настроек
  */
#ifndef PROJECT_SETTINGS_H
#define PROJECT_SETTINGS_H
#define NAME_OF_FILE_LOGS_GENERATE_ID "C:/Users/Redmi/Desktop/ppois/second_lab/Logs/generator_id_log.txt"
#include <cmath>
#include <string>
constexpr int length_of_id = 8;
constexpr int max_count_of_attempts = pow(10, 8);

int CheckFileLog(std::string file_name);
#endif
