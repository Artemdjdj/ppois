/*! \file data_manager.h
*   \brief Заголовочный файл с определением классов, необходимых для управления чатами и другими объектами, например историями
 */
#ifndef THIRD_LAB_DATA_MANAGER_H
#define THIRD_LAB_DATA_MANAGER_H
#include <vector>
#include <memory>
#include <unordered_map>
#include <stdexcept>
#include "../Communication/chat.h"
#include "../Generator/generator.h"
#include "../SocialMedia/story.h"
#include "../SocialMedia/post.h"

/*! \class DataManager
 *  \brief Класс для управления данными приложения
 *  \details Обеспечивает хранение и управление чатами, историями и постами пользователей
 */
class DataManager {
public:
    /*! \brief Создание нового чата
     *  \param user1 Первый участник чата
     *  \param user2 Второй участник чата
     */
    void CreateNewChat(const std::string &user1, const std::string &user2);

    /*! \brief Получение всех чатов пользователя
     *  \param user Имя пользователя
     *  \return Все чаты пользователя
     */
    std::vector<std::shared_ptr<Chat> > GetAllChats(const std::string &user);

    /*! \brief Получение чата между двумя пользователями
     *  \param user1 Первый участник чата
     *  \param user2 Второй участник чата
     *  \return Указатель на чат
     */
    std::shared_ptr<Chat> GetChat(const std::string &user1, const std::string &user2);

    /*! \brief Проверка существования чата
     *  \param user1 Первый участник чата
     *  \param user2 Второй участник чата
     *  \return true если чат существует, false в противном случае
     */
    bool IsChatExist(const std::string &user1, const std::string &user2);

    /*! \brief Отправка сообщения в чат
     *  \param user1 Первый участник чата
     *  \param user2 Второй участник чата
     *  \param message Сообщение для отправки
     */
    void SendMessageToChat(const std::string &user1, const std::string &user2, const std::shared_ptr<Message> &message);

    /*! \brief Удаление чата
     *  \param user1 Первый участник чата
     *  \param user2 Второй участник чата
     */
    void DeleteChat(const std::string &user1, const std::string &user2);

    /*! \brief Создание новой истории
     *  \param name Название истории
     *  \param info  Информация, о чем история
     *  \param settings Настройки истории
     *  \param user Автор истории
     */
    void CreateNewStory(const std::string &name, const std::string &info, const StorySettings &settings,
                        const std::string &user);

    /*! \brief Получение всех историй пользователя
     *  \param user Имя пользователя
     *  \return Все истории пользователя
     */
    std::vector<std::shared_ptr<Story> > GetAllStories(const std::string &user);

    /*! \brief Получение конкретной истории
     *  \param user Имя пользователя
     *  \param id ID истории
     *  \return Указатель на историю
     */
    std::shared_ptr<Story> GetStory(const std::string &user, const std::string &id);

    /*! \brief Удаление истории
     *  \param user Имя пользователя
     *  \param id ID истории
     */
    void DeleteStory(const std::string &user, const std::string &id);

private:
    GeneratorId stories_generator_id_; /*!< Генератор идентификаторов для историй */
    std::unordered_map<std::string, std::vector<std::shared_ptr<Chat> > > chats_;
    /*!< Хранилище чатов по пользователям */
    std::unordered_map<std::string, std::vector<std::shared_ptr<Story> > > stories_;
    /*!< Хранилище историй по пользователям */
    std::unordered_map<std::string, std::vector<std::shared_ptr<Post> > > posts_;
    /*!< Хранилище постов по пользователям */

    /*! \brief Получение номера истории в списке пользователя
     *  \param user Имя пользователя
     *  \param id ID истории
     *  \return Номер истории в списке
     */
    int GetNumberOfStory(const std::string &user, const std::string &id);

    /*! \brief Получение номера поста в списке пользователя
     *  \param user Имя пользователя
     *  \param id ID поста
     *  \return Номер поста в списке
     */
    int GetNumberOfPost(const std::string &user, const std::string &id);
};

#endif //THIRD_LAB_DATA_MANAGER_H
