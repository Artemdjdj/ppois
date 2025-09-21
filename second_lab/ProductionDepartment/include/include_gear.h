/*! \file include_gear.h
 *  \brief Заголовочный файл с определением базовых класса деталей
 */
#ifndef INCLUDE_GEAR_H
#define INCLUDE_GEAR_H
#include <optional>

/*! \class Figure
 *  \brief Абстрактный класс для определения фигур
 */
class Figure {
public:
    /*! \brief Деструктор */
    virtual ~Figure() {};

    /*! \brief Чисто виртуальная функция для получения площади фигуры
	*  \return Площадь фигуры
	*/
    virtual double get_square() = 0;

    /*! \brief Чисто виртуальная функция для получения периметра фигуры
	*  \return Периметр фигуры
	*/
    virtual double get_perimeter() = 0;
};

/*! \class Triangle
 *  \brief Класс для определения фигуры треугольника
 *  \details Класс предоставляет возможность получения и изменения базовых параметров треугольника
 */
class Triangle : public Figure {
private:
    int first_side{0};/*!< Первая сторона */;
    int second_side{0};/*!< Вторая сторона */;
    int third_side{0};/*!< Третья сторона */;
public:

    /*! \brief Конструктор по умолчанию */
    Triangle();

    /*! \brief Параметризованный конструктор
	*  \param first_side Длина первой стороны
	*  \param second_side Длина второй стороны
    *  \param third_side Длина третьей стороны
	*/
    Triangle(int first_side, int second_side, int third_side);

    /*! \brief Установка всех сторон
	*  \param first_side Длина первой стороны
	*  \param second_side Длина второй стороны
    *  \param third_side Длина третьей стороны
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_sides(int first_side, int second_side, int third_side);

    /*! \brief Получение текущей длины стороны
    *  \param number_of_side Номер стороны
	*  \return Длина стороны или nullodt
	*/
    std::optional<int> get_one_of_sides(int number_of_side) const;

    double get_square() override;
    double get_perimeter() override;
};

/*! \class Circle
 *  \brief Класс для определения круга
 *  \details Класс предоставляет возможность получения и изменения базовых параметров круга
 */
class Circle : public Figure {
private:
    int radius{0};/*!< Радиус */;
public:
    /*! \brief Конструктор по умолчанию */
    Circle();

    /*! \brief Параметризованный конструктор
	*  \param radius Радиус
	*/
    Circle(int radius);

     /*! \brief Установка радиуса
	*  \param radius Радиус
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_radius(int radius);

    /*! \brief Получение текущего радиуса
	*  \return Длина радиуса
	*/
    int get_radius() const;

    double get_square() override;
    double get_perimeter() override;
};

/*! \class Detail
 *  \brief Абстрактный класс для определения базовых параметров любой детали
 *  \details Класс предоставляет возможность получения и изменения базовых параметров детали
 */
class Detail {
private:
    int thickness{0};/*!< Толщина */;
    int density{0};/*!< Плотность */;
public:
    /*! \brief Конструктор по умолчанию */
    Detail();

    /*! \brief Параметризованный конструктор
	*  \param thickness Начальная толщина
	*  \param density Начальная плотность
	*/
    Detail(int thickness, int density);

    /*! \brief Виртуальный деструктор */
    virtual ~Detail() {};

    /*! \brief Установка толщины
	*  \param thickness Толщина
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_thickness(int thickness);

    /*! \brief Получение текущей толщины
	*  \return Толщина
	*/
    int get_thickness() const;

    /*! \brief Установка плотности
	*  \param density Плотность
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_density(int density);

    /*! \brief Получение текущей плотности
	*  \return Плотность
	*/
    int get_density() const;

    /*! \brief Чисто виртуальная функция для получения массы детали
	*  \return Масса
	*/
    virtual double get_weight() =0;
};

/*! \class Prong
 *  \brief Класс для определения зубца
 *  \details Класс предоставляет возможность получения и изменения базовых параметров зубца
 */
class Prong : public Triangle, Detail {
public:
    /*! \brief Конструктор по умолчанию */
    Prong();

    /*! \brief Параметризованный конструктор
	*  \param first_side Длина первой стороны
	*  \param second_side Длина второй стороны
    *  \param third_side Длина третьей стороны
    *  \param thickness Начальная толщина
	*  \param density Начальная плотность
	*/
    Prong(int first_side, int seconde_side, int third_side, int thickness, int density);

    /*! \brief Установка всех сторон, толщины и плонтости
	*  \param first_side Длина первой стороны
	*  \param second_side Длина второй стороны
    *  \param third_side Длина третьей стороны
    *  \param thickness Толщина
    *  \param density Плотность
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_data_prong(int first_side, int second_side, int third_side, int thickness, int density);

    double get_weight() override;
};

/*! \class Rim
 *  \brief Класс для определения обода
 *  \details Класс предоставляет возможность получения и изменения базовых параметров обода
 */
class Rim: public Circle, public Detail {
public:
    /*! \brief Конструктор по умолчанию */
    Rim();

    /*! \brief Параметризованный конструктор
	*  \param radius Радиус
    *  \param thickness Толщина
    *  \param density Плотность
	*/
    Rim(int radius, int thickness, int density);

    /*! \brief Установка радиуса, толщины и плонтости
    *  \param radius Радиус
    *  \param thickness Толщина
    *  \param density Плотность
    *  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_data_rim(int radius, int thickness, int density);

    double get_weight() override;
};

#endif //INCLUDE_GEAR_H
