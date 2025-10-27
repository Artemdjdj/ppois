/*! \file settings.h
* \brief Заголовочный файл с определением константных переменных
*/
#ifndef SETTINGS_H
#define SETTINGS_H
#define PATH_TO_FILE "C:/Users/Redmi/Desktop/ppois/second_lab/Logs/production_development.txt"
#include <vector>
const std::vector<std::string> kColors = {"blue", "black", "grey", "green", "red", "orange", "brown"};/*!< Список разрешенных цветов */;
const std::vector<std::string> kTypeOfFuels = {"petrol", "diesel", "gas"};/*!< Список разрешенных видов топлива */;
const std::vector<std::string> kTypeOfMaterialsToBrakeShoe = {"semi-metallic", "organic", "low-metal", "ceramic"};/*!< Список разрешенных материалов для тормозных колодок  */;
const std::vector<std::string> kSeasons = {"winter", "summer"};/*!< Спосок разрешенных пор года  */;
constexpr int kSpeedOfSound = 331;/*!< Скорость звука */;
#endif
