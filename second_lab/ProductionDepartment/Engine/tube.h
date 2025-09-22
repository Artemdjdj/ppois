/*! \file tube.h
 *  \brief Заголовочный файл с определением класса трубки
 *  \details Классы для упрощения работы
 */
#ifndef TUBE_H
#define TUBE_H
#include "../Wheel/wheel.h"
#include "../CarPart/car_part.h"

/*! \class Tube
 *  \brief Класс для определения базовых параметров трубки
 *  \details Класс предоставляет возможность получения и изменения базовых параметров трубки
 */
class Tube:public CarPart{
public:

	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return"This class describes tube";
	}

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
    bool SetRadius(int radius);

    /*! \brief Установка длины
	*  \param height Начальная длина
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool SetHeight(int height);

    /*! \brief Получение текущего радиуса
	*  \return Радиус
	*/
    int GetRadius() const;

    /*! \brief Получение текущей длины
	*  \return Длина
	*/
    int GetHeight() const;

private:
	BaseCircle radius_;/*!< Радиус трубки */;
	int height_{0};/*!<Длина трубки */;

};
#endif //TUBE_H
