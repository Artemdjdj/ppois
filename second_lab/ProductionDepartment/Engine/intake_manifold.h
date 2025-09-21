/*! \file intake_manifold.h
 *  \brief Заголовочный файл с определением класса впускного коллектора
 */
#ifndef INCLUDE_INTAKE_MANIFOLD_H
#define INCLUDE_INTAKE_MANIFOLD_H
#include "../include/basic_params.h"
#include "tube.h"
#include <optional>
#include "../CarPart/car_part.h"

/*! \class IntakeManifold 
 *  \brief Класс для определения базовых параметров впускного коллекторра
 *  \details Класс предоставляет возможность получения и изменения базовых параметров впускного коллектора
 */
class IntakeManifold:public CarPart {
private:
    Volume main_volume;/*!< Главный объем */;
    Volume plenum_volume;/*!< Объем камеры */;
    Tube canal;/*!< Трубка */;
    int number_of_canals;/*!< Количество трубок */;
public:

	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string get_info_about_part() const override {
		return"This class describes intake manifold in engine";
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
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_main_volume(int main_volume);

    /*! \brief Установка объема камеры
	*/
    void set_plenum_volume();

    /*! \brief Установка длины трубки
	*  \param height_canal Новое значение длины
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_height_canal(int height_canal);

    /*! \brief Установка радиуса трубки
	*  \param radius_canal Новое значение радиуса
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_radius_canal(int radius_canal);

     /*! \brief Установка количество трубок
	*  \param number_of_canals Новое количество трубок
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_number_of_canals(int number_of_canals);

    /*! \brief Получение текущего количества трубок
	*  \return Количество трубок
	*/
    int get_number_of_canals() const;

    /*! \brief Получение текущего радиуса
	*  \return Радиус
	*/
    int get_radius_canal() const;

    /*! \brief Получение длины трубки
	*  \return Длина
	*/
    int get_height_canal() const;

    /*! \brief Получение текущего объема камеры
	*  \return Объем
	*/
    int get_plenum_volume() const;

    /*! \brief Рассчет текущей частоты
	*  \return Частота, или если какие-то параметры некорректны, то nullodt
	*/
    std::optional<double> calculate_response_frequency(double temperature) const;
private:
    /*! \brief Функция проверяет объем на корректность
    */
    void checking_volume() const;
};
#endif
