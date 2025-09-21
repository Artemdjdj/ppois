/*! \file metal_links.h
 *  \brief Заголовочный файл с определением классов для металической цепи
 */
#ifndef INCLUDE_METAL_LINKS_H
#define INCLUDE_METAL_LINKS_H
#include "../include/basic_params.h"
#include "tube.h"
#include <string>
#include <utility>
#include <vector>
#include "../CarPart/car_part.h"

/*! \class Plata
 *  \brief Класс для определения базовых параметров металлической пластины
 *  \details Класс предоставляет возможность получения и изменения базовых параметров металлической пластины
 */
class Plata{
private:
    BasicParams size;/*!< Размеры */;
    std::string material{"steel"};/*!< Материал */;
public:

    /*! \brief Конструктор по умолчанию */
    Plata();

    /*! \brief Параметризованный конструктор
	*  \param height Начальная длина
	*  \param width Начальная ширина
	*/
    Plata(int height, int width);

    /*! \brief Установка длины
	*  \param height Новое значение длины
    *  \param width Новое значение ширины
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_plata_size(int height, int width);

    /*! \brief Получение текущей длины
	*  \return Длина
	*/
    int get_height_of_plata() const;

    /*! \brief Получение текущей ширины
	*  \return Ширина
	*/
    int get_width_of_plata() const;

    /*! \brief Получение материала
	*  \return Материал пластины
	*/
    std::string get_material() const;
};

/*! \class MetalCylinder
 *  \brief Класс для определения базовых параметров металлического циллиндра
 *  \details Класс предоставляет возможность получения и изменения базовых параметров метааллического циллиндра
 */
class MetalCylinder:public Tube{
private:
    int weight{0};/*!< Масса */;
public:
    /*! \brief Конструктор по умолчанию */
    MetalCylinder();

    /*! \brief Параметризованный конструктор
    *  \param radius Начальный радиус
	*  \param height Начальная длина
	*  \param width Начальная ширина
	*/
    MetalCylinder(int radius, int height, int weight);

    /*! \brief Установка массы
	*  \param weight Новое значение массы
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_weight(int weight);

    /*! \brief Получение текущей массы
	*  \return Масса
	*/
    int get_weight() const;
};

/*! \class MetalLink
 *  \brief Класс для определения базовых параметров соединителя
 *  \details Класс предоставляет возможность получения и изменения базовых параметров соединителя
 */
class MetalLink {
private:
    std::pair<Plata, Plata> two_plats;/*!< Пара плат */;
    MetalCylinder cylinder;/*!< Цилиндр */;
public:

    /*! \brief Конструктор по умолчанию */
    MetalLink();

    /*! \brief Параметризованный конструктор
    *  \param height_of_plata Начальная длина
	*  \param width_of_plata Начальная ширина
    *  \param radius Начальный радиус
	*  \param height Начальная высота
	*  \param weight Начальная масса
	*/
    MetalLink(int height_of_plata, int width_of_plata, int radius, int height, int weight);

    /*! \brief Установка размеров платы
	*  \param height_of_plata Начальная длина платы
	*  \param width_of_plata Начальная ширина платы
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_data_for_two_plats(int height_of_plata, int width_of_plata);

    /*! \brief Получение текущей длины платы
	*  \return Длина
	*/
    int get_height_of_plata_for_user() const;

    /*! \brief Получение текущей ширины платы
	*  \return Ширина
	*/
    int get_width_of_plata_for_user() const;

    /*! \brief Установка размеров цилиндра
    *  \param radius Начальный радиус
	*  \param height Начальная высота
	*  \param weight Начальная масса
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_data_for_cylinder(int radius, int height, int weight);
};


/*! \class MetalChain
 *  \brief Класс для определения базовых параметров цепи двигателя
 *  \details Класс предоставляет возможность получения и изменения базовых параметров цепи двигателя
 */
class MetalChain:public CarPart {
private:
    std::vector<MetalLink> chain;/*!< Массив соединителей */;
public:

	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string get_info_about_part() const override {
		return"This class describes metal chain in  engine";
	}

    /*! \brief Функция добавляет  новый соединитель, то есть увеличивает длину цепи
    *  \param new_metal_link соединитель
    */
    void add_new_metal_link(const MetalLink& new_metal_link);

    /*! \brief Функция удаляет один соединитель
    */
    void delete_metal_link();

    /*! \brief Получение текущего размера цепи(длины)
	*  \return Длина
	*/
    int get_lens_of_metal_chain() const;
};
#endif //INCLUDE_METAL_LINKS_H
