/*! \file place_of_study.h
*  \brief Заголовочный файл с определением классов, которые описывают место учебы
 */
#ifndef THIRD_LAB_PLACE_OF_STUDY_H
#define THIRD_LAB_PLACE_OF_STUDY_H
#include <string>

/*! \class PlaceStudy
 *  \brief Базовый абстрактный класс для представления места обучения
 *  \details Содержит общую информацию о месте учебы: страна, город, годы обучения и год создания учреждения
 */
class PlaceStudy {
public:
    /*! \brief Виртуальный деструктор */
    virtual ~PlaceStudy() = default;

    /*! \brief Установка страны обучения
     *  \param country Название страны
     */
    void SetCountry(const std::string &country);

    /*! \brief Установка города обучения
     *  \param city Название города
     */
    void SetCity(const std::string &city);

    /*! \brief Установка года начала обучения
     *  \param start_year Год начала обучения
     */
    void SetStartYear(int start_year);

    /*! \brief Установка года окончания обучения
     *  \param end_year Год окончания обучения
     */
    void SetEndYear(int end_year);

    /*! \brief Установка года создания учреждения
     *  \param year_of_creation Год создания учебного заведения
     */
    void SetYearCreation(int year_of_creation);

    /*! \brief Установка дополнительной информации
     *  \param info Дополнительная информация об обучении
     */
    virtual void SetInfo(const std::string &info) = 0;

    /*! \brief Получение страны обучения
     *  \return Название страны
     */
    std::string GetCountry() const;

    /*! \brief Получение города обучения
     *  \return Название города
     */
    std::string GetCity() const;

    /*! \brief Получение года начала обучения
     *  \return Год начала обучения
     */
    int GetStartYear() const;

    /*! \brief Получение года окончания обучения
     *  \return Год окончания обучения
     */
    int GetEndYear() const;

    /*! \brief Получение года создания учреждения
     *  \return Год создания учебного заведения
     */
    int GetYearOfCreation() const;

    /*! \brief Получение дополнительной информации
     *  \return Дополнительная информация об обучении
     */
    virtual std::string GetInfo() const = 0;

protected:
    std::string country_; /*!< Страна обучения */
    std::string city_; /*!< Город обучения */
    int start_year_{0}; /*!< Год начала обучения */
    int end_year_{0}; /*!< Год окончания обучения */
    int year_of_creation_{0}; /*!< Год создания учебного заведения */
    std::string info_; /*!< Дополнительная информация */
};

/*! \class University
 *  \brief Класс для представления университета
 *  \details Наследуется от PlaceStudy и хранит специфическую информацию об университетском образовании
 */
class University final : public PlaceStudy {
public:
    void SetInfo(const std::string &info) override;

    std::string GetInfo() const override;

    /*! \brief Установка названия университета
     *  \param name Название университета
     */
    void SetName(const std::string &name);

    /*! \brief Установка факультета
     *  \param faculty Название факультета
     */
    void SetFaculty(const std::string &faculty);

    /*! \brief Установка специальности
     *  \param speciality Название специальности
     */
    void SetSpeciality(const std::string &speciality);

    /*! \brief Установка учебной группы
     *  \param group Номер/название группы
     */
    void SetGroup(const std::string &group);

    /*! \brief Получение названия университета
     *  \return Название университета
     */
    std::string GetName() const;

    /*! \brief Получение названия факультета
     *  \return Название факультета
     */
    std::string GetFaculty() const;

    /*! \brief Получение специальности
     *  \return Название специальности
     */
    std::string GetSpeciality() const;

    /*! \brief Получение учебной группы
     *  \return Номер/название группы
     */
    std::string GetGroup() const;

private:
    std::string name_; /*!< Название университета */
    std::string faculty_; /*!< Факультет */
    std::string speciality_; /*!< Специальность */
    std::string group_; /*!< Учебная группа */
};

/*! \class School
 *  \brief Класс для представления школы
 *  \details Наследуется от PlaceStudy и хранит информацию о школьном образовании
 */
class School final : public PlaceStudy {
public:
    void SetInfo(const std::string &info) override;

    std::string GetInfo() const override;

    /*! \brief Установка номера школы
     *  \param number Номер школы
     */
    void SetNumber(int number);

    /*! \brief Получение номера школы
     *  \return Номер школы
     */
    int GetNumber() const;

private:
    int number_{0}; /*!< Номер школы */
};

#endif // THIRD_LAB_PLACE_OF_STUDY_H
