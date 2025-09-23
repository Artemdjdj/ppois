/*! \file project_settings.h
 *  \brief Файл настроек
  */
#ifndef PROJECT_SETTINGS_H
#define PROJECT_SETTINGS_H
#define NAME_OF_FILE_LOGS_GENERATE_ID "C:/Users/Redmi/Desktop/ppois/second_lab/Logs/generator_id_log.txt"
#include <cmath>
#include <string>
constexpr int length_of_id = 8;/*!< Длина id */;
constexpr int max_count_of_attempts = pow(10, 8);/*!< Количество уникальных id */;

/*! \brief Очитска файла логирования, если он существует
	*  \return Число 0 если все прошло успешно, 1 в обратном случае
	*/
int CheckFileLog(std::string file_name);
#endif
