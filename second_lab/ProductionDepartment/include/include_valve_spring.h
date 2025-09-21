/*! \file include_valve_spring.h
 *  \brief Заголовочный файл с определением класса для клапанной пружины
 */
#ifndef INCLUDE_VALVE_SPRING_H
#define INCLUDE_VALVE_SPRING_H

/*! \class ValveSpring
 *  \brief Класс для определения параметров клапанной пружины
 *  \details Класс предоставляет возможность работы с параметрами клапанной пружины, включая сжатие и деформацию
 */
class ValveSpring {
private:
    int diameter{0};         /*!< Диаметр пружины */
    int length{0};          /*!< Длина пружины */
    int count_of_coils{0};  /*!< Количество витков */
    bool is_compressed{false}; /*!< Состояние сжатия */

public:
    /*! \brief Конструктор по умолчанию */
    ValveSpring();

    /*! \brief Параметризованный конструктор
     *  \param diameter Диаметр пружины
     *  \param length Длина пружины
     *  \param count_of_coils Количество витков
     *  \param is_compressed Состояние сжатия
     */
    ValveSpring(int diameter, int length, int count_of_coils, bool is_compressed);

    /*! \brief Установка всех параметров пружины
     *  \param diameter Новый диаметр
     *  \param length Новая длина
     *  \param count_of_coils Новое количество витков
     *  \return true если установка прошла успешно, false в противном случае
     */
    bool set_all_parameters(int diameter, int length, int count_of_coils);

    /*! \brief Сжатие пружины */
    void compress();

    /*! \brief Разжатие пружины */
    void decompress();

    /*! \brief Получение диаметра пружины
     *  \return Текущий диаметр
     */
    int get_diameter() const;

    /*! \brief Получение количества витков
     *  \return Текущее количество витков
     */
    int get_count_of_coils() const;

    /*! \brief Получение длины пружины
     *  \return Текущая длина
     */
    int get_length() const;

    /*! \brief Проверка состояния сжатия
     *  \return true если пружина сжата, false в противном случае
     */
    bool check_is_compressed() const;

    /*! \brief Расчет расстояния между соседними витками
     *  \return Расстояние между соседними витками
     */
    double dist_between_neighbours() const;
};

#endif //INCLUDE_VALVE_SPRING_H