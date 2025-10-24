/*! \file user.h
 *  \brief Заголовочный файл с определением классов пользователь и профиль
 */
#ifndef USER_H
#define USER_H
#include <string>
#include <memory>
#include "role.h"
#include "../WorkingWithUser/working_with_password.h"
#include "../SocialMedia/black_list.h"
#include "../Utils/validator.h"

/*! \class Profile
 *  \brief Класс для представления профиля пользователя
 *  \details Хранит персональную информацию пользователя и управляет черным списком
 */
class Profile {
public:
    /*! \brief Параметризованный конструктор
     *  \param username Имя пользователя
     *  \param location Местоположение (опционально)
     *  \param biography Биография (опционально)
     */
    explicit Profile(const std::string &username, const std::string &location = "", const std::string &biography = "");

    /*! \brief Установка местоположения
     *  \param location Местоположение
     */
    void SetLocation(const std::string &location);

    /*! \brief Установка биографии
     *  \param biography Биография
     */
    void SetBiography(const std::string &biography);

    /*! \brief Установка пола пользователя
     *  \param is_man Пол пользователя (true - мужской, false - женский)
     */
    void SetGender(const bool is_man);

    /*! \brief Установка возраста пользователя
     *  \param age Возраст
     */
    void SetAge(int age);

    /*! \brief Получение пола пользователя
     *  \return Пол пользователя
     */
    bool GetGender() const;

    /*! \brief Получение местоположения
     *  \return Местоположение
     */
    std::string GetLocation() const;

    /*! \brief Получение биографии
     *  \return Биография
     */
    std::string GetBiography() const;

    /*! \brief Получение возраста
     *  \return Возраст
     */
    int GetAge() const;

    /*! \brief Добавление пользователя в черный список
     *  \param user Пользователь для добавления в черный список
     */
    void AddUserToBlackList(const std::string &user);

    /*! \brief Удаление пользователя из черного списка
     *  \param user Пользователь для удаления из черного списка
     */
    void DeleteUserFromBlackList(const std::string &user);

    /*! \brief Очистка черного списка */
    void DeleteAllFromBlackList();

    /*! \brief Получение имен всех заблокированных пользователей
     *  \return Вектор имен заблокированных пользователей
     */
    std::vector<std::string> GetBlockedUsersNamesFromBlackList();

private:
    std::string username_; /*!< Имя пользователя */
    std::string location_; /*!< Местоположение пользователя */
    std::string biography_; /*!< Биография пользователя */
    bool is_man_; /*!< Пол пользователя */
    std::string birthday_; /*!< Дата рождения пользователя */
    std::string marital_status_; /*!< Семейное положение пользователя */
    BlackList black_list_; /*!< Черный список пользователя */
    int age_; /*!< Возраст пользователя */
};

/*! \class User
 *  \brief Класс для представления пользователя системы
 *  \details Хранит основную информацию о пользователе, включая учетные данные и профиль
 */
class User {
public:
    /*! \brief Параметризованный конструктор
     *  \param username Имя пользователя
     *  \param password Пароль
     *  \param name Имя пользователя (опционально)
     */
    User(const std::string &username, const std::string &password, const std::string &name = "");

    /*! \brief Конструктор копирования
     *  \param other Другой пользователь для копирования
     */
    User(const User &other);

    /*! \brief Оператор сравнения пользователей
     *  \param other Другой пользователь для сравнения
     *  \return true если пользователи идентичны, false в противном случае
     */
    bool operator==(const User &other) const;

    /*! \brief Оператор неравенства пользователей
     *  \param other Другой пользователь для сравнения
     *  \return true если пользователи различаются, false в противном случае
     */
    bool operator!=(const User &other) const;

    /*! \brief Установка имени пользователя
     *  \param username Имя пользователя
     */
    void SetUserName(const std::string &username);

    /*! \brief Установка имени
     *  \param name Имя
     */
    void SetName(const std::string &name);

    /*! \brief Установка фамилии
     *  \param surname Фамилия
     */
    void SetSurname(const std::string &surname);

    /*! \brief Установка email
     *  \param email Email адрес
     */
    void SetEmail(const std::string &email);

    /*! \brief Установка номера телефона
     *  \param phone_number Номер телефона
     */
    void SetPhoneNumber(const std::string &phone_number);

    /*! \brief Установка пароля
     *  \param password Пароль
     */
    void SetPassword(const std::string &password);

    /*! \brief Установка роли пользователя
     *  \param role Роль пользователя
     */
    void SetRole(const Role &role);

    /*! \brief Создание профиля пользователя */
    void CreateProfile();

    /*! \brief Получение имени пользователя
     *  \return Имя пользователя
     */
    std::string GetUsername() const;

    /*! \brief Получение имени
     *  \return Имя
     */
    std::string GetName() const;

    /*! \brief Получение фамилии
     *  \return Фамилия
     */
    std::string GetSurName() const;

    /*! \brief Получение email
     *  \return Email адрес
     */
    std::string GetEmail() const;

    /*! \brief Получение номера телефона
     *  \return Номер телефона
     */
    std::string GetPhoneNumber() const;

    /*! \brief Получение профиля пользователя
     *  \return Ссылка на уникальный указатель профиля
     */
    const std::unique_ptr<Profile> &GetProfile() const;

    /*! \brief Получение роли пользователя
     *  \return Роль пользователя
     */
    std::string GetRole() const;

    /*! \brief Получение хэша пароля
     *  \return Хэш пароля
     */
    Hash GetPassword() const;

private:
    std::string username_; /*!< Имя пользователя */
    std::string name_; /*!< Имя */
    std::string surname_; /*!< Фамилия */
    std::string email_; /*!< Email адрес */
    std::string phone_number_; /*!< Номер телефона */
    Hash password_; /*!< Хэш пароля */
    Role role_; /*!< Роль пользователя */
    std::unique_ptr<Profile> profile_; /*!< Уникальный указатель на профиль пользователя */
};

#endif //USER_H
