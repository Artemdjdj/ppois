/*! \file include_Mirror.h
 *  \brief Заголовочный файл с определением класса для зеркала
 */
#ifndef INCLUDE_Mirror_H
#define INCLUDE_Mirror_H
#include <string>
#include "include_basic_params.h"

/*! \class Mirror
 *  \brief Класс для определения параметров зеркала
 *  \details Класс предоставляет возможность работы с параметрами зеркала, включая тонировку
 */
class Mirror:public BasicParams {
private:
    std::string serial_number;/*!< Серийный номер */
    int thickness{0};/*!< Толщина */
    bool is_tinting{false};/*!< Наличие тонировки */

    /*! \brief Приватный метод установки серийного номера
    *  \param serial_number Новый серийный номер
    */
    void set_serial_number_private(std::string serial_number);

    /*! \brief Проверка корректности серийного номера
    *  \param serial_number Проверяемый серийный номер
    *  \return true если серийный номер корректен, false в противном случае
    */
    bool check_serial_number(const std::string &serial_number);
public:
    /*! \brief Параметризованный конструктор
    *  \param height Высота
    *  \param width Ширина
    *  \param thickness Толщина
    *  \param is_tinting Наличие тонировки
    *  \param serial_number Серийный номер
    */
    Mirror(int height, int width, int thickness, bool is_tinting, std::string serial_number);

    /*! \brief Конструктор по умолчанию */
    Mirror();

    /*! \brief Тонировка зеркала */
    void make_mirror_tinting();

    /*! \brief Установка толщины
    *  \param thickness Новая толщина
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_thickness(int thickness);

    /*! \brief Нанесение тонировки */
    void make_tinting();

    /*! \brief Очистка тонировки */
    void clear_tinting();

    /*! \brief Установка серийного номера
    *  \param serial_number Новый серийный номер
    *  \return true если установка прошла успешно, false в противном случае
    */
    bool set_serial_number(std::string serial_number);

    /*! \brief Получение серийного номера
    *  \return Серийный номер
    */
    std::string get_serial_number();

    /*! \brief Получение всей информации о зеркале
    *  \param height Текущая высота
    *  \param width Текущая ширина
    *  \param thickness Текущая толщина
    *  \param is_tinting Текущее состояние тонировки
    *  \param serial_number Текущий серийный номер
    */
    void get_information_about_mirror(int &height, int&width, int&thickness, bool&is_tinting, std::string &serial_number);
};

#endif //INCLUDE_Mirror_H