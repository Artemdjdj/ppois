/*! \file chat.h
 *  \brief Заголовочный файл с определением классов, необходимых для реализации обмена сообщениями между пользователями
 */
#ifndef CHAT_H
#define CHAT_H
#include <string>
#include <utility>
#include <vector>
#include <map>
#include "../SocialMedia/reaction.h"
#include "../User/user.h"

/*! \class Message
 *  \brief Класс для представления сообщения в чате
 *  \details Класс хранит информацию о сообщении, его авторе и статусе редактирования(изменен ли)
 */
class Message {
public:
    /*! \brief Конструктор по умолчанию */
    Message();

    /*! \brief Параметризованный конструктор
     *  \param message Текст сообщения
     *  \param user Автор сообщения
     */
    Message(const std::string &message, const std::string &user);

    /*! \brief Создание сообщения
     *  \param message Текст сообщения
     *  \param user Автор сообщения
     */
    void CreateMessage(const std::string &message, const std::string &user);

    /*! \brief Редактирование сообщения
     *  \param message Новый текст сообщения
     */
    void RefactorMessage(const std::string &message);

    /*! \brief Добавление реакции на сообщения
     *  \param reaction  Реакция
     */
    void AddReaction(const std::shared_ptr<Reaction> &reaction);

    /*! \brief Получение реакции
     *  \param author Автор реакции
     *  \return  Реакция
     */
    std::shared_ptr<Reaction> GetReaction(const std::string &author);

    /*! \brief Удаление реакции
     *  \param author Автор реакции
     */
    void DeleteReaction(const std::string &author);

    /*! \brief Получение автора сообщения
     *  \return Имя автора
     */
    std::string GetAuthor() const;

    /*! \brief Получение полной информации о сообщении
     *  \return Строка с текстом сообщением и датой его создания или изменения
     */
    std::string GetMessageDefault() const;

    /*! \brief Получение текста сообщения
     *  \return Текст сообщения
     */
    std::string GetMessageDefaultText() const;

private:
    std::pair<std::string, std::string> message_; /*!< Текст сообщения и времея его создания или изменения */
    std::map<std::string, std::shared_ptr<Reaction> > reactions_; /*!< Реакции */
    bool is_refactor_{false}; /*!< редактировано ли сообщение */
    std::string author_; /*!< Автор сообщения */
};

/*! \class BaseChat
 *  \brief Базовый класс для чатов
 *  \details Предоставляет базовый функционал для работы с сообщениями в чате
 */
class BaseChat {
public:
    /*! \brief Конструктор по умолчанию */
    BaseChat() = default;

    /*! \brief Виртуальный деструктор */
    virtual ~BaseChat() = default;

    /*! \brief Удаленный конструктор копирования */
    BaseChat(const BaseChat &) = delete;

    /*! \brief Отправка сообщения в чат
     *  \param message Сообщение для добавления
     */
    void WriteMessage(const std::shared_ptr<Message> &message);

    /*! \brief Редактирование сообщения
     *  \param message Новый текст сообщения
     *  \param number_of_message Номер сообщения для редактирования
     *  \param user Пользователь, редактирующий сообщение (владелец)
     */
    void RefactorMessage(const std::string &message, int number_of_message, const std::string &user);

    /*! \brief Удаление сообщения
     *  \param number_of_message Номер сообщения для удаления
     *  \param user Пользователь, удаляющий сообщение (владелец)
     */
    void DeleteMessage(int number_of_message, const std::string &user);

    /*! \brief Копирование сообщения
     *  \param number_of_message Номер сообщения для копирования
     *  \param copy_message Строка для сохранения скопированного сообщения
     */
    void CopyMessage(int number_of_message, std::string &copy_message) const;

    /*! \brief Удаление всех сообщений */
    void DeleteAllMessages();

    /*! \brief Получение количества сообщений в чате
     *  \return Количество сообщений
     */
    int CountMessages() const;

    /*! \brief Получение всех сообщений чата
     *  \return Все сообщения
     */
    std::vector<std::shared_ptr<Message> > GetAllMessages() const;

    /*! \brief Получение сообщения по номеру
     *  \param number Номер сообщения
     *  \return Указатель на сообщение
     */
    std::shared_ptr<Message> GetMessageByNumber(int number);

    /*! \brief Получение списка участников чата
     *  \return Вектор имен участников
     */
    virtual std::vector<std::string> ListMembers() = 0;

protected:
    /*! \brief Изменение сообщения (вспомогательный метод)
     *  \param number_of_message Номер сообщения
     *  \param sender_user Пользователь, изменяющий сообщение
     *  \param is_delete Удалять или редактировать сообщение (true - удаление, false - редактирование)
     *  \param message Новый текст сообщения (при редактировании)
     */
    void ChangeMessage(int number_of_message, const std::string &sender_user, bool is_delete,
                       const std::string &message);

    std::vector<std::shared_ptr<Message> > messages_; /*!< Вектор сообщений чата */
};

/*! \class Chat
 *  \brief Класс для представления чата между двумя пользователями
 *  \details Наследуется от BaseChat и реализует функционал чата между двумя пользователями
 */
class Chat final : public BaseChat {
public:
    /*! \brief Конструктор по умолчанию */
    Chat() = default;

    /*! \brief Параметризованный конструктор
     *  \param first_user Первый участник чата
     *  \param second_user Второй участник чата
     */
    Chat(const std::string &first_user, const std::string &second_user);

    /*! \brief Получение первого участника чата
     *  \return Имя первого участника
     */
    std::string GetFirstMember() const;

    /*! \brief Получение второго участника чата
     *  \return Имя второго участника
     */
    std::string GetSecondMember() const;

    /*! \brief Получение списка участников чата
     *  \return Usernames участников
     */
    std::vector<std::string> ListMembers() override;

private:
    std::pair<std::string, std::string> users_; /*!< Участники чата (количество:2) */
};

#endif //CHAT_H
