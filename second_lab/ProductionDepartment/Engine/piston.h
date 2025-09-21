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
class Piston:public CarPart {
private:
    int diameter{0};/*!< Диаметр */;
    int height{0};/*!< Высота */;
    int compression_height{0};/*!< Высота поднятия */;
    int count_of_cycles{0};/*!< Количество циклов */;
    int weight{0};/*!< Масса */;
public:

	/*! \brief Переопределение унаследованной функции
	*  \return Описание
	*/
	std::string get_info_about_part() const override {
		return"This class describes piston in engine";
	}

    /*! \brief Конструктор по умолчанию */
    Piston();

    /*! \brief Параметризованный конструктор
	*  \param diameter Начальный диаметр
	*  \param height Начальная высота
    *  \param compression_height Начальная высота поднятия
	*  \param count_of_cycles Начальное количество циклов
    *  \param weight Начальная масса
	*/
    Piston(int diameter, int height, int compression_height, int count_of_cycles, int weight);

    /*! \brief Установка всех параметров
	*  \param diameter Начальный диаметр
	*  \param height Начальная высота
    *  \param compression_height Начальная высота поднятия
	*  \param count_of_cycles Начальное количество циклов
    *  \param weight Начальная масса
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_all_parameters(int diameter, int height, int compression_height, int count_of_cycles, int weight);

    /*! \brief Получение текущего диаметра
	*  \return Диаметер
	*/
    int get_diameter() const;

    /*! \brief Получение текущего количества циклов
	*  \return Количество циклов
	*/
    int get_count_of_cycles() const;

    /*! \brief Получение текущей высоты
	*  \return Высота
	*/
    int get_height() const;

    /*! \brief Получение текущей массы
	*  \return Масса
	*/
    int get_weight() const;

    /*! \brief Проверка работоспособности поршня
	*  \return true если износа нет, false в противном случае
	*/
    bool check_is_piston_in_working_condition() const;
};
#endif //INCLUDE_PISTON_H
