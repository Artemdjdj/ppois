/*! \file valve_spring.h
 *  \brief Заголовочный файл с определением класса для клапанной пружины
 */
#ifndef INCLUDE_VALVE_SPRING_H
#define INCLUDE_VALVE_SPRING_H
#include "../CarPart/car_part.h"

/*! \class ValveSpring
 *  \brief Класс для определения параметров клапанной пружины
 *  \details Класс предоставляет возможность работы с параметрами клапанной пружины, включая сжатие и деформацию
 */
class ValveSpring:public CarPart {
public:

    /*! \brief Переопределение унаследованной функции
    *  \return Описание
    */
    std::string GetInfoAboutPart() const override {
        return"This class describes valve spring";
    }

    /*! \brief Конструктор по умолчанию */
    ValveSpring();

    /*! \brief Параметризованный конструктор
     *  \param diameter Диаметр пружины
     *  \param length Длина пружины
     *  \param count_of_coils Количество витков
     *  \param is_Compressed Состояние сжатия
     */
    ValveSpring(int diameter, int length, int count_of_coils, bool is_compressed);

    /*! \brief Установка всех параметров пружины
     *  \param diameter Новый диаметр
     *  \param length Новая длина
     *  \param count_of_coils Новое количество витков
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool SetAllParameters(int diameter, int length, int count_of_coils);

    /*! \brief Сжатие пружины */
    void Compress();

    /*! \brief Разжатие пружины */
    void DeCompress();

    /*! \brief Получение диаметра пружины
     *  \return Текущий диаметр
     */
    int GetDiameter() const;

    /*! \brief Получение количества витков
     *  \return Текущее количество витков
     */
    int GetCountOfCoils() const;

    /*! \brief Получение длины пружины
     *  \return Текущая длина
     */
    int GetLength() const;

    /*! \brief Проверка состояния сжатия
     *  \return true если пружина сжата, false в противном случае
     */
    bool CheckIsCompressed() const;

    /*! \brief Расчет расстояния между соседними витками
     *  \return Расстояние между соседними витками
     */
    double DistBetweenNeighbours() const;

private:
    int diameter_{0};         /*!< Диаметр пружины */
    int length_{0};          /*!< Длина пружины */
    int count_of_coils_{0};  /*!< Количество витков */
    bool is_compressed_{false}; /*!< Состояние сжатия */

};

#endif //INCLUDE_VALVE_SPRING_H