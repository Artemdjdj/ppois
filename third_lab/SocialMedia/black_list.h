/*! \file black_list.h
 *  \brief Заголовочный файл с определением класса, который описывает "черный" список
 */
#ifndef BLACK_LIST_H
#define BLACK_LIST_H
#include <vector>
#include <memory>
class User;

/*! \class BlackList
 *  \brief Класс для работы с "черным" списком пользователей
 *  \details Предоставляет функционал для добавления, удаления и управления пользователями в "черном" списке
 */
class BlackList {
public:
    /*! \brief Конструктор по умолчанию */
    BlackList() = default;

    /*! \brief Добавление пользователя в "черный" список
     *  \param user Имя пользователя для добавления
     */
    void AddUser(const std::string& user);

    /*! \brief Удаление пользователя из "черного" списка
     *  \param user Имя пользователя для удаления
     */
    void DeleteUser(const std::string& user);

    /*! \brief Очистка "черного" списка */
    void DeleteAll();

    /*! \brief Получение имен всех заблокированных пользователей
     *  \return Вектор имен заблокированных пользователей
     */
    std::vector<std::string> GetBlockedUsersNames();

private:
    std::vector<std::string> blocked_users_; /*!<Имена заблокированных пользователей */

    /*! \brief Получение индекса пользователя в "черном" списке
     *  \param user Имя пользователя для поиска
     *  \return Индекс пользователя в списке или -1, если не найден
     */
    int FindUserIndex(const std::string& user) const;
};
#endif //BLACK_LIST_H