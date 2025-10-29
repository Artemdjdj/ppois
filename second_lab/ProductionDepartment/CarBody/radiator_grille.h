/*! \file radiator_grille.h
* \brief Заголовочный файл с определением класса радиаторной решетки
*/
#ifndef INCLUDE_RADIATOR_GRILLE_H
#define INCLUDE_RADIATOR_GRILLE_H
#include "../Include/basic_params.h"
#include "../CarPart/car_part.h"

/*! \class RadiatorGrille
* \brief Класс для определения базовых параметров  радиаторной решетки
* \details Класс предоставляет возможность получения и изменения базовых параметров радиаторной решетки
*/
class RadiatorGrille : public CarPart {
public:
    /*! \brief Переопределение унаследованной функции
    * \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return "This detail name is radiator grille";
    }

    /*! \brief Конструктор по умолчанию */
    RadiatorGrille();

    /*! \brief Параметризованный конструктор
    * \param height Начальная длина
    * \param width Начальная ширина
    * \param count_of_holes Начальное количество дырок
    * \param diameter Начальный диаметр дырок
    */
    RadiatorGrille(int height, int width, int count_of_holes, int diameter);

    /*! \brief Установка размеров
    * \param height Новое значение длины
    * \param width Новое значение ширины
    */
    void SetSize(int height, int width);

    /*! \brief Установка количества дырок
    * \param count_of_holes Новое значение количества дырок
    */
    void SetCountOfHoles(int count_of_holes);

    /*! \brief Установка диаметра
    * \param diameter Новое значение диаметра
    */
    void SetDiameter(int diameter);

    /*! \brief Получение текущего количества дырок
    * \return Количество дырок
    */
    int GetCountOfHoles() const;

    /*! \brief Получение текущего диаметра
    * \return Диаметр
    */
    int GetDiameter() const;

    /*! \brief Проверка надежности решетки
    * \return true, если рещетка надежна, false  в обратном случае
    */
    bool CheckReliabilityOfGrille() const;


    /*! \brief Установка размеров
    * \param color
    */
    void SetColor(const Color& color);

    /*! \brief Установка года производства двигателя
     *  \param year_of_producing Год производства
     */
    void SetYearOfProducing(int year_of_producing);

    /*! \brief Установка наличия подсветки
    * \param is_led_lighting Наличие подсветки
    */
    void SetLedLighting(bool is_led_lighting);

    /*! \brief Установка наличия защиты от камней
    * \param is_stone_guard Наличие защиты от камней
    */
    void SetStoneGuard(bool is_stone_guard);

    /*! \brief Установка наличия усиленной защиты
    * \param is_reinforced Наличие усиленной защиты
    */
    void MakeReinforced(bool is_reinforced);

    /*! \brief Получение цвета решетки
     *  \return Цвет решетки
     */
    std::string GetColor() const;

    /*! \brief Получение года производства решетки
     *  \return Год производства
     */
    int GetYearOfProducing() const;

    /*! \brief Проверка наличия подсветки
     *  \return true если есть подсветка, false в противном случае
     */
    bool HasLedLighting() const;

    /*! \brief Проверка наличия защиты от камней
     *  \return true если есть защита от камней, false в противном случае
     */
    bool HasStoneGuard() const;

    /*! \brief Проверка наличия усиленной защиты
     *  \return true если конструкция усиленная, false в противном случае
     */
    bool IsReinforced() const;

private:
    BasicParams size_; /*!< Размеры */
    int count_of_holes_{0}; /*!< Количество отверстий */
    int diameter_of_hole_{0}; /*!< Диаметр отверстий */
    Color color_; /*!< Цвет */
    int year_of_producing_{0}; /*!< Год производства */
    bool is_led_lighting_{false}; /*!< Наличие подсветки */
    bool is_stone_guard_{false}; /*!< Наличие защиты от камней */
    bool is_reinforced_{false}; /*!< Усилена ли конструкция */
};
#endif //INCLUDE_RADIATOR_GRILLE_H
