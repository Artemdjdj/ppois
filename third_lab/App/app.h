/*! \file app.h
 *  \brief Заголовочный файл с определением класса приложения
 */
#ifndef THIRD_LAB_APP_H
#define THIRD_LAB_APP_H
#include "../UserManager/user_manager.h"
#include "../DataManager/data_manager.h"

/*! \class App
 *  \brief Основной класс приложения для управления пользователями и чатами
 *  \details Класс предоставляет функционал для регистрации, авторизации пользователей,
 *           управления чатами и сообщениями, а также работы с профилем пользователя
 */
class App {
public:
    /*! \brief Регистрация нового пользователя
     *  \param username Имя пользователя
     *  \param password Пароль
     *  \param name Имя пользователя (в жизни)
     */
    void RegistrateUser(const std::string &username, const std::string &password,
                        const std::string &name = "");

    /*! \brief Авторизация пользователя
     *  \param username Имя пользователя
     *  \param password Пароль
     */
    void Login(const std::string &username, const std::string &password);

    /*! \brief Выход из текущего аакаунта */
    void Logout();

    /*! \brief Удаление аккаунта текущего пользователя */
    void DeleteAccount();

    /*! \brief Создание нового чата
     *  \param second_user Второй участник чата
     */
    void CreateNewChat(const std::string &second_user);

    /*! \brief Отправка сообщения в чат
     *  \param second_user Второй участник чата
     *  \param message Сообщение для отправки
     */
    void SendMessageToChat(const std::string &second_user,
                           const std::shared_ptr<Message> &message);

    /*! \brief Получение имени чата
     *  \param user Участник чата
     *  \return Имя чата
     */
    std::string GetChatName(const std::string &user);

    /*! \brief Удаление сообщения из чата
     *  \param second_user Второй участник чата
     *  \param number_of_message Номер сообщения для удаления
     */
    void DeleteMessageFromChat(const std::string &second_user, int number_of_message);

    /*! \brief Редактирование сообщения в чате
     *  \param second_user Второй участник чата
     *  \param number_of_message Номер сообщения для редактирования
     *  \param new_message Новое сообщение
     */
    void RefactorMessageInChat(const std::string &second_user, int number_of_message,
                               const std::shared_ptr<Message> &new_message);

    /*! \brief Просмотр всей истории чата
     *  \param second_user Второй участник чата
     *  \return Все сообщения с информацией о номере, отправителе и содержимом
     */
    std::vector<std::pair<int, std::pair<std::string, std::string> > > ViewAllHistoryOfChat(
        const std::string &second_user);

    /*! \brief Получение всех чатов текущего пользователя
     *  \return Вектор всех чатов
     */
    std::vector<std::shared_ptr<Chat> > GetAllChats();

    /*! \brief Удаление чата
     *  \param user Участник чата для удаления
     */
    void DeleteChat(const std::string &user);

    /*! \brief Получение количества пользователей в системе
     *  \return Количество пользователей
     */
    int GetCountOfUsers() const;

    /*! \brief Получение username текущего пользователя
     *  \return Имя автора
     */
    std::string GetAuthor() const;

    /*! \brief Получение профиля текущего пользователя
     *  \return Указатель на профиль
     */
    Profile *GetProfile() const;

    /*! \brief Получение чата с конкретным пользователем
     *  \param user Участник чата
     *  \return Указатель на чат
     */
    std::shared_ptr<Chat> GetChat(const std::string &user);

    /*! \brief Получение текущего пользователя
     *  \return Указатель на текущего пользователя
     */
    std::shared_ptr<User> GetCurrentUser();

    /*! \brief Получение пользователя по имени
     *  \param username Имя пользователя
     *  \return Указатель на пользователя
     */
    std::shared_ptr<User> GetUser(const std::string &username);

    /*! \brief Установка местоположения пользователя
     *  \param location Местоположение
     */
    void SetLocation(const std::string &location) const;

    /*! \brief Установка биографии пользователя
     *  \param biography Биография
     */
    void SetBiography(const std::string &biography) const;

    /*! \brief Установка пола пользователя
     *  \param is_man Пол пользователя (true - мужской, false - женский)
     */
    void SetGender(const bool is_man) const;

    /*! \brief Установка возраста пользователя
     *  \param age Возраст
     */
    void SetAge(int age) const;

    /*! \brief Получение местоположения пользователя
     *  \return Местоположение
     */
    std::string GetLocation() const;

    /*! \brief Получение биографии пользователя
     *  \return Биография
     */
    std::string GetBiography() const;

    /*! \brief Получение пола пользователя
     *  \return Пол пользователя
     */
    bool GetGender() const;

    /*! \brief Получение возраста пользователя
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
    void DeleteUserFromBlackList(const std::string &user) const;

    /*! \brief Очистка черного списка */
    void DeleteAllFromBlackList() const;

    /*! \brief Получение списка заблокированных пользователей
     *  \return Имена заблокированных пользователей
     */
    std::vector<std::string> GetBlockedUsersNamesFromBlackList();

private:
    std::shared_ptr<User> user_ = nullptr; /*!< Текущий пользователь*/
    UserManager user_manager_; /*!< Менеджер пользователей */
    DataManager data_manager_; /*!< Менеджер данных */
};
#endif //THIRD_LAB_APP_H
