/*! \file project_utils.h
 *  \brief Заголовочный файл с определением классов настроек
 */
#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H
#define NUMBER_OF_VERSION "1.0.0" /*!< Версия проекта */
#define GREEN "\033[32m" /*!< Зеленый цвет */
#define RED "\033[31m" /*!< Красный цвет*/
#define RESET "\033[0m" /*!< Сброс цвета*/
#define MIN_YEAR 1930 /*!< Минимальный год */
#define MAX_YEAR 2025 /*!< Максимальный год  */
#define MIN_COUNT_OF_PAGES 6 /*!< Минимальное количество страниц в книге */
#define MAX_COUNT_OF_PAGES 22000 /*!< Максимальное количество страниц в книге */
#define MIN_READER_YEAR 3 /*!< Минимальный возраст читателя */
#define MAX_READER_YEAR 18 /*!< Максимальный возраст читателя */
#define YEAR_OF_FIRST_SONG 1860 /*!< Год первой песни */
#define MAX_LENGTH_OF_SONG 10.0 /*!< Максимальная длина песни в минутах */
#define MIN_LENGTH_OF_SONG 0.02 /*!< Минимальная длина песни в минутах */
#define MAX_LENGTH_OF_FILM 48.0 /*!< Максимальная длина фильма в часах */
#define MIN_LENGTH_OF_FILM 0.017 /*!< Минимальная длина фильма в часах */
#define RATING 10 /*!< Максимальный рейтинг */
#define FIRST_FILM 1888 /*!< Год первого фильма */
#define MAX_LENGTH_OF_LIFE 140 /*!< Максимальная продолжительность жизни */
#define MIN_AGE 13 /*!< Минимальный возраст пользователя */
#include <string>
#include <unordered_set>
#include <vector>
#include <../User/user.h>
#include <functional>
#include "../Exceptions/exceptions.h"
#include "validator.h"
#include <stdexcept>

const std::string kMainLogFile = "../Logs/main_log.txt"; /*!< Основной файл для логирования */

/*! \class Info
 *  \brief Базовый класс для хранения информации с названием и описанием
 *  \details Предоставляет базовый функционал для работы с именованными объектами информации
 */
class Info {
protected:
    /*! \brief Защищенный конструктор по умолчанию */
    Info() = default;

public:
    /*! \brief Виртуальный деструктор */
    virtual ~Info() = default;

    /*! \brief Установка названия
     *  \param name Название
     */
    virtual void SetName(const std::string &name);

    /*! \brief Установка информации
     *  \param info Информация/описание
     */
    virtual void SetInfo(const std::string &info);

    /*! \brief Получение названия
     *  \return Название
     */
    virtual std::string GetName() const;

    /*! \brief Получение информации
     *  \return Информация/описание
     */
    virtual std::string GetInfo() const;

protected:
    std::string name_; /*!< Название */
    std::string info_; /*!< Информация */
};

/*! \class PropertySetter
 *  \brief Класс с утилитами для настроек проекта
 *  \details Предоставляет статические методы для установки значений
 */
class PropertySetter {
public:
    /*! \brief Установка значения с проверкой автора
     *  \param property Свойство для установки
     *  \param value Новое значение
     *  \param user Пользователь, пытающийся установить значение
     *  \param user_checked Ожидаемый пользователь (автор)
     *  \param error_incorrect_author Сообщение об ошибке при несовпадении авторов
     *  \param error_invalid_value Сообщение об ошибке при невалидном значении
     */
    static void SetValueWithAuthor(std::string &property, const std::string &value, const std::string &user,
                                   const std::string &user_checked,
                                   const std::string &error_incorrect_author,
                                   const std::string &error_invalid_value);

    /*! \brief Установка значения с валидацией
     *  \param property Свойство для установки
     *  \param value Новое значение
     *  \param error_invalid_value Сообщение об ошибке при невалидном значении
     */
    static void SetValue(std::string &property, const std::string &value,
                         const std::string &error_invalid_value);
};

/*! \class Logger
 *  \brief Класс для логирования ошибок
 */
class Logger {
public:
    /*! \brief Запись в лог-файл
     *  \param msg Сообщение для логирования
     *  \param file_name Имя файла для записи
     */
    static void LogFile(const char *msg, const std::string &file_name);

