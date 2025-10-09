/*! \file piston.h
 *  \brief Заголовочный файл с определением базовых классов и некоторых функций класса поршень
 */
#ifndef INCLUDE_PISTON_H
#define INCLUDE_PISTON_H
#include "../CarPart/car_part.h"


/*! \class Piston
 *  \brief Класс для определения базовых параметров поршня
 *  \details Класс предоставляет возможность получения и изменения базовых параметров поршня
 */
class Piston : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is piston";
	}

	/*! \brief Конструктор по умолчанию */
	Piston();

	/*! \brief Параметризованный конструктор
	*  \param diameter Начальный диаметр
	*  \param height Начальная высота
	*  \param Compression_height Начальная высота поднятия
	*  \param count_of_cycles Начальное количество циклов
	*  \param weight Начальная масса
	*/
	Piston(int diameter, int height, int compression_height, int count_of_cycles, int weight);

	/*! \brief Установка всех параметров
	*  \param diameter Начальный диаметр
	*  \param height Начальная высота
	*  \param Compression_height Начальная высота поднятия
	*  \param count_of_cycles Начальное количество циклов
	*  \param weight Начальная масса
	*/
	void SetAllParameters(int diameter, int height, int compression_height, int count_of_cycles, int weight);

	/*! \brief Получение текущего диаметра
	*  \return Диаметер
	*/
	int GetDiameter() const;

	/*! \brief Получение текущего количества циклов
	*  \return Количество циклов
	*/
	int GetCountOfCycles() const;

	/*! \brief Получение текущей высоты
	*  \return Высота
	*/
	int GetHeight() const;

	/*! \brief Получение текущей массы
	*  \return Масса
	*/
	int GetWeight() const;

	/*! \brief Проверка работоспособности поршня
	*  \return true если износа нет, false в противном случае
	*/
	bool CheckIsPistonInWorkingCondition() const;

private:
	int diameter_{0};/*!< Диаметр */;
	int height_{0};/*!< Высота */;
	int compression_height_{0};/*!< Высота поднятия */;
	int count_of_cycles_{0};/*!< Количество циклов */;
	int weight_{0};/*!< Масса */;
};
#endif //INCLUDE_PISTON_H
