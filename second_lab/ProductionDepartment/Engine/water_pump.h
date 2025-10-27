/*! \file water_pump.h
* \brief Заголовочный файл с определением класса водяного насоса
*/
#ifndef INCLUDE_WATER_PUMP_H
#define INCLUDE_WATER_PUMP_H
#include "../CarPart/car_part.h"
#include <string>

/*! \class WaterPump
* \brief Класс для определения базовых параметров водяного насоса
* \details Класс предоставляет возможность получения и изменения базовых параметров водяного насоса
*/
class WaterPump : public CarPart {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is water pump";
    }

    /*! \brief Конструктор по умолчанию
     */
    WaterPump() = default;

    /*! \brief Параметризованный конструктор
    * \param flow Начальная скорость потока
    * \param max_pressure Максимальное давление
    */
    WaterPump(int flow, int max_pressure);

    /*! \brief Запуск водяного насоса
    * \return true если запуск прошел успешно, false в противном случае
    */
    bool StartPump();

    /*! \brief Остановка водяного насоса
    */
    void StopPump();

    /*! \brief Рассчет текущей скорости потока
    * \param pressure Текущее давление
    * \return Скорость потока
    */
    int CalculateFlow(int pressure);

    /*! \brief Рассчет текущей мощности
    * \param pressure Текущее давление
    * \return Мощность
    */
    int CalculatePower(int pressure) const;

    /*! \brief Получение текущего ресурса
    * \return Ресурс
    */
    int GetResource() const;

    /*! \brief Получение текущего давления
    * \return Давление
    */
    int GetCurrentPressure() const;

    /*! \brief Получение максимального давления
    * \return Максимальное давление
    */
    int GetMaxPressure() const;

    /*! \brief Получение текущей скорости потока
    * \return Скорость потока
    */
    int GetFlowRate() const;

    /*! \brief Работает ли насос
    * \return true,  если работает, false - в противном случае
    */
    bool GetWorkingState() const;

    // Методы для работы с температурой
    /*! \brief Установка температуры работы
    * \param temperature Температура работы в градусах Цельсия
    */
    void SetOperatingTemperature(int temperature);

    /*! \brief Получение температуры работы
    * \return Температура работы в градусах Цельсия
    */
    int GetOperatingTemperature() const;

    // Методы для работы с термостатом
    /*! \brief Установка наличия термостата
    * \param is_thermostat Наличие термостата
    */
    void SetThermostat(bool is_thermostat);

    /*! \brief Проверка наличия термостата
    * \return true если есть термостат, false в противном случае
    */
    bool IsThermostat() const;

    // Методы для работы со сроком службы
    /*! \brief Установка срока службы
    * \param life_span Срок службы в часах
    */
    void SetLifeSpan(int life_span);

    /*! \brief Получение срока службы
    * \return Срок службы в часах
    */
    int GetLifeSpan() const;

    // Методы для работы с энергопотреблением
    /*! \brief Установка энергопотребления
    * \param power_consumption Энергопотребление в ваттах
    */
    void SetPowerConsumption(int power_consumption);

    /*! \brief Получение энергопотребления
    * \return Энергопотребление в ваттах
    */
    int GetPowerConsumption() const;

    // Методы для работы с производителем
    /*! \brief Установка производителя
    * \param manufacturer Производитель
    */
    void SetManufacturer(const std::string &manufacturer);

    /*! \brief Получение производителя
    * \return Производитель
    */
    const std::string &GetManufacturer() const;

    // Методы для работы с весом
    /*! \brief Установка веса
    * \param weight Вес в граммах
    */
    void SetWeight(int weight);

    /*! \brief Получение веса
    * \return Вес в граммах
    */
    int GetWeight() const;

private:
    int flow_rate_{0}; /*!< Скорость потока */;
    int max_pressure_{0}; /*!< Максимальное давление */;
    int current_pressure_{0}; /*!< Текущее давление */;
    bool is_working_{false}; /*!< Включен ли */;
    int resource_{0}; /*!< Ресурс */;
    int operating_temperature_{0}; /*!< Рабочая температура */;
    bool is_thermostat_{false}; /*!< Наличие термостата */;
    int life_span_{0}; /*!< Срок службы */;
    int power_consumption_{0}; /*!< Энергопотребление */;
    std::string manufacturer_; /*!< Производитель */;
    int weight_{0}; /*!< Вес */;
};

#endif // INCLUDE_WATER_PUMP_H
