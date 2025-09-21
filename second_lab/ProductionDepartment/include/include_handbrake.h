/*! \file include_handbrake.h
 *  \brief Заголовочный файл с определением класса ручника
 */
#ifndef INCLUDE_HANDBRAKE_H
#define INCLUDE_HANDBRAKE_H
#include "include_basic_params.h"

/*! \class Handbrake
 *  \brief Класс для определения базовых параметров ручника
 *  \details Класс предоставляет возможность получения и изменения базовых параметров ручника
 */
class Handbrake {
private:
    BasicParams size;/*!< Размеры */;
    bool is_block{false};/*!< Активен ли ручник */;
public:
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
    bool set_size(int height, int width);

    /*! \brief Получение текущей высоты
	*  \return Высота
	*/
    int get_height();

    /*! \brief Получение текущей ширины
	*  \return Ширина
	*/
    int get_width();

    /*! \brief Функция активирует ручник
    */
    void block_car();

    /*! \brief Функция деактивирует ручник
    */
    void unblock_car();

    /*! \brief Функция проверяет активен ли ручник
    *  \return Активен ли
    */
    bool get_is_block();
};
#endif //INCLUDE_HANDBRAKE_H
