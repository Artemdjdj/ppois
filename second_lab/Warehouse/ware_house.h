/*! \file ware_house.h
* \brief Заголовочный файл с определением класса склада
*/
#ifndef WARE_HOUSE_H
#define WARE_HOUSE_H
#include "../ProductionDepartment/CarPart/car_part.h"
#include "../GeneratorId/generator_id.h"
#include <string>
#include <optional>
#include <map>
#include <vector>

/*! \class WareHouse
* \brief Класс для определения базовых параметров склада
* \details Класс предоставляет возможность получения и изменения базовых параметров склада
*/
class WareHouse {
public:
    /*! \brief Конструктор по умолчанию */
    WareHouse() = default;

    /*! \brief Добавление новой детали на склад
    * \param new_detail Новая деталь
    * \param id получаем id, под которым будет записана деталь
    */
    void AddNewDetail(CarPart *new_detail, std::string &id);

    /*! \brief Удаление детали со склада
    * \param id id детали
    * \return true если удаление прошло успешно, false в противном случае
    */
    bool DeleteDetailById(const std::string &id);

    /*! \brief Поиск детали на складе
    * \param id id детали
    * \param detail деталь в которую получаем данные
    * \return true если деталь существует с таким id, false в противном случае
    */
    bool FindDetailById(const std::string &id, CarPart *&detail);

    /*! \brief Получение всех id и деталей
    * \return Контейнер (id, деталь)
    */
    std::map<std::string, CarPart *> GetWareHouse();

    /*! \brief Получение всех деталей
    * \return Список деталей
    */
    std::vector<CarPart *> GetAllDetails() const;

    /*! \brief Очистка склада */
    void DeleteAllDetails();

private:
    std::map<std::string, CarPart *> warehouse_;/*!< Склад */;
    GeneratorId generated_id_; /*!< Генератор */;
};


#endif //WARE_HOUSE_H
