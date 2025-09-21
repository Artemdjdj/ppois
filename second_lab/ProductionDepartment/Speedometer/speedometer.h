/*! \file speedometer.h
 *  \brief Заголовочный файл с определением классов для спидометра
 */
#ifndef INCLUDE_SPEEDOMETER_H
#define INCLUDE_SPEEDOMETER_H
#include "../CarPart/car_part.h"

/*! \class DefaultSpeedometer
 *  \brief Базовый абстрактный класс для определения спидометра
 *  \details Класс предоставляет базовый интерфейс для работы со спидометром
 */
class DefaultSpeedometer:public CarPart{
protected:
    int speed{0};/*!< Текущая скорость */
    int mileage{0};/*!< Текущий пробег */
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string get_info_about_part() const override {
        return"This class describes Default speedometer";
    }

    /*! \brief Конструктор по умолчанию */
    DefaultSpeedometer();

    /*! \brief Параметризованный конструктор
    *  \param speed Начальная скорость
    *  \param mileage Начальный пробег
    */
    DefaultSpeedometer(int speed,int mileage);

    /*! \brief Виртуальная функция установки скорости
    *  \param speed Новое значение скорости
    *  \return true если установка прошла успешно, false в противном случае
    */
    virtual bool set_speed(int speed) = 0;

    /*! \brief Виртуальная функция установки пробега
    *  \param mileage Новое значение пробега
    *  \return true если установка прошла успешно, false в противном случае
    */
    virtual bool set_mileage(int mileage) =0;

    /*! \brief Получение текущей скорости
    *  \return Скорость
    */
    int get_speed() const;

    /*! \brief Получение текущего пробега
    *  \return Пробег
    */
    int get_mileage() const;

    /*! \brief Виртуальный деструктор */
    virtual ~DefaultSpeedometer()= default;
};

/*! \class SpeedometerInKilometers
 *  \brief Класс для определения спидометра с измерениями в километрах
 *  \details Класс предоставляет возможность работы со спидометром в километрах
 */
class SpeedometerInKilometers: public DefaultSpeedometer{
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string get_info_about_part() const override {
        return"This class describes speedometer in kilometers";
    }

    /*! \brief Конструктор по умолчанию */
    SpeedometerInKilometers();

    /*! \brief Параметризованный конструктор
    *  \param speed Начальная скорость в км/ч
    *  \param mileage Начальный пробег в км
    */
    SpeedometerInKilometers(int speed,int mileage);

    /*! \brief Установка скорости в километрах в час
    *  \param speed Новое значение скорости
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_speed(int speed) override;

    /*! \brief Установка пробега в километрах
    *  \param mileage Новое значение пробега
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_mileage(int mileage) override;
};

/*! \class SpeedometerInMiles
 *  \brief Класс для определения спидометра с измерениями в милях
 *  \details Класс предоставляет возможность работы со спидометром в милях
 */
class SpeedometerInMiles: public DefaultSpeedometer{
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string get_info_about_part() const override {
        return"This class describes speedometer in miles";
    }

    /*! \brief Параметризованный конструктор
    *  \param speed Начальная скорость в милях/ч
    *  \param mileage Начальный пробег в милях
    */
    SpeedometerInMiles(int speed, int mileage);

    /*! \brief Конструктор по умолчанию */
    SpeedometerInMiles();

    /*! \brief Установка скорости в милях в час
    *  \param speed Новое значение скорости
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_speed(int speed) override;

    /*! \brief Установка пробега в милях
    *  \param mileage Новое значение пробега
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_mileage(int mileage) override;
};
#endif //INCLUDE_SPEEDOMETER_H