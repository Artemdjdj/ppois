/*! \file metal_links.h
* \brief Заголовочный файл с определением классов для металической цепи
*/
#ifndef INCLUDE_METAL_LINKS_H
#define INCLUDE_METAL_LINKS_H
#include "../Include/basic_params.h"
#include "tube.h"
#include <string>
#include <utility>
#include <vector>
#include "../CarPart/car_part.h"

/*! \class Plata
* \brief Класс для определения базовых параметров металлической пластины
* \details Класс предоставляет возможность получения и изменения базовых параметров металлической пластины
*/
class Plata {
public:
	/*! \brief Конструктор по умолчанию */
	Plata();

	/*! \brief Параметризованный конструктор
	* \param height Начальная длина
	* \param width Начальная ширина
	*/
	Plata(int height, int width);

	/*! \brief Установка длины
	* \param height Новое значение длины
	* \param width Новое значение ширины
	*/
	void SetPlataSize(int height, int width);

	/*! \brief Получение текущей длины
	* \return Длина
	*/
	int GetHeightOfPlata() const;

	/*! \brief Получение текущей ширины
	* \return Ширина
	*/
	int GetWidthOfPlata() const;

	/*! \brief Получение материала
	* \return Материал пластины
	*/
	std::string GetMaterial() const;

private:
	BasicParams size_;/*!< Размеры */;
	std::string material_{"steel"};/*!< Материал */;
};

/*! \class MetalCylinder
* \brief Класс для определения базовых параметров металлического циллиндра
* \details Класс предоставляет возможность получения и изменения базовых параметров метааллического циллиндра
*/
class MetalCylinder : public Tube {
public:
	/*! \brief Конструктор по умолчанию */
	MetalCylinder();

	/*! \brief Параметризованный конструктор
	* \param radius Начальный радиус
	* \param height Начальная длина
	* \param width Начальная ширина
	*/
	MetalCylinder(int radius, int height, int weight);

	/*! \brief Установка массы
	* \param weight Новое значение массы
	*/
	void SetWeight(int weight);

	/*! \brief Получение текущей массы
	* \return Масса
	*/
	int GetWeight() const;

private:
	int weight_{0};/*!< Масса */;
};

/*! \class MetalLink
* \brief Класс для определения базовых параметров соединителя
* \details Класс предоставляет возможность получения и изменения базовых параметров соединителя
*/
class MetalLink {
public:
	/*! \brief Конструктор по умолчанию */
	MetalLink();

	/*! \brief Параметризованный конструктор
	* \param height_of_plata Начальная длина
	* \param width_of_plata Начальная ширина
	* \param radius Начальный радиус
	* \param height Начальная высота
	* \param weight Начальная масса
	*/
	MetalLink(int height_of_plata, int width_of_plata, int radius, int height, int weight);

	/*! \brief Установка размеров платы
	* \param height_of_plata Начальная длина платы
	* \param width_of_plata Начальная ширина платы
	*/
	void SetDataForTwoPlats(int height_of_plata, int width_of_plata);

	/*! \brief Получение текущей длины платы
	* \return Длина
	*/
	int GetHeightOfPlataForUser() const;

	/*! \brief Получение текущей ширины платы
	* \return Ширина
	*/
	int GetWidthOfPlataForUser() const;

	/*! \brief Установка размеров цилиндра
	* \param radius Начальный радиус
	* \param height Начальная высота
	* \param weight Начальная масса
	*/
	void SetDataForCylinder(int radius, int height, int weight);

private:
	std::pair<Plata, Plata> two_plats_;/*!< Пара плат */;
	MetalCylinder cylinder_;/*!< Цилиндр */;
};


/*! \class MetalChain
* \brief Класс для определения базовых параметров цепи двигателя
* \details Класс предоставляет возможность получения и изменения базовых параметров цепи двигателя
*/
class MetalChain : public CarPart {
public:
	/*! \brief Переопределение унаследованной функции
	* \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is metal chain and the length is "+ std::to_string(this->chain_.size());
	}

	/*! \brief Функция добавляет  новый соединитель, то есть увеличивает длину цепи
	* \param new_metal_link соединитель
	*/
	void AddNewMetalLink(const MetalLink &new_metal_link);

	/*! \brief Функция удаляет один соединитель
	*/
	void DeleteMetalLink();

	/*! \brief Получение текущего размера цепи(длины)
	* \return Длина
	*/
	int GetLensOfMetalChain() const;

private:
	std::vector<MetalLink> chain_;/*!< Массив соединителей */;
};
#endif //INCLUDE_METAL_LINKS_H
