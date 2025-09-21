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
    bool SetSeason(std::string season);

    /*! \brief Получение текущего сезона года
	*  \return Сезон года
	*/
    std::string GetSeason();

private:

	/*! \brief Функция проверяет сезон года на корректность
	*  \param color Проверяемый сезон года
	*/
	void SetSeasonPrivate(std::string season);

private:
	std::string season_;/*!< Сезон года */
};
#endif //SEASON_H