    /*! \brief Очистка файла
     *  \param file_name Имя файла для очистки
     */
    static void ClearFile(const std::string &file_name);
};

/*! \class StringFormatter
 *  \brief Класс для форматирования строк
 */
class StringFormatter {
public:
    /*! \brief Преобразование строки к нижнему регистру
     *  \param str Строка для форматирования
     */
    static void ToLower(std::string &str);
};

/*! \class TimeProvider
 *  \brief Класс для работы с временем
 */
class TimeProvider {
public:
    /*! \brief Получение текущего реального времени
     *  \return Строка с текущим временем
     */
    static std::string GetRealTime();
};

/*! \class WorkingWithVector
 *  \brief Класс с утилитами для работы с векторами
 *  \details Предоставляет статические шаблонные методы для работы с различными типами векторов
 */
class WorkingWithVector {
public:
    /*! \brief Добавление элемента в вектор
     *  \tparam T Тип элементов вектора
     *  \param vec Вектор для добавления
     *  \param val Значение для добавления
     */
    template<typename T>
    static void AddElementToVector(std::vector<T> &vec, const T &val) {
        vec.push_back(val);
    }

    /*! \brief Добавление weak_ptr элемента в вектор
     *  \tparam T Тип элементов вектора
     *  \param vec Вектор weak_ptr для добавления
     *  \param element Элемент для добавления
     */
    template<typename T>
    static void AddElementToVector(std::vector<std::weak_ptr<T> > &vec, const std::shared_ptr<T> &element) {
        if (!element) {
            throw std::invalid_argument("Invalid user pointer!");
        }
        vec.push_back(element);
    }

    /*! \brief Добавление shared_ptr элемента в вектор
     *  \tparam T Тип элементов вектора
     *  \param vec Вектор shared_ptr для добавления
     *  \param element Элемент для добавления
     */
    template<typename T>
    static void AddElementToVector(std::vector<std::shared_ptr<T> > &vec, const std::shared_ptr<T> &element) {
        if (!element) {
            throw std::invalid_argument("Invalid user pointer!");
        }
        vec.push_back(element);
    }

    /*! \brief Добавление строки в вектор
     *  \param vec Вектор строк для добавления
     *  \param element Строка для добавления
     */
    static void AddElementToVector(std::vector<std::string> &vec, const std::string &element) {
        if (element.empty()) {
            throw std::invalid_argument("Invalid input!");
        }
        vec.push_back(element);
    }

    /*! \brief Удаление элемента из вектора по позиции
     *  \tparam T Тип элементов вектора
     *  \param vec Вектор для удаления
     *  \param pos Позиция элемента для удаления
     */
    template<typename T>
    static void DeleteElementFromVectorByPos(std::vector<T> &vec, int pos) {
        if (pos < 0 or pos >= vec.size()) {
            throw ExceptionIncorrectNumber("Incorrect number of del element");
        }
        vec.erase(vec.begin() + pos);
    }

    /*! \brief Редактирование элемента в векторе
     *  \tparam T Тип элементов вектора
     *  \param vec Вектор для редактирования
     *  \param value Новое значение
     *  \param pos Позиция элемента для редактирования
     */
    template<typename T>
    static void RefactorElement(std::vector<T> &vec, const T &value, int pos) {
        if (pos < 0 or pos >= vec.size()) {
            throw ExceptionIncorrectNumber("Incorrect number of del element");
        }
        vec[pos] = value;
    }

    /*! \brief Очистка вектора
     *  \tparam T Тип элементов вектора
     *  \param vec Вектор для очистки
     */
    template<typename T>
    static void DeleteAll(std::vector<T> &vec) {
        vec.clear();
    }

    /*! \brief Удаление неиспользуемых weak_ptr из вектора
     *  \tparam T Тип элементов вектора
     *  \param vec Вектор weak_ptr для очистки
     */
    template<typename T>
    static void DeleteUnUsedWeakPtrs(std::vector<std::weak_ptr<T> > &vec) {
        std::erase_if(vec, std::mem_fn(&std::weak_ptr<T>::expired));
    }
};

#endif
