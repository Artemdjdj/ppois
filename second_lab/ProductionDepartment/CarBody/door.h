/*! \file door.h
 *  \brief Заголовочный файл с определением классов дверей
 *  \details Классы для упрощения работы
 */

#ifndef INCLUDE_DOOR_H
#define INCLUDE_DOOR_H
#include<string>
#include <iostream>
#include "../include/basic_params.h"
#include "../CarPart/car_part.h"

/*! \class SideMirror
 *  \brief Класс для определения боковых зеркал
 *  \details Класс предоставляет возможность получения и изменения информации о боковых зеркалах
 */
class SideMirror: public CarPart, public BasicParams, public Color {
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string get_info_about_part() const override {
        return"This class describes the side mirror on the front doors.";
    }

    /*! \brief Параметризованный конструктор
    *  \param height Начальная длина, базовое значение 0
    *  \param width Начальный ширина, базовое значение 0
    *  \param color Начальный цвет, базовое цвет black
    */
    SideMirror(int height =0, int width =0, std::string color="black");

    /*! \brief Деструктор */
    ~SideMirror();
};

/*! \class BackDoo
 *  \brief Класс для определения шаблона задних дверей
 *  \details Класс предоставляет возможность получения и изменения базовых параметров задних дверей
 */
class BackDoor:public CarPart, public BasicParams {
public:

    std::string get_info_about_part() const override {
        return"This class describes the backdoor door";
    }

    /*! \brief Параметризованный конструктор
    *  \param height Начальная длина
    *  \param width Начальный ширина
    */
    BackDoor(int height, int width);

    /*! \brief Деструктор */
    ~BackDoor();
};

/*! \class FrontDoor
 *  \brief Класс для определения базовых параметров передних дверей
 *  \details Класс предоставляет возможность получения и изменения базовых параметров передних дверей
 */
class FrontDoor : public BackDoor {
private:
    bool is_lock = false;/*!< Закрыта ли дверь */;
    SideMirror mirror;/*!< Боковое зеркало */;
public:

    std::string get_info_about_part() const override {
        return"This class describes the front door";
    }

    /*! \brief Параметризованный конструктор
    *  \param height_door Начальная длина, 0
    *  \param width_door Начальный ширина, 0
    *  \param height_mirror Начальная длина бокового окна, 0
    *  \param width_mirror Начальная ширина бокового окна, 0
    *  \param is_lock Закрыта ли, false
    *  \param color Начальный цвет, black
    */
    FrontDoor(
    int height_door = 0,
    int width_door = 0,
    int height_mirror = 0,
    int width_mirror = 0,
    bool is_lock = false,
    std::string color = "black"
);

    /*! \brief Функция открывает дверь*/
    void open_door();

    /*! \brief Функция закрывает дверь*/
    void close_door();

    /*! \brief Функция проверяет открыта ли дверь
    *  \return true если открыта, false в противном случае
    */
    bool get_lock();

    /*! \brief Функция получает цвет в переменную
    *  \param result_color цвет
    */
    void get_color_of_mirror(std::string& result_color);
};

#endif //INCLUDE_DOOR_H
