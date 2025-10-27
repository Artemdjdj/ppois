/*! \file gas_tank.h
* \brief Заголовочный файл с определением класса бензобака
*/
#ifndef INCLUDE_GAS_TANK_H
#define INCLUDE_GAS_TANK_H
#include <string>
#include "../Include/basic_params.h"
#include "../Fuel/fuel.h"
#include "../CarPart/car_part.h"

/*! \class GasTank
* \brief Класс для определения бензобака
* \details Класс предоставляет возможность получения и изменения базовых параметров бензобака
*/
class GasTank : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	* \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is gas tank";
	}

	/*! \brief Конструктор по умолчанию */
	GasTank();

	/*! \brief Параметризованный конструктор
	* \param percentage Начальная заполненность
	* \param type_of_fuel Начальная тип топлива
	* \param season Начальный сезон года
	* \param volume Начальный объем
	*/
	GasTank(int percentage, const std::string& type_of_fuel, const std::string& season, int volume);

	/*! \brief Установка процента заполненности
	* \param procent Новое значение заполненности
	*/
	void SetPercentageOfOccupancy(int procent);

	/*! \brief Получение текущей заполненности
	* \return Заполненность
	*/
	int GetPercentageOfOccupancy() const;

	/*! \brief Получение текущего объема
	* \return Объем
	*/
	int GetVolume() const;

	/*! \brief Получение текущего вида топлива
	* \return Вид топлива
	*/
	std::string GetFuel();

	/*! \brief Установка объема
	* \param volume Новое значение объема
	*/
	void SetVolume(int volume);

	/*! \brief Установка типа топлива
	* \param type_of_fuel Новый вид топлива
	*/
	void SetFuel(const std::string& type_of_fuel);

	/*! \brief Установка сезона года
	* \param season Новый сезон года
	*/
	void SetSeason(const std::string& season);

	/*! \brief Установка механического индикатора
	* \param is_mechanical_indicator Новый сезон года
	*/
	void SetMechanicalIndicator(bool is_mechanical_indicator);

	/*! \brief Получение текущего сезона года
	* \return Сезон года
	*/
	std::string GetSeason();

	/*! \brief Получение свободного места
	* \return Свободное место в баке
	*/
	int CheckHowMuchEmptySpace() const;

	/*! \brief Получение механического индикатора (есть ли он)
	* \return Есть ли механический индикатор
	*/
	bool CheckIsMechanicalIndicator() const;

private:
	Volume volume_;/*!< Объем бака */;
	Fuel fuel_;/*!< Тип топлива */;
	int percentage_of_occupancy_{0};/*!< Процент заполненности */;
	bool is_mechanical_indicator_{false} /*!< Механический индикатор  (есть ли он)*/;
};

#endif //INCLUDE_GAS_TANK_H
