/*! \file piston.h
* \brief Заголовочный файл с определением базовых классов и некоторых функций класса поршень
*/
#ifndef INCLUDE_PISTON_H
#define INCLUDE_PISTON_H
#include "../CarPart/car_part.h"
#include <string>

/*! \class Piston
* \brief Класс для определения базовых параметров поршня
* \details Класс предоставляет возможность получения и изменения базовых параметров поршня
*/
class Piston : public CarPart {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is piston";
    }

    /*! \brief Конструктор по умолчанию */
    Piston() = default;

    /*! \brief Параметризованный конструктор
    * \param diameter Начальный диаметр
    * \param height Начальная высота
    * \param compression_height Начальная высота поднятия
    * \param count_of_cycles Начальное количество циклов
    * \param weight Начальная масса
    */
    Piston(int diameter, int height, int compression_height, int count_of_cycles, int weight);

    /*! \brief Установка всех параметров
    * \param diameter Начальный диаметр
    * \param height Начальная высота
    * \param compression_height Начальная высота поднятия
    * \param count_of_cycles Начальное количество циклов
    * \param weight Начальная масса
    */
    void SetAllParameters(int diameter, int height, int compression_height, int count_of_cycles, int weight);

    /*! \brief Установка производителя
    * \param manufacturer Производитель
    */
    void SetManufacturer(const std::string &manufacturer);

    /*! \brief Установка типа поршня
    * \param piston_type Тип поршня (плоский, выпуклый, вогнутый)
    */
    void SetPistonType(const std::string &piston_type);

    /*! \brief Установка диаметра пальца
    * \param pin_diameter Диаметр пальца в мм
    */
    void SetPinDiameter(int pin_diameter);

    /*! \brief Установка рабочей температуры
    * \param temperature Рабочая температура в градусах Цельсия
    */
    void SetOperatingTemperature(int temperature);

    /*! \brief Установка максимального давления
    * \param max_pressure Максимальное давление в бар
    */
    void SetMaxPressure(int max_pressure);

    /*! \brief Установка степени сжатия
    * \param compression_ratio Степень сжатия
    */
    void SetCompressionRatio(double compression_ratio);

    /*! \brief Установка количества масляных канавок
    * \param oil_grooves_count Количество масляных канавок
    */
    void SetOilGroovesCount(int oil_grooves_count);

    /*! \brief Установка наличия термостойкого покрытия
    * \param is_coating Наличие термостойкого покрытия
    */
    void SetHasThermalCoating(bool is_coating);

    /*! \brief Установка срока службы
    * \param life_span Срок службы в часах
    */
    void SetLifespan(int life_span);

    /*! \brief Установка скорости движения
    * \param speed Скорость движения в м/с
    */
    void SetSpeed(int speed);

    /*! \brief Получение текущего диаметра
    * \return Диаметр
    */
    int GetDiameter() const;

    /*! \brief Получение текущего количества циклов
    * \return Количество циклов
    */
    int GetCountOfCycles() const;

    /*! \brief Получение текущей высоты
    * \return Высота
    */
    int GetHeight() const;

    /*! \brief Получение текущей массы
    * \return Масса
    */
    int GetWeight() const;

    /*! \brief Получение высоты поднятия
    * \return Высота поднятия
    */
    int GetCompressionHeight() const;

    /*! \brief Получение производителя
    * \return Производитель
    */
    std::string GetManufacturer() const;

    /*! \brief Получение типа поршня
    * \return Тип поршня
    */
    std::string GetPistonType() const;

    /*! \brief Получение диаметра пальца
    * \return Диаметр пальца в мм
    */
    int GetPinDiameter() const;

    /*! \brief Получение рабочей температуры
    * \return Рабочая температура в градусах Цельсия
    */
    int GetOperatingTemperature() const;

    /*! \brief Получение максимального давления
    * \return Максимальное давление в бар
    */
    int GetMaxPressure() const;

    /*! \brief Получение степени сжатия
    * \return Степень сжатия
    */
    double GetCompressionRatio() const;

    /*! \brief Получение количества масляных канавок
    * \return Количество масляных канавок
    */
    int GetOilGroovesCount() const;

    /*! \brief Проверка наличия термостойкого покрытия
    * \return true если есть покрытие, false в противном случае
    */
    bool IsThermalCoating() const;

    /*! \brief Получение срока службы
    * \return Срок службы в часах
    */
    int GetLifespan() const;

    /*! \brief Получение скорости движения
    * \return Скорость движения в м/с
    */
    int GetSpeed() const;

    /*! \brief Проверка работоспособности поршня
    * \return true если износа нет, false в противном случае
    */
    bool CheckIsPistonInWorkingCondition() const;

private:
    int diameter_{0};/*!< Диаметр */;
    int height_{0};/*!< Высота */;
    int compression_height_{0};/*!< Высота поднятия */;
    int count_of_cycles_{0};/*!< Количество циклов */;
    int weight_{0};/*!< Масса */;
    std::string manufacturer_; /*!< Производитель */;
    std::string piston_type_; /*!< Тип поршня */;
    int pin_diameter_{0}; /*!< Диаметр пальца */;
    int operating_temperature_{0}; /*!< Рабочая температура */;
    int max_pressure_{0}; /*!< Максимальное давление */;
    double compression_ratio_{0}; /*!< Степень сжатия */;
    int oil_grooves_count_{0}; /*!< Количество масляных канавок */;
    bool is_coating_{false}; /*!< Наличие термостойкого покрытия */;
    int life_span_{0}; /*!< Срок службы */;
    int speed_{0}; /*!< Скорость движения */;
};
#endif //INCLUDE_PISTON_H
