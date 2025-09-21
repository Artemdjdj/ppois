/*! \file include_fuel.h
 *  \brief Заголовочный файл с определением класса топлива
 */
#ifndef INCLUDE_FUEL_H
#define INCLUDE_FUEL_H
#include <string>
#include "include_season.h"

/*! \class Fuel
 *  \brief Класс для определения топлива
 *  \details Класс предоставляет возможность получения и измененияинформации о топливе
 */
class Fuel {
private:
    std::string type_of_fuel;/*!< Тип топлива */;
    Season season;/*!< Сезон года */;

    /*! \brief Функция проверяет топливо на корректность
    *  \param type_of_fuel цвет
    */
    void set_type_of_fuel_private(std::string type_of_fuel);
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
    bool set_type_of_fuel(std::string type_of_fuel);

    /*! \brief Установка сезона года
    *  \param season Новый сезон
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_season(std::string season);

    /*! \brief Получение текущего вида топлива
    *  \return Тип топлива
    */
    std::string get_type_of_fuel();

    /*! \brief Получение текущего сезона года
    *  \return Сезон года
    */
    std::string get_season();
};

#endif
