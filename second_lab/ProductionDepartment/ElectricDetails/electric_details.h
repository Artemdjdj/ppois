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
class ElectroPart : public CarPart {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is default electro part";
    }

    /*! \brief Конструктор по умолчанию */
    ElectroPart() = default;

    /*! \brief Конструктор с параметрами
    *  \param voltage Начальное значение напряжения, по умолчанию 0
    *  \param power Начальное значение мощности, по умолчанию 0
    *  \param current_strength Начальное значение тока, по умолчанию 0
    *  \param resistance Начальное значение сопротивления, по умолчанию 0
    *  \param temperature Начальное значение температуры, по умолчанию 0
    */
    ElectroPart(int voltage, int power, int current_strength, int resistance, int temperature);

    /*! \brief Устанавливает значение напряжения
    *  \param voltage Новое значение напряжения
    */
    void SetVoltage(int voltage);

    /*! \brief Устанавливает значение мощности
    *  \param power Новое значение мощности
    */
    void SetPower(int power);

    /*! \brief Устанавливает значение силы тока
    *  \param current_strength Новое значение тока
    */
    void SetCurrentStrength(int current_strength);

    /*! \brief Устанавливает значение сопртивления
    *  \param resistance Новое значение сопротвления
    */
    void SetResistance(int resistance);

    /*! \brief Устанавливает значение температуры
    *  \param temperature Новое значение температуры
    */
    void SetTemperature(int temperature);

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

    /*! \brief Получает значение сопротивления
    *  \return Текущее значение сопротивления
    */
    int GetResistance() const;

    /*! \brief Получает значение температуры
    *  \return Текущее значение температуры
    */
    int GetTemperature() const;

    /*! \brief Виртуальный деструктор */
    ~ElectroPart() override = default;

    /*! \brief Проверка температуры
    *  \return true -  если температура в норме,  false -  в обратном случае
    */
    virtual bool CheckIsTemperatureInNorm() const = 0;

protected:
    int voltage_{0}; //!< Значение напряжения в вольтах
    int power_{0}; //!< Значение мощности в ваттах
    int current_strength_{0}; //!< Сила тока в амперах
    int resistance_{0}; //!< Сопротивление Ом
    int temperature_{0}; //!< Температура в C
};

/*! \class Starter
 *  \brief Класс для стартера
 *  \details Класс предоставляет функциональность для работы с параметрами стартера
 */
class Starter final : public ElectroPart {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is starter";
    }

    /*! \brief Переопределение унаследованной функции от класса ElectroPart
    * \return true -  если температура в норме,  false -  в обратном случае
    */
    bool CheckIsTemperatureInNorm() const override;

    /*! \brief Конструктор по умолчанию */
    Starter() = default;

    /*! \brief Конструктор с параметрами
    *  \param voltage Начальное значение напряжения
    *  \param power Начальное значение мощности
    *  \param current_strength Начальное значение тока
    *  \param resistance Начальное значение сопротивления, по умолчанию 0
    *  \param temperature Начальное значение температуры, по умолчанию 0
    *  \param is_left_direction Начальное направление вращения
    *  \param count_of_prong Начальное количество штырей
    */
    Starter(int voltage, int power, int current_strength, int resistance, int temperature,
            bool is_left_direction, int count_of_prong);

    /*! \brief Устанавливает направление вращения вправо */
    void ChooseRightDirection();

    /*! \brief Устанавливает направление вращения влево */
    void ChooseLeftDirection();

    /*! \brief Устанавливает количество штырей
    *  \param count_of_prong Новое количество штырей
    */
    void SetCountOfProg(int count_of_prong);

    /*! \brief Получает количество штырей
    *  \return Текущее количество штырей
    */
    int GetCountOfProg() const;

    /*! \brief Получает направление вращения
    *  \return true для левого направления, false для правого
    */
    bool GetDirection() const;

private:
    bool is_left_direction_{false}; //!< Флаг направления вращения
    int count_of_prong_{0}; //!< Количество штырей/контактов
};

/*! \class Battery
 *  \brief Класс для аккумулятора
 *  \details Класс предоставляет функциональность для работы с параметрами аккумулятора
 */
class Battery final : public ElectroPart {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is battery";
    }

    /*! \brief Переопределение унаследованной функции от класса ElectroPart
    * \return true -  если температура в норме,  false -  в обратном случае
    */
    bool CheckIsTemperatureInNorm() const override;

    /*! \brief Конструктор по умолчанию */
    Battery() = default;

    /*! \brief Конструктор с параметрами
    *  \param voltage Начальное значение напряжения
    *  \param power Начальное значение мощности
    *  \param current_strength Начальное значение тока
    *  \param resistance Начальное значение сопротивления, по умолчанию 0
    *  \param temperature Начальное значение температуры, по умолчанию 0
    *  \param cold_cranking_current Начальный рейтинг холодного пуска
    */
    Battery(int voltage, int power, int current_strength, int resistance, int temperature,
            int cold_cranking_current);

    /*! \brief Устанавливает холодный пуск
    *  \param cold_cranking_current Новое значение холодного пуска
    */
    void SetColdCrankingCurrent(int cold_cranking_current);

    /*! \brief Получает холодный пуск
    *  \return Текущее значение холодного пуска
    */
    int GetColdCrankingCurrent() const;

private:
    int cold_cranking_current_{0}; //!< Рейтинг холодного пуска в амперах
};

#endif //INCLUDE_ELECTRIC_DETAILS_H
