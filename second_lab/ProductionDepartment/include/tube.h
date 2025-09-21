/*! \file tube.h
 *  \brief Заголовочный файл с определением класса трубки
 *  \details Классы для упрощения работы
 */
#ifndef TUBE_H
#define TUBE_H
#include "include_wheel.h"

/*! \class Tube
 *  \brief Класс для определения базовых параметров трубки
 *  \details Класс предоставляет возможность получения и изменения базовых параметров трубки
 */
class Tube {
private:
    BaseCircle radius;/*!< Радиус трубки */;
    int height{0};/*!<Длина трубки */;
public:
    /*! \brief Конструктор по умолчанию */
    Tube();

    /*! \brief Параметризованный конструктор
    *  \param radius Начальный радиус
	*  \param height Начальная длина
	*/
    Tube(int radius, int height);

    /*! \brief Установка радиуса
	*  \param radius Начальный радиус
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_radius(int radius);

    /*! \brief Установка длины
	*  \param height Начальная длина
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_height(int height);

    /*! \brief Получение текущего радиуса
	*  \return Радиус
	*/
    int get_radius() const;

    /*! \brief Получение текущей длины
	*  \return Длина
	*/
    int get_height() const;

};
#endif //TUBE_H
