/*! \file place_of_working.h
 *  \brief Заголовочный файл с определением класса место работы
 */
#ifndef THIRD_LAB_PLACE_OF_WORKING_H
#define THIRD_LAB_PLACE_OF_WORKING_H
#include <string>
#include <optional>

/*! \class PlaceOfWorking
 *  \brief Класс для представления места работы пользователя
 *  \details Хранит информацию о компании, должности, местоположении и периоде работы
 */
class PlaceOfWorking {
public:
    /*! \brief Конструктор по умолчанию */
    PlaceOfWorking() = default;

    /*! \brief Параметризованный конструктор
     *  \param name_of_company Название компании
     *  \param country Страна расположения
     *  \param city Город расположения
     *  \param job_title Должность
     */
    PlaceOfWorking(const std::string &name_of_company, const std::string &country, const std::string &city,
                   const std::string &job_title);

    /*! \brief Установка названия компании
     *  \param name_of_company Название компании
     */
    void SetNameOfCompany(const std::string &name_of_company);

    /*! \brief Установка страны расположения
     *  \param country Страна расположения
     */
    void SetCountry(const std::string &country);

    /*! \brief Установка города расположения
     *  \param city Город расположения
     */
    void SetCity(const std::string &city);

    /*! \brief Установка года начала работы
     *  \param start_year Год начала работы
     */
    void SetStartYear(int start_year);

    /*! \brief Установка года окончания работы
     *  \param end_year Год окончания работы
     */
    void SetEndYear(int end_year);

    /*! \brief Установка должности
     *  \param job_title Должность
     */
    void SetJobTitle(const std::string &job_title);

    /*! \brief Получение названия компании
     *  \return Название компании
     */
    std::string GetNameOfCompany() const;

    /*! \brief Получение страны расположения
     *  \return Страна расположения
     */
    std::string GetCountry() const;

    /*! \brief Получение города расположения
     *  \return Город расположения
     */
    std::string GetCity() const;

    /*! \brief Получение года начала работы
     *  \return Год начала работы (optional)
     */
    std::optional<int> GetStartYear() const;

    /*! \brief Получение года окончания работы
     *  \return Год окончания работы (optional)
     */
    std::optional<int> GetEndYear() const;

    /*! \brief Получение должности
     *  \return Должность
     */
    std::string GetJobTitle() const;

private:
    std::string name_of_company_; /*!< Название компании */
    std::string country_; /*!< Страна расположения компании */
    std::string city_; /*!< Город расположения компании */
    int start_year_{0}; /*!< Год начала работы в компании */
    int end_year_{0}; /*!< Год окончания работы в компании */
    std::string job_title_; /*!< Должность в компании */
};
#endif //THIRD_LAB_PLACE_OF_WORKING_H