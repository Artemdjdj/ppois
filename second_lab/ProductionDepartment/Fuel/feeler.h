/*! \file feeler.h
 *  \brief Заголовочный файл с декларацией класса Feeler
 *  \details Содержит определение класса для работы с датчиком уровня
 */

#ifndef INCLUDE_FEELER_H
#define INCLUDE_FEELER_H
#include "../CarPart/car_part.h"

/*! \class Feeler
 *  \brief Класс для проверки уровня масла(щуп)
 *  \details Класс предоставляет функционал для установки и получения длины и уровня,
 *           а также проверки корректности состояния уровня
 */
class Feeler:public CarPart {
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return"This class describes feeler, which help to see the level of oil in engine";
    }

    /*! \brief Конструктор по умолчанию */
    Feeler();

    /*! \brief Параметризованный конструктор
     *  \param length Начальная длина щупа
     *  \param level Начальный уровень
     */
    Feeler(int length, int level);

    /*! \brief Установка длины щупа
     *  \param length Новое значение длины
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool SetLength(int length);

    /*! \brief Установка уровня
     *  \param level Новое значение уровня
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool SetLevel(int level);

    /*! \brief Получение текущей длины щупа
     *  \return Текущая длина щупа
     */
    int GetLength() const;

    /*! \brief Получение текущего уровня
     *  \return Текущий уровень
     */
    int GetLevel() const;

    /*! \brief Проверка уровня
     *  \return true если уровень в норме, false в противном случае
     */
    bool CheckIsTheLevelInNormState() const;

private:
    /*! \brief Приватный метод проверки корректности уровня
    *  \details Выполняет внутреннюю проверку состояния уровня
    */
    void CheckIsTheLevelInNormState_private() const;

private:
    int length_{0}; /*!< Длина  щупа */
    int level_{0};  /*!< Текущий уровень */
};

#endif //INCLUDE_FEELER_H