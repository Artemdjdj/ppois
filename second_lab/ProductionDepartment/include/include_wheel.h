/*! \file include_wheel.h
 *  \brief Заголовочный файл с определением классов для колеса и руля
 */
#ifndef INCLUDE_WHEEL_H
#define INCLUDE_WHEEL_H
#include <vector>
#include <string>
#include "include_basic_params.h"

/*! \class BaseCircle
 *  \brief Класс для определения базовых параметров круга
 *  \details Класс предоставляет возможность работы с радиусом круга
 */
class BaseCircle {
private:
    int radius{0};/*!< Радиус круга */
public:
    /*! \brief Конструктор по умолчанию */
    BaseCircle() {}

    /*! \brief Параметризованный конструктор
    *  \param radius Начальный радиус
    */
    BaseCircle(int radius);

    /*! \brief Установка радиуса
    *  \param r Новое значение радиуса
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_radius(int r);

    /*! \brief Получение текущего радиуса
    *  \return Радиус
    */
    int get_radius() const;
};

/*! \class BrakeShoe
 *  \brief Класс для определения тормозной колодки
 *  \details Класс предоставляет возможность работы с параметрами тормозной колодки
 */
class BrakeShoe:public BasicParams, public Color {
private:
    std::string type_of_material;/*!< Тип материала */
    void set_material_private(std::string material);
public:
    /*! \brief Конструктор по умолчанию */
    BrakeShoe();

    /*! \brief Параметризованный конструктор
    *  \param height Высота
    *  \param width Ширина
    *  \param material Материал
    *  \param color Цвет
    */
    BrakeShoe(int height, int width, std::string material, std::string color);

    /*! \brief Параметризованный конструктор
    *  \param material Материал
    */
    BrakeShoe(std::string material);

    /*! \brief Установка материала
    *  \param material Новый материал
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_material(std::string material);

    /*! \brief Получение текущего материала
    *  \return Материал
    */
    std::string get_material();
};

/*! \class Wheel
 *  \brief Класс для определения колеса
 *  \details Класс предоставляет возможность работы с параметрами колеса
 */
class Wheel{
private:
    BaseCircle radius;/*!< Радиус колеса */
    BrakeShoe brake_shoe;/*!< Тормозная колодка */
    int count_of_bolts{0};/*!< Количество болтов */
public:
    /*! \brief Конструктор по умолчанию */
    Wheel();

    /*! \brief Параметризованный конструктор
    *  \param radius Радиус
    *  \param height Высота
    *  \param width Ширина
    *  \param material Материал
    *  \param color Цвет
    *  \param count_of_bolts Количество болтов
    */
    Wheel(int radius, int height, int width, std::string material, std::string color, int count_of_bolts);

    /*! \brief Установка количества болтов
    *  \param count_of_bolts Новое количество болтов
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_count_of_bolts(int count_of_bolts);

    /*! \brief Получение количества болтов
    *  \return Количество болтов
    */
    int get_count_of_bolts();

    /*! \brief Получение радиуса
    *  \return Радиус
    */
    int get_radius();

    /*! \brief Установка радиуса
    *  \param radius Новый радиус
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_radius(int radius);

    /*! \brief Установка материала
    *  \param material Новый материал
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_material(std::string material);

    /*! \brief Установка цвета
    *  \param color Новый цвет
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_color(std::string color);

    /*! \brief Установка размера
    *  \param height Новая высота
    *  \param width Новая ширина
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_size(int height, int width);

    /*! \brief Получение типа материала тормозной колодки
    *  \return Тип материала
    */
    std::string get_type_of_material_to_brake_shoe();
};

/*! \class SignalButton
 *  \brief Класс для определения кнопки сигнала
 *  \details Класс предоставляет возможность работы с кнопкой сигнала
 */
class SignalButton{
private:
    BasicParams size;/*!< Размеры кнопки */
    bool is_clicked = false;/*!< Состояние нажатия */
public:
    /*! \brief Конструктор по умолчанию */
    SignalButton();

    /*! \brief Параметризованный конструктор
    *  \param height Высота
    *  \param width Ширина
    *  \param is_clicked Состояние нажатия
    */
    SignalButton(int height, int width, bool is_clicked);

    /*! \brief Нажатие кнопки */
    void clicked_button();

    /*! \brief Получение состояния нажатия
    *  \return Состояние нажатия
    */
    bool get_is_clicked() const;

    /*! \brief Установка размера кнопки
    *  \param height Новая высота
    *  \param width Новая ширина
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_size_for_button(int height, int width);
};

/*! \class SteeringWheel
 *  \brief Класс для определения рулевого колеса
 *  \details Класс предоставляет возможность работы с рулевым колесом
 */
class SteeringWheel{
private:
    BaseCircle radius_of_steering_wheel;/*!< Радиус руля */
    BaseCircle radius_of_center_logo;/*!< Радиус центрального логотипа */
    SignalButton signal_button;/*!< Кнопка сигнала */
public:
    /*! \brief Конструктор по умолчанию */
    SteeringWheel();

    /*! \brief Параметризованный конструктор
    *  \param first_radius Радиус руля
    *  \param second_radius Радиус логотипа
    *  \param height_of_button Высота кнопки
    *  \param width_of_button Ширина кнопки
    *  \param is_clicked Состояние нажатия
    */
    SteeringWheel(int first_radius, int second_radius, int height_of_button, int width_of_button, bool is_clicked);

    /*! \brief Установка радиуса руля
    *  \param radius_of_steering_wheel Новый радиус
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_radius_of_steering_wheel(int radius_of_steering_wheel);

    /*! \brief Установка радиуса логотипа
    *  \param radius_of_center_logo Новый радиус
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_radius_of_center_logo(int radius_of_center_logo);

    /*! \brief Нажатие кнопки сигнала
    *  \return true если нажатие прошло успешно, false в противном случае
    */
    bool clicked_button_to_make_noise();

    /*! \brief Получение состояния нажатия
    *  \return Состояние нажатия
    */
    bool get_is_clicked() const;

    /*! \brief Установка размера кнопки
    *  \param height_of_button Новая высота
    *  \param width_of_button Новая ширина
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_size_for_button(int height_of_button, int width_of_button);
};
#endif //INCLUDE_WHEEL_H