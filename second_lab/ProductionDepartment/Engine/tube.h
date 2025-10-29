/*! \file tube.h
* \brief Заголовочный файл с определением класса трубки
* \details Классы для упрощения работы
*/
#ifndef TUBE_H
#define TUBE_H
#include "../Wheel/wheel.h"
#include "../CarPart/car_part.h"
#include <string>

/*! \class Tube
* \brief Класс для определения базовых параметров трубки
* \details Класс предоставляет возможность получения и изменения базовых параметров трубки
*/
class Tube : public CarPart {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is tube";
    }

    /*! \brief Конструктор по умолчанию */
    Tube();

    /*! \brief Параметризованный конструктор
    * \param radius Начальный радиус
    * \param height Начальная длина
    */
    Tube(int radius, int height);

    /*! \brief Установка радиуса
    * \param radius Начальный радиус
    */
    void SetRadius(const BaseCircle &radius);

    /*! \brief Установка цвета
    * \param color  Начальный цвет
    */
    void SetColor(const Color &color);

    /*! \brief Установка длины
    * \param height Начальная длина
    */
    void SetHeight(int height);

    /*! \brief Установка производителя
    * \param manufacturer Производитель
    */
    void SetManufacturer(const std::string &manufacturer);

    /*! \brief Установка максимального давления
    * \param max_pressure Максимальное давление в бар
    */
    void SetMaxPressure(int max_pressure);

    /*! \brief Установка гибкости
    * \param is_flexible Гибкая ли трубка
    */
    void SetFlexibility(bool is_flexible);

    /*! \brief Установка температуры работы
    * \param temperature Температура работы в градусах Цельсия
    */
    void SetOperatingTemperature(int temperature);

    /*! \brief Установка срока службы
    * \param life_span Срок службы в часах
    */
    void SetLifespan(int life_span);

    /*! \brief Установка толщины стенки
    * \param thickness Толщина стенки в мм
    */
    void SetWallThickness(int thickness);

    /*! \brief Получение текущего радиуса
    * \return Радиус
    */
    int GetRadius() const;

    /*! \brief Получение текущего цвета
    * \return Цвет
    */
    std::string GetColor() const;

    /*! \brief Получение текущей длины
    * \return Длина
    */
    int GetHeight() const;

    /*! \brief Получение производителя
    * \return Производитель
    */
    std::string GetManufacturer() const;

    /*! \brief Получение максимального давления
    * \return Максимальное давление в бар
    */
    int GetMaxPressure() const;

    /*! \brief Проверка гибкости
    * \return true если трубка гибкая, false в противном случае
    */
    bool IsFlexible() const;

    /*! \brief Получение температуры работы
    * \return Температура работы в градусах Цельсия
    */
    int GetOperatingTemperature() const;

    /*! \brief Получение срока службы
    * \return Срок службы в часах
    */
    int GetLifespan() const;

    /*! \brief Получение толщины стенки
    * \return Толщина стенки в мм
    */
    int GetWallThickness() const;

private:
    BaseCircle radius_;/*!< Радиус трубки */;
    Color color_; /*!< Цвет трубки */;
    int height_{0};/*!<Длина трубки */;
    std::string manufacturer_; /*!< Производитель */;
    int max_pressure_{0}; /*!< Максимальное давление */;
    bool is_flexible_{false}; /*!< Гибкая ли трубка */;
    int operating_temperature_{0}; /*!< Температура работы */;
    int life_span_{0}; /*!< Срок службы */;
    int thickness_{0}; /*!< Толщина стенки */;
};
#endif //TUBE_H
