/*! \file season.h
 *  \brief Заголовочный файл с определением класса сезона года
 */
#ifndef SEASON_H
#define SEASON_H
#include <iostream>
#include <string>
#include <vector>
#include "../CarPart/car_part.h"


/*! \class Season
 *  \brief Класс для определения базовых параметров сезона года
 *  \details Класс предоставляет возможность получения и изменения базовых параметров сезона года
 */
class Season {
private:
    std::string season;/*!< Сезон года */;

    /*! \brief Функция проверяет сезон года на корректность
    *  \param color Проверяемый сезон года
    */
    void set_season_private(std::string season);
public:

    /*! \brief Конструктор по умолчанию */
    Season();

    /*! \brief Параметризованный конструктор
    *  \param color Сезон года
	*/
    Season(std::string season);

    /*! \brief Установка сезона длины года
    *  \param color Новый сезон года
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_season(std::string season);

    /*! \brief Получение текущего сезона года
	*  \return Сезон года
	*/
    std::string get_season();
};
#endif //SEASON_H
