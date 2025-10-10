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

	/*! \brief Параметризованный конструктор
	* \param height Начальная длина, базовое значение 0
	* \param width Начальный ширина, базовое значение 0
	*  \param color Начальный цвет, базовое цвет black
	*/
	SideMirror(int height = 0, int width = 0, std::string color = "black");

	/*! \brief Деструктор */
	~SideMirror();

	/*! \brief Установка цвета
	*  \param color Новый цвет
	*/
	void SetColor(std::string color);

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
	~BackDoor();
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
	* \param height_door Начальная длина, 0
	* \param width_door Начальный ширина, 0
	*  \param height_mirror Начальная длина бокового окна, 0
	* \param width_mirror Начальная ширина бокового окна, 0
	* \param is_lock Закрыта ли, false
	* \param color Начальный цвет, black
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
	void OpenDoor();

	/*! \brief Функция закрывает дверь*/
	void CloseDoor();

	/*! \brief Функция проверяет открыта ли дверь
	* \return true если открыта, false в противном случае
	*/
	bool GetLock() const;

	/*! \brief Функция получает цвет в переменную
	* \param result_color цвет
	*/
	void GetColorOfMirror(std::string &result_color);

private:
	bool is_lock_ = false;/*!< Закрыта ли дверь */;
	SideMirror mirror_;/*!< Боковое зеркало */;
};

#endif //INCLUDE_DOOR_H
