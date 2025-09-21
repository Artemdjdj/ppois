/*! \file fuel.h
 *  \brief Заголовочный файл с определением класса топлива
 */
#ifndef INCLUDE_FUEL_H
#define INCLUDE_FUEL_H
#include <string>
#include "../Seasons/season.h"
#include "../CarPart/car_part.h"

/*! \class Fuel
 *  \brief Класс для определения топлива
 *  \details Класс предоставляет возможность получения и измененияинформации о топливе
 */
class Fuel {
public:

    /*! \brief Конструктор по умолчанию */
    Fuel();

    /*! \brief Параметризованный конструктор
    *  \param type_of_fuel Тип топлива
    *  \param season Сезон года
    */
    Fuel(std::string type_of_fuel, std::string season);

    /*! \brief Установка топлива
    *  \param type_of_fuel Новое топливо
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool SetTypeOfFuel(std::string type_of_fuel);

    /*! \brief Установка сезона года
    *  \param season Новый сезон
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool SetSeason(std::string season);

    /*! \brief Получение текущего вида топлива
    *  \return Тип топлива
    */
    std::string GetTypeOfFuel();

    /*! \brief Получение текущего сезона года
    *  \return Сезон года
    */
    std::string GetSeason();

private:
    /*! \brief Функция проверяет топливо на корректность
    *  \param type_of_fuel цвет
    */
    void SetTypeOfFuelPrivate(std::string type_of_fuel);

private:
    std::string type_of_fuel_;/*!< Тип топлива */;
    Season season_;/*!< Сезон года */;
};

#endif
