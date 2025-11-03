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
class BasicParams {
public:
    /*! \brief Конструктор по умолчанию */
    BasicParams() = default;

    /*! \brief Параметризованный конструктор
    *  \param height Начальная длина
    *  \param width Начальный ширина
    */
    BasicParams(int height, int width);

    /*! \brief Установка длины
    *  \param height Новое значение длины
    */
    void SetHeight(int height);

    /*! \brief Установка ширины
    *  \param width Новое значение ширины
    */
    void SetWidth(int width);

    /*! \brief Установка длины и ширины
    *  \param height Новое значение длины
    *  \param width Новое значение ширины
    */
    void SetSize(int height, int width);

    /*! \brief Получение текущей длины
    *  \return Длина
    */
    int GetHeight() const;

    /*! \brief Получение текущей ширины
    *  \return Длина
    */
    int GetWidth() const;

    /*! \brief Получение текущих размеров
    */
    void GetSize(int &height, int &width) const;

protected:
    int height_{0}; /*!< Высота/длина объекта */
    int width_{0}; /*!< Ширина объекта */
};

/*! \class Color
 *  \brief Класс для работы с цветами
 *  \details Класс предоставляет возможность работы корректной работы с разными существующими цветами
 */
class Color {
public:
    /*! \brief Конструктор по умолчанию */
    Color() = default;

    /*! \brief Параметризованный конструктор
    * \param color Первоначальный цвет
    */
    Color(const std::string &color);

    /*! \brief Установка цвета
    * \param color Новое значение цвета
    */
    void SetColor(std::string color);

    /*! \brief Получение длины
    * \return Цвет
    */
    std::string GetColor() const;

private:
    std::string color_; /*!< Цвет объекта */
};

/*! \class Volume
* \brief Класс для определения объема
* \details Класс предоставляет возможность получения и изменения данных об объеме
*/
class Volume {
public:
    /*! \brief Конструктор по умолчанию */
    Volume() = default;

    /*! \brief Параметризованный конструктор
    * \param volume Начальный объем
    */
    Volume(int volume);

    /*! \brief Установка объема
    * \param volume Новое значение объема
    */
    void SetVolume(int volume);

    /*! \brief Получение объема
    * \return Объем
    */
    int GetVolume() const;

private:
    int volume_{0}; /*!< Объем*/;
};

/*! \class CarSetter
* \brief Класс для установки значений
*/
class CarSetter {
public:
    /*! \brief Установка процента
    * \param procent процент
    * \param value куда присвоить
    */
    static void SetSinglePercent(int procent, int &value);

    /*! \brief Установка целого числа
    * \param integer_number целое число
    * \param description описание ошибки
    * \param value куда присвоить
    */
    static void SetSingleValue(int integer_number, const char *description, int &value);
};

/*! \class CarStringFormatter
* \brief Класс для форматирования строк
* \details Класс предоставляет возможность приводить все символы к одному регистру
*/
class CarStringFormatter {
public:
    /*! \brief Функция переводит строку внижний регистр
    * \param str строка
    */
    static void ToLower(std::string &str);
};

/*! \class CarLogger
* \brief Класс для логирования
* \details Класс предоставляет возможность логировать события
*/
class CarLogger {
public:
    /*! \brief Функция записывает сообщение в файл
    * \param message Cообщение
    * \param file_name  Файл, в который записывается сообщение
    * \return true если запись прошла успешно, false в противном случае
    */
    static bool LogToFile(const char *message, const std::string &file_name);

    /*! \brief Очитска файла логирования, если он существует
    * \return Число 0 если все прошло успешно, 1 в обратном случае
    */
    static int CheckFileLog(const std::string &file_name);
};

/*! \class CarValidator
* \brief Класс для валидации данных
* \details Класс предоставляет возможность проверять на корректность элементы
*/
class CarValidator {
public:
    /*! \brief Функция проверяет переданную строку на принадлежность массиву строк
    * \param vector_of_string массив строк
    * \param statement проверяемая строка
    * \return true если строка принадлежит массиву, false в противном случае
    */
    static bool CheckIsStatementCorrect(const std::vector<std::string> &vector_of_string, std::string &statement);
};

/*! \class MathOperations
* \brief Класс для выполнения математических действий
* \details Класс предоставляет возможность рассчитывать математические данные
*/
class MathOperations {
public:
    /*! \brief Получение числа, которое является частью передаваемого числа
    * \param number исходное число
    * \param procent процент от числа
    * \return Новое число
    */
    static int GetNewValueAfterMultiplication(int number, int procent);

    /*! \brief  Рассчет скорости звука в определенной температуре
    * \param temperature температура
    * \return Скорость звука в определенной температуре
    */
    static double GetNewValueAfterMultiplication(double temperature);
};

#endif //INCLUDE_BASIC_PARAMS_H
