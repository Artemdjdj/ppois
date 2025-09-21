/*! \file electric_details.h
 *  \brief Заголовочный файл с определениями классов электрических компонентов
 *  \details Классы для работы с электрическими компонентами, такими как стартеры и аккумуляторы
 */

#ifndef INCLUDE_ELECTRIC_DETAILS_H
#define INCLUDE_ELECTRIC_DETAILS_H
#include <string>
#include "../CarPart/car_part.h"

/*! \class ElectroPart
 *  \brief Базовый абстрактный класс для электрических компонентов
 *  \details Класс предоставляет функциональность для работы с основными электрическими параметрами
 */
class ElectroPart :public CarPart{
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return"This class describes a default ElectroPart";
    }

    /*! \brief Конструктор по умолчанию */
    ElectroPart();

    /*! \brief Конструктор с параметрами
     *  \param voltage Начальное значение напряжения, по умолчанию 0
     *  \param power Начальное значение мощности, по умолчанию 0 
     *  \param current_strength Начальное значение тока, по умолчанию 0
     */
    ElectroPart(int voltage, int power, int current_strength);

    /*! \brief Устанавливает значение напряжения
     *  \param voltage Новое значение напряжения
     *  \return true, если значение было установлено успешно
     */
    bool SetVoltage(int voltage);

    /*! \brief Устанавливает значение мощности
     *  \param power Новое значение мощности
     *  \return true, если значение было установлено успешно
     */
    bool SetPower(int power);

    /*! \brief Устанавливает значение силы тока
     *  \param current_strength Новое значение тока
     *  \return true, если значение было установлено успешно
     */
    bool SetCurrentStrength(int current_strength);

    /*! \brief Получает значение напряжения
     *  \return Текущее значение напряжения
     */
    int GetVoltage() const;

    /*! \brief Получает значение мощности
     *  \return Текущее значение мощности
     */
    int GetPower() const;

    /*! \brief Получает значение силы тока
     *  \return Текущее значение силы тока
     */
    int GetCurrentStrength() const;

    /*! \brief Виртуальный деструктор */
    virtual ~ElectroPart()= default;

private:
    int voltage_{0};             //!< Значение напряжения в вольтах
    int power_{0};              //!< Значение мощности в ваттах
    int current_strength_{0};    //!< Сила тока в амперах

};

/*! \class Starter
 *  \brief Класс для стартера
 *  \details Класс предоставляет функциональность для работы с параметрами стартера
 */
class Starter : public ElectroPart {
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return"This class describes electrto part Starter";
    }

    /*! \brief Конструктор по умолчанию */
    Starter();

    /*! \brief Конструктор с параметрами
     *  \param voltage Начальное значение напряжения
     *  \param power Начальное значение мощности
     *  \param current_strength Начальное значение тока
     *  \param is_left_direction Начальное направление вращения
     *  \param count_of_prong Начальное количество штырей
     */
    Starter(int voltage, int power, int current_strength, 
            bool is_left_direction, int count_of_prong);

    /*! \brief Устанавливает направление вращения вправо */
    void ChooseRightDirection();

    /*! \brief Устанавливает направление вращения влево */
    void ChooseLeftDirection();

    /*! \brief Устанавливает количество штырей
     *  \param count_of_prong Новое количество штырей
     *  \return true, если значение было установлено успешно
     */
    bool SetCountOfProg(int count_of_prong);

    /*! \brief Получает количество штырей
     *  \return Текущее количество штырей
     */
    int GetCountOfProg() const;

    /*! \brief Получает направление вращения
     *  \return true для левого направления, false для правого
     */
    bool GetDirection() const;

private:
    bool is_left_direction_;     //!< Флаг направления вращения
    int count_of_prong_{0};     //!< Количество штырей/контактов
};

/*! \class Battery
 *  \brief Класс для аккумулятора
 *  \details Класс предоставляет функциональность для работы с параметрами аккумулятора
 */
class Battery : public ElectroPart {
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return"This class describes electrto part Battery";
    }

    /*! \brief Конструктор по умолчанию */
    Battery();

    /*! \brief Конструктор с параметрами
     *  \param voltage Начальное значение напряжения
     *  \param power Начальное значение мощности
     *  \param current_strength Начальное значение тока
     *  \param cold_cranking_current Начальный рейтинг холодного пуска
     */
    Battery(int voltage, int power, int current_strength,
            int cold_cranking_current);

    /*! \brief Устанавливает холодный пуск
     *  \param cold_cranking_current Новое значение холодного пуска
     *  \return true, если значение было установлено успешно
     */
    bool SetColdCrankingCurrent(int cold_cranking_current);

    /*! \brief Получает холодный пуск
     *  \return Текущее значение холодного пуска
     */
    int GetColdCrankingCurrent() const;

private:
    int cold_cranking_current_{0};   //!< Рейтинг холодного пуска в амперах
};

#endif //INCLUDE_ELECTRIC_DETAILS_H