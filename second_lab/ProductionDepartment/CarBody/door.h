/*! \file door.h
* \brief Заголовочный файл с определением классов дверей
* \details Классы для упрощения работы
*/

#ifndef INCLUDE_DOOR_H
#define INCLUDE_DOOR_H
#include<string>
#include <iostream>
#include "../Include/basic_params.h"
#include "../CarPart/car_part.h"

/*! \class SideMirror
* \brief Класс для определения боковых зеркал
* \details Класс предоставляет возможность получения и изменения информации о боковых зеркалах
*/
class SideMirror : public CarPart, public BasicParams {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is side mirror";
    }

    /*! \brief Базовый конструктор
    */
    SideMirror() = default;

    /*! \brief Параметризованный конструктор
    * \param height Начальная длина, базовое значение 0
    * \param width Начальный ширина, базовое значение 0
    *  \param color Начальный цвет, базовое цвет black
    */
    SideMirror(int height, int width, const Color &color);

    /*! \brief Деструктор */
    ~SideMirror() = default;

    /*! \brief Установка цвета
    *  \param color Новый цвет
    */
    void SetColor(const Color &color);

    /*! \brief Получение текущего цвета
    *  \return Цвет
    */
    std::string GetColor() const;

private:
    Color color_;
};

/*! \class BackDoor
* \brief Класс для определения шаблона задних дверей
* \details Класс предоставляет возможность получения и изменения базовых параметров задних дверей
*/
class BackDoor : public CarPart, public BasicParams {
public:
    std::string GetInfoAboutPart() const override {
        return "This detail name is back door";
    }

    /*! \brief Параметризованный конструктор
    * \param height Начальная длина
    * \param width Начальный ширина
    */
    BackDoor(int height, int width);

    /*! \brief Деструктор */
    ~BackDoor() override = default;

};

/*! \class FrontDoor
* \brief Класс для определения базовых параметров передних дверей
* \details Класс предоставляет возможность получения и изменения базовых параметров передних дверей
*/
class FrontDoor : public BackDoor {
public:
    std::string GetInfoAboutPart() const override {
        return "This detail name is front door";
    }

    /*! \brief Параметризованный конструктор
    * \param mirror Боковое зеркало
    * \param height Высота передней двери
    * \param width Ширина задней двери
    * \param is_lock Закрыта ли, false
    */
    FrontDoor(
        int height,
        int width,
        const SideMirror &mirror,
        bool is_lock = false
    );

    /*! \brief Установка зеркала
    * \param mirror Боковое зеркало
    */
    void SetMirror(const SideMirror &mirror);

    /*! \brief Функция открывает дверь*/
    void OpenDoor();

    /*! \brief Функция закрывает дверь*/
    void CloseDoor();

    /*! \brief Функция проверяет открыта ли дверь
    * \return true если открыта, false в противном случае
    */
    bool GetLock() const;

    /*! \brief Функция получает цвет в переменную
    * \return Цвет
    */
    std::string GetColorOfMirror() const;

    /*! \brief Деструктор */
    ~FrontDoor() override = default;

private:
    bool is_lock_ = false;/*!< Закрыта ли дверь */;
    SideMirror mirror_;/*!< Боковое зеркало */;
};

#endif //INCLUDE_DOOR_H
