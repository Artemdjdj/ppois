/*! \file include_electric_details.h
 *  \brief Заголовочный файл с определениями классов электрических компонентов
 *  \details Классы для работы с электрическими компонентами, такими как стартеры и аккумуляторы
 */

#ifndef INCLUDE_ELECTRIC_DETAILS_H
#define INCLUDE_ELECTRIC_DETAILS_H
#include <string>

/*! \class ElectroPart
 *  \brief Базовый абстрактный класс для электрических компонентов
 *  \details Класс предоставляет функциональность для работы с основными электрическими параметрами
 */
class ElectroPart {
private:
    int voltage{0};             //!< Значение напряжения в вольтах
    int power{0};              //!< Значение мощности в ваттах
    int current_strength{0};    //!< Сила тока в амперах

public:
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
    bool set_voltage(int voltage);

    /*! \brief Устанавливает значение мощности
     *  \param power Новое значение мощности
     *  \return true, если значение было установлено успешно
     */
    bool set_power(int power);

    /*! \brief Устанавливает значение силы тока
     *  \param current_strength Новое значение тока
     *  \return true, если значение было установлено успешно
     */
    bool set_current_strength(int current_strength);

    /*! \brief Получает значение напряжения
     *  \return Текущее значение напряжения
     */
    int get_voltage() const;

    /*! \brief Получает значение мощности
     *  \return Текущее значение мощности
     */
    int get_power() const;

    /*! \brief Получает значение силы тока
     *  \return Текущее значение силы тока
     */
    int get_current_strength() const;

    /*! \brief Виртуальный деструктор */
    virtual ~ElectroPart()= default;

    /*! \brief Чисто виртуальная функция, которая возвращает назначение компонента
     *  \return Строка, описывающая назначение компонента
     */
    virtual std::string get_purpose()= 0;
};

/*! \class Starter
 *  \brief Класс для стартера
 *  \details Класс предоставляет функциональность для работы с параметрами стартера
 */
class Starter : public ElectroPart {
private:
    bool is_left_direction;     //!< Флаг направления вращения
    int count_of_prong{0};     //!< Количество штырей/контактов

public:
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
    void choose_right_direction();

    /*! \brief Устанавливает направление вращения влево */
    void choose_left_direction();

    /*! \brief Устанавливает количество штырей
     *  \param count_of_prong Новое количество штырей
     *  \return true, если значение было установлено успешно
     */
    bool set_count_of_prog(int count_of_prong);

    /*! \brief Получает количество штырей
     *  \return Текущее количество штырей
     */
    int get_count_of_prog() const;

    /*! \brief Получает направление вращения
     *  \return true для левого направления, false для правого
     */
    bool get_direction() const;

    /*! \brief Возвращает назначение стартера
     *  \return Строка, описывающая назначение стартера
     */
    std::string get_purpose() override;
};

/*! \class Battery
 *  \brief Класс для аккумулятора
 *  \details Класс предоставляет функциональность для работы с параметрами аккумулятора
 */
class Battery : public ElectroPart {
private:
    int cold_cranking_current{0};   //!< Рейтинг холодного пуска в амперах

public:
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
    bool set_cold_cranking_current(int cold_cranking_current);

    /*! \brief Получает холодный пуск
     *  \return Текущее значение холодного пуска
     */
    int get_cold_cranking_current() const;

    /*! \brief Возвращает назначение аккумулятора
     *  \return Строка, описывающая назначение аккумулятора
     */
    std::string get_purpose() override;
};

#endif //INCLUDE_ELECTRIC_DETAILS_H