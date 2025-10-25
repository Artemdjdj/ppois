/*! \file validator.h
 *  \brief Заголовочный файл с определением класов, проверяющие валидность данных
 */
#ifndef THIRD_LAB_VALIDATOR_H
#define THIRD_LAB_VALIDATOR_H
#include <string>
#include <unordered_set>

/*! \class DefaultValidator
 *  \brief Базовый шаблонный класс для валидаторов
 *  \details Предоставляет интерфейс для валидации данных различных типов
 *  \tparam T Тип данных для валидации
 */
template<typename T>
class DefaultValidator {
public:
    /*! \brief Валидация значения
     *  \param value Значение
     *  \return true если значение валидно, false в противном случае
     */
    virtual bool Validate(const T &value) = 0;

    /*! \brief Виртуальный деструктор */
    virtual ~DefaultValidator() = default;
};

/*! \class ValidatorUsername
 *  \brief Валидатор для имен пользователей
 */
class ValidatorUsername final : public DefaultValidator<std::string> {
public:
    /*! \brief Валидация имени пользователя
     *  \param str Имя пользователя
     *  \return true если имя пользователя валидно, false в противном случае
     */
    bool Validate(const std::string &str) override;
};

/*! \class ValidatorName
 *  \brief Валидатор для имен
 */
class ValidatorName final : public DefaultValidator<std::string> {
public:
    /*! \brief Валидация имени
     *  \param str Имя
     *  \return true если имя валидно, false в противном случае
     */
    bool Validate(const std::string &str) override;
};

/*! \class ValidatorEmail
 *  \brief Валидатор для email адресов
 */
class ValidatorEmail final : public DefaultValidator<std::string> {
public:
    /*! \brief Валидация email адреса
     *  \param str Email
     *  \return true если email валиден, false в противном случае
     */
    bool Validate(const std::string &str) override;
};

/*! \class ValidatorPhoneNumber
 *  \brief Валидатор для номеров телефонов
 */
class ValidatorPhoneNumber final : public DefaultValidator<std::string> {
public:
    /*! \brief Валидация номера телефона
     *  \param str Номер телефона
     *  \return true если номер телефона валиден, false в противном случае
     */
    bool Validate(const std::string &str) override;
};

/*! \class ValidatorPassword
 *  \brief Валидатор для паролей
 */
class ValidatorPassword final : public DefaultValidator<std::string> {
public:
    /*! \brief Валидация пароля
     *  \param str Пароль
     *  \return true если пароль валиден, false в противном случае
     */
    bool Validate(const std::string &str) override;
};

/*! \class ValidatorHashTag
 *  \brief Валидатор для хэштегов
 */
class ValidatorHashTag final : public DefaultValidator<std::string> {
public:
    /*! \brief Валидация хэштега
     *  \param str Хэштег
     *  \return true если хэштег валиден, false в противном случае
     */
    bool Validate(const std::string &str) override;
};

/*! \class ValidatorString
 *  \brief Валидатор для строк общего назначения
 */
class ValidatorString final : public DefaultValidator<std::string> {
public:
    /*! \brief Валидация строки
     *  \param str Строка
     *  \return true если строка валидна, false в противном случае
     */
    bool Validate(const std::string &str) override;

    static bool CheckIsStatementInAllowed(const std::string &statement, const std::unordered_set<std::string> &allowed_values);
};

/*! \class ValidatorLevel
 *  \brief Валидатор для уровней
 */
class ValidatorLevel final : public DefaultValidator<int> {
public:
    /*! \brief Валидация уровня
     *  \param level Уровень
     *  \return true если уровень валиден, false в противном случае
     */
    bool Validate(const int &level) override;
};

/*! \class ValidatorCountOfPages
 *  \brief Валидатор для количества страниц
 */
class ValidatorCountOfPages final : public DefaultValidator<int> {
public:
    /*! \brief Валидация количества страниц
     *  \param count_of_pages Количество страниц
     *  \return true если количество страниц валидно, false в противном случае
     */
    bool Validate(const int &count_of_pages) override;
};

/*! \class ValidatorMaxYear
 *  \brief Валидатор для максимального года
 */
class ValidatorMaxYear final : public DefaultValidator<int> {
public:
    /*! \brief Валидация максимального года
     *  \param max_year Год
     *  \return true если год валиден, false в противном случае
     */
    bool Validate(const int &max_year) override;
};

/*! \class ValidatorReaderAge
 *  \brief Валидатор для возраста читателя
 */
class ValidatorReaderAge final : public DefaultValidator<int> {
public:
    /*! \brief Валидация возраста читателя
     *  \param age Возраст
     *  \return true если возраст валиден, false в противном случае
     */
    bool Validate(const int &age) override;
};

/*! \class ValidatorYearSong
 *  \brief Валидатор для года выпуска песни
 */
class ValidatorYearSong final : public DefaultValidator<int> {
public:
    /*! \brief Валидация года выпуска песни
     *  \param year Год
     *  \return true если год валиден, false в противном случае
     */
    bool Validate(const int &year) override;
};

/*! \class ValidatorLengthOfSong
 *  \brief Валидатор для длины песни
 */
class ValidatorLengthOfSong final : public DefaultValidator<double> {
public:
    /*! \brief Валидация длины песни
     *  \param length Длина песни
     *  \return true если длина валидна, false в противном случае
     */
    bool Validate(const double &length) override;
};

/*! \class ValidatorLengthOfFilm
 *  \brief Валидатор для длины фильма
 */
class ValidatorLengthOfFilm final : public DefaultValidator<double> {
public:
    /*! \brief Валидация длины фильма
     *  \param length Длина фильма
     *  \return true если длина валидна, false в противном случае
     */
    bool Validate(const double &length) override;
};

/*! \class ValidatorFilmCreation
 *  \brief Валидатор для года создания фильма
 */
class ValidatorFilmCreation final : public DefaultValidator<int> {
public:
    /*! \brief Валидация года создания фильма
     *  \param year Год
     *  \return true если год валиден, false в противном случае
     */
    bool Validate(const int &year) override;
};

/*! \class ValidatorWorkingYear
 *  \brief Валидатор для рабочего года
 */
class ValidatorWorkingYear final : public DefaultValidator<int> {
public:
    /*! \brief Валидация рабочего года
     *  \param year Год
     *  \return true если год валиден, false в противном случае
     */
    bool Validate(const int &year) override;
};

#endif //THIRD_LAB_VALIDATOR_H
