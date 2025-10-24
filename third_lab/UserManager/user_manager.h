/*! \file user_manager.h
 *  \brief Заголовочный файл с определением класса менеджера пользователей
 */
#ifndef THIRD_LAB_USER_MANAGER_H
#define THIRD_LAB_USER_MANAGER_H
#include <memory>
#include <unordered_map>
#include <vector>
#include "../User/user.h"

/*! \class UserManager
 *  \brief Класс для управления пользователями
 *  \details Предоставляет функционал для создания, аутентификации, поиска и удаления пользователей
 */
class UserManager {
public:
    /*! \brief Создание нового пользователя
     *  \param username Имя пользователя
     *  \param password Пароль
     *  \param name Имя пользователя (опционально)
     *  \return Указатель на созданного пользователя
     */
    std::shared_ptr<User> CreateUser(const std::string &username, const std::string &password,
                                     const std::string &name = "");

    /*! \brief Получение всех пользователей системы
     *  \return Вектор всех пользователей
     */
    std::vector<std::shared_ptr<User> > GetAllUsers() const;

    /*! \brief Получение пользователя по имени
     *  \param username Имя пользователя
     *  \return Указатель на пользователя или nullptr если не найден
     */
    std::shared_ptr<User> GetUser(const std::string &username);

    /*! \brief Аутентификация пользователя
     *  \param username Имя пользователя
     *  \param password Пароль
     *  \return Указатель на аутентифицированного пользователя или nullptr при неудаче
     */
    std::shared_ptr<User> AuthenticateUser(const std::string& username, const std::string& password);

    /*! \brief Удаление пользователя
     *  \param user Пользователь для удаления
     */
    void DeleteUser(const std::shared_ptr<User> &user);

    /*! \brief Проверка существования пользователя
     *  \param username Имя пользователя для проверки
     *  \return true если пользователь существует, false в противном случае
     */
    bool IsUserExist(const std::string &username) const;

    /*! \brief Получение количества пользователей в системе
     *  \return Количество пользователей
     */
    int GetCountOfUsers() const;

private:
    std::unordered_map<std::string, std::shared_ptr<User> > users_; /*!< Хранилище пользователей (имя -> пользователь) */
};
#endif //THIRD_LAB_USER_MANAGER_H