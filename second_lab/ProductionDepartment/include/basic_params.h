/*! \file basic_params.h
 *  \brief Заголовочный файл с определением базовых классов и некоторых функций
 *  \details Классы для упрощения работы
 */
#ifndef INCLUDE_BASIC_PARAMS_H
#define INCLUDE_BASIC_PARAMS_H
#include <string>
#include <vector>
#include "../CarPart/car_part.h"
#include "settings.h"

/*! \class BasicParams
 *  \brief Класс для определения базовых параметров
 *  \details Класс предоставляет возможность получения и изменения базовых параметров
 */
class BasicParams{
private:
    int height{0}; /*!< Высота/длина объекта */
    int width{0}; /*!< Ширина объекта */
public:
    /*! \brief Конструктор по умолчанию */
    BasicParams();

    /*! \brief Параметризованный конструктор
     *  \param height Начальная длина
     *  \param width Начальный ширина
     */
    BasicParams(int height, int width);

    /*! \brief Установка длины
     *  \param height Новое значение длины
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool set_height(int height);

    /*! \brief Установка ширины
     *  \param width Новое значение ширины
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool set_width(int width);

    /*! \brief Установка длины и ширины
     *  \param height Новое значение длины
     *  \param width Новое значение ширины
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool set_size(int height, int width);

    /*! \brief Получение текущей длины
     *  \return Длина
     */
    int get_height() const;

    /*! \brief Получение текущей ширины 
     *  \return Длина
     */
    int get_width() const;

    /*! \brief Получение текущих размеров
     */
    void get_size(int & height, int & width) const;
};

/*! \class Color
 *  \brief Класс для работы с цветами
 *  \details Класс предоставляет возможность работы корректной работы с разными существующими цветами
 */
class Color{
private:
    std::string color;/*!< Цвет объекта */

    /*! \brief Функция проверяет цвет на корректность
     *  \param color цвет
     */
    void set_color_private(std::string color);
public:

    /*! \brief Конструктор по умолчанию */
    Color();

    /*! \brief Параметризованный конструктор
     *  \param сolor первоначальный цвет
     */
    Color(std::string color);

    /*! \brief Установка цвета
     *  \param color Новое значение цвета
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool set_color(std::string color);

    /*! \brief Получение длины
     *  \return Цвет
     */
    std::string get_color();
};

/*! \class Volume
 *  \brief Класс для определения объема
 *  \details Класс предоставляет возможность получения и изменения данных об объеме
 */
class Volume {
private:
    int volume{0}; /*!< Объем*/;
public:

    /*! \brief Конструктор по умолчанию */
    Volume();

    /*! \brief Параметризованный конструктор
     *  \param volume Начальный объем
     */
    Volume(int volume);

    /*! \brief Установка объема
     *  \param volume Новое значение объема
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool set_volume(int volume);

    /*! \brief Получение объема
     *  \return Объем
     */
    int get_volume() const;
};

/*! \brief Функция проверяет целое число на корректность
*  \param integer_number целое число
*  \param description строка описания ошибки
*/
void set_integer_number(int integer_number, const char * description);

/*! \brief Функция проверяет процент на корректность
*  \param percentage Целое число
*/
void set_procent(int percentage);

/*! \brief Установка процента
*  \param procent процент
*  \param value куда присвоить
*  \return true если установка прошла успешно, false в противном случае
*/
bool set_single_procent(int procent, int& value);

/*! \brief Установка целого числа
*  \param integer_number целое число
*  \param description описание ошибки
*  \param value куда присвоить
*  \return true если установка прошла успешно, false в противном случае
*/
bool set_single_value(int integer_number, const char * description, int &value);

/*! \brief Функция переводит строку внижний регистр
*  \param str строка
*/
void ToLower(std::string& str);

/*! \brief Функция записывает сообщение в файл
*  \param message сообщение
*  \return true если запись прошла успешно, false в противном случае
*/
bool log_to_file(const char * message);

/*! \brief Функция проверяет переданную строку на принадлежность массиву строк
*  \param vector_of_string массив строк
*  \param statement проверяемая строка
*  \return true если строка принадлежит массиву, false в противном случае
*/
bool check_is_statement_correct(const std::vector<std::string>& vector_of_string, std::string& statement);

/*! \brief Получение числа, которое является частью передаваемого числа
*  \param number исходное число
*  \param procent процент от числа
*  \return Новое число
*/
int get_new_value_after_multiplication(int number, int procent);

/*! \brief  Рассчет скорости звука в определенной температуре
*  \param temperature температура
*  \return Скорость звука в определенной температуре
*/
double calculate_the_speed_of_sound_in_special_temperature(double temperature);
#endif //INCLUDE_BASIC_PARAMS_H
