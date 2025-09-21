/*! \file include_radiator_grille.h
 *  \brief Заголовочный файл с определением класса радиаторной решетки
 */
#ifndef INCLUDE_RADIATOR_GRILLE_H
#define INCLUDE_RADIATOR_GRILLE_H
#include "include_basic_params.h"

/*! \class RadiatorGrille
 *  \brief Класс для определения базовых параметров  радиаторной решетки
 *  \details Класс предоставляет возможность получения и изменения базовых параметров радиаторной решетки
 */
class RadiatorGrille {
private:
    BasicParams size; /*!< Размеры */;
    int count_of_holes{0};/*!< Количество отверстий */;
    int diameter_of_hole{0};/*!< диаметр отверстий */;
public:

    /*! \brief Конструктор по умолчанию */
    RadiatorGrille();

    /*! \brief Параметризованный конструктор
	*  \param height Начальная длина
	*  \param width Начальная ширина
    *  \param count_of_holes Начальное количество дырок
	*  \param diameter Начальный диаметр дырок
	*/
    RadiatorGrille(int height, int width, int count_of_holes, int diameter);

    /*! \brief Установка размеров
	*  \param height Новое значение длины
    *  \param width Новое значение ширины
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_size(int height, int width);

    /*! \brief Установка количества дырок
	*  \param count_of_holes Новое значение количества дырок
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_count_of_holes(int count_of_holes);

    /*! \brief Установка диаметра
	*  \param diameter Новое значение диаметра
	*  \return true если установка прошла успешно, false в противном случае
	*/
    bool set_diameter(int diameter);

    /*! \brief Получение текущего количества дырок
	*  \return Количество дырок
	*/
    int get_count_of_holes() const;

    /*! \brief Получение текущего диаметра
	*  \return Диаметр
	*/
    int get_diameter() const;

    /*! \brief Проверка надежности решетки
	*  \return true, если рещетка надежна, false  в обратном случае
	*/
    bool check_reliability_of_grille() const;
};
#endif //INCLUDE_RADIATOR_GRILLE_H
