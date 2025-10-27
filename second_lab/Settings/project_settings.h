/*! \file project_settings.h
* \brief Файл настроек
 */
#ifndef PROJECT_SETTINGS_H
#define PROJECT_SETTINGS_H
#define NAME_OF_FILE_LOGS_GENERATE_ID "C:/Users/Redmi/Desktop/ppois/second_lab/Logs/generator_id_log.txt"
#include <string>
constexpr int kLengthOfId = 8;/*!< Длина id */;
constexpr int kMaxCountOfAttempts = 100000000;/*!< Количество уникальных id */;
constexpr int kFirstCar = 1886; /*!< Год создания первого автомобиля */;
constexpr int kMaxYear = 2025; /*!< Текущий год */;

/*! \brief Очитска файла логирования, если он существует
	* \return Число 0 если все прошло успешно, 1 в обратном случае
	*/
int CheckFileLog(const std::string &file_name);
#endif
