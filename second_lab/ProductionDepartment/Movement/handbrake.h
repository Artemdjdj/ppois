/*! \file handbrake.h
 *  \brief Заголовочный файл с определением класса ручника
 */
#ifndef INCLUDE_HANDBRAKE_H
#define INCLUDE_HANDBRAKE_H
#include "../Include/basic_params.h"
#include "../CarPart/car_part.h"
/*! \class Handbrake
 *  \brief Класс для определения базовых параметров ручника
 *  \details Класс предоставляет возможность получения и изменения базовых параметров ручника
 */
class Handbrake : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is handbrake";
	}

	/*! \brief Конструктор по умолчанию */
	Handbrake();

	/*! \brief Параметризованный конструктор
	*  \param height Начальная высота
	*  \param width Начальный ширина
	*  \param is_car_block_nowth Начальное состочние ручника
	*/
	Handbrake(int height, int width, bool is_car_block_now);

	/*! \brief Установка длины и ширины
	*  \param height Новое значение высоты
	*  \param width Новое значение ширины
	*  \return true если установка прошла успешно, false в противном случае
	*/
	bool SetSize(int height, int width);

	/*! \brief Получение текущей высоты
	*  \return Высота
	*/
	int GetHeight() const;

	/*! \brief Получение текущей ширины
	*  \return Ширина
	*/
	int GetWidth() const;

	/*! \brief Функция активирует ручник
	*/
	void BlockCar();

	/*! \brief Функция деактивирует ручник
	*/
	void UnblockCar();

	/*! \brief Функция проверяет активен ли ручник
	*  \return Активен ли
	*/
	bool GetIsBlock() const;

private:
	BasicParams size_;/*!< Размеры */;
	bool is_block_{false};/*!< Активен ли ручник */;
};
#endif //INCLUDE_HANDBRAKE_H
