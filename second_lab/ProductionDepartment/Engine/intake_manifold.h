/*! \file intake_manifold.h
 *  \brief Заголовочный файл с определением класса впускного коллектора
 */
#ifndef INCLUDE_INTAKE_MANIFOLD_H
#define INCLUDE_INTAKE_MANIFOLD_H
#include "../Include/basic_params.h"
#include "tube.h"
#include <optional>
#include "../CarPart/car_part.h"

/*! \class IntakeManifold 
 *  \brief Класс для определения базовых параметров впускного коллекторра
 *  \details Класс предоставляет возможность получения и изменения базовых параметров впускного коллектора
 */
class IntakeManifold : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is intake manifold";
	}

	/*! \brief Конструктор по умолчанию */
	IntakeManifold();

	/*! \brief Параметризованный конструктор
	*  \param main_volume Начальный весь объем
	*  \param width Начальный радиус трубки
	*  \param height_canal Начальныая длина трубки
	*  \param number_of_canals Начальное количество трубок
	*/
	IntakeManifold(int main_volume, int radius_canal, int height_canal, int number_of_canals);

	/*! \brief Установка всего объема
	*  \param main_volume Новое значение добъема
	*/
	void SetMainVolume(int main_volume);

	/*! \brief Установка объема камеры
	*/
	void SetPlenumVolume();

	/*! \brief Установка длины трубки
	*  \param height_canal Новое значение длины
	*/
	void SetHeightCanal(int height_canal);

	/*! \brief Установка радиуса трубки
	*  \param radius_canal Новое значение радиуса
	*/
	void SetRadiusCanal(int radius_canal);

	/*! \brief Установка количество трубок
	*  \param number_of_canals Новое количество трубок
	*/
	void SetNumberOfCanals(int number_of_canals);

	/*! \brief Получение текущего количества трубок
	*  \return Количество трубок
	*/
	int GetNumberOfCanals() const;

	/*! \brief Получение текущего радиуса
	*  \return Радиус
	*/
	int GetRadiusCanal() const;

	/*! \brief Получение длины трубки
	*  \return Длина
	*/
	int GetHeightCanal() const;

	/*! \brief Получение текущего объема камеры
	*  \return Объем
	*/
	int GetPlenumVolume() const;

	/*! \brief Рассчет текущей частоты
	*  \return Частота, или если какие-то параметры некорректны, то nullodt
	*/
	std::optional<double> CalculateResponseFrequency(double temperature) const;

private:
	Volume main_volume_;/*!< Главный объем */;
	Volume plenum_volume_;/*!< Объем камеры */;
	Tube canal_;/*!< Трубка */;
	int number_of_canals_;/*!< Количество трубок */;
};
#endif
