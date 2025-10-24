/*! \file post.h
 *  \brief Заголовочный файл с определением класса пост
 */
#ifndef POST_H
#define POST_H
#include <string>
#include <map>
#include <vector>
#include "hash_tag.h"
#include "reaction.h"
#include "poll.h"
#include "../User/user.h"
#include "../Utils/project_utils.h"

/*! \class Post
 *  \brief Класс для представления поста в социальной сети
 *  \details Наследуется от класса Info и предоставляет функционал для создания постов,
 *           добавления реакций, хэштегов и опросов
 */
class Post {
public:
    /*! \brief Параметризованный конструктор
     *  \param name Название поста
     *  \param info Содержание поста
     *  \param author Автор поста
     *  \param id_ Уникальный идентификатор поста
     */
    Post(const std::string &name, const std::string &info, const std::string &author, const std::string &id_);

    /*! \brief Установка названия поста
     *  \param name Новое название поста
     *  \param author Автор, изменяющий название (должен быть автором поста)
     */
    void SetName(const std::string &name, const std::string &author);

    /*! \brief Установка содержания поста
     *  \param info Новое содержание поста
     *  \param author Автор, изменяющий содержание (должен быть автором поста)
     */
    void SetInfo(const std::string &info, const std::string &author);

    /*! \brief Получение названия поста
     *  \return Название поста
     */
    std::string GetName() const;

    /*! \brief Получение содержания поста
     *  \return Содержание поста
     */
    std::string GetInfo() const;

    /*! \brief Получение идентификатора поста
     *  \return Уникальный идентификатор поста
     */
    std::string GetId() const;

    /*! \brief Добавление реакции к посту
     *  \param reaction Реакция для добавления
     */
    void AddReaction(const std::shared_ptr<Reaction> &reaction);

    /*! \brief Удаление реакции пользователя
     *  \param username Имя пользователя, чью реакцию нужно удалить
     */
    void RemoveReaction(const std::string &username);

    /*! \brief Просмотр реакции конкретного автора
     *  \param username Имя автора для поиска реакции
     *  \return Указатель на реакцию автора
     */
    std::shared_ptr<Reaction> SeeReactionByAuthor(const std::string &username) const;

    /*! \brief Добавление хэштега к посту
     *  \param hash_tag Хэштег для добавления
     */
    void AddHashTag(const std::shared_ptr<HashTag> &hash_tag);

    /*! \brief Удаление хэштега из поста
     *  \param hash_tag Текст хэштега для удаления
     *  \param author Автор, удаляющий хэштег (должен быть автором поста)
     */
    void RemoveHashTag(const std::string &hash_tag, const std::string &author);

    /*! \brief Добавление опроса к посту
     *  \param poll Опрос для добавления
     *  \param author Автор, добавляющий опрос (должен быть автором поста)
     */
    void AddPoll(const std::shared_ptr<Poll> &poll, const  std::string &author);

    /*! \brief Удаление опроса из поста
     *  \param question Вопрос опроса для удаления
     *  \param author Автор, удаляющий опрос (должен быть автором поста)
     */
    void RemovePoll(const std::string &question, const std::string &author);

private:
    std::string id_; /*!< Уникальный идентификатор поста */
    std::string name_; /*!< Название поста */
    std::string info_; /*!< Содержание поста */
    std::map<std::string, std::shared_ptr<Reaction>> reactions_; /*!< Карта реакций (имя пользователя -> реакция) */
    std::vector<std::shared_ptr<HashTag>> hash_tags_; /*!< Вектор хэштегов поста */
    std::vector<std::shared_ptr<Poll>> polls_; /*!< Вектор опросов поста */
    std::string author_; /*!< Автор поста */

    /*! \brief Проверка использования хэштега в посте
     *  \param check_hash_tag Хэштег для проверки
     *  \return Индекс хэштега в векторе или -1 если не найден
     */
    int CheckHashTagUsed(const std::string &check_hash_tag) const;

    /*! \brief Проверка использования опроса по вопросу
     *  \param check_question Вопрос опроса для проверки
     *  \return Индекс опроса в векторе или -1 если не найден
     */
    int CheckPollUsed(const std::string &check_question) const;

    /*! \brief Проверка использования опроса в списке
     *  \param check_poll Опрос для проверки
     *  \return true если опрос уже используется, false в противном случае
     */
    bool CheckPollUsedInList(const std::shared_ptr<Poll> &check_poll) const;
};

#endif //POST_H