/*! \file story.h
 *  \brief Заголовочный файл с определением класса история
 */
#ifndef STORY_H
#define STORY_H
#include <string>
#include <unordered_set>
#include <../User/user.h>

/*! \var const std::unordered_set<std::string> kStoriesCategories
 *  \brief Множество допустимых категорий для историй
 */
const std::unordered_set<std::string> kStoriesCategories{"default", "worth a look", "important"};

/*! \class StorySettings
 *  \brief Класс для настроек истории
 *  \details Определяет категорию и видимость истории
 */
class StorySettings {
public:
    /*! \brief Конструктор по умолчанию */
    StorySettings() = default;

    /*! \brief Параметризованный конструктор
     *  \param category Категория истории (должна быть из kStoriesCategories)
     *  \param is_public Флаг публичности истории
     */
    StorySettings(const std::string &category, bool is_public);

    /*! \brief Установка категории истории
     *  \param category Категория истории
     */
    void SetCategory(std::string category);

    /*! \brief Сделать историю публичной */
    void MakeStoryPublic();

    /*! \brief Сделать историю приватной */
    void MakeStoryPrivate();

    /*! \brief Получение категории истории
     *  \return Категория истории
     */
    std::string GetCategory() const;

    /*! \brief Получение типа видимости истории
     *  \return true если история публичная, false если приватная
     */
    bool GetTypeOfVisibility() const;

private:
    std::string category_; /*!< Категория истории */
    bool is_public_{false}; /*!< Флаг публичности истории */
};

/*! \class Story
 *  \brief Класс для представления истории в социальной сети
 *  \details Хранит информацию об истории, включая название, содержание, настройки и автора
 */
class Story {
public:
    /*! \brief Параметризованный конструктор
     *  \param name Название истории
     *  \param info Содержание истории
     *  \param settings Настройки истории
     *  \param author Автор истории
     *  \param id Уникальный id истории
     */
    Story(const std::string &name, const std::string &info, const StorySettings &settings,
          const std::string &author, const std::string &id);

    /*! \brief Установка названия истории
     *  \param name Новое название истории
     *  \param user Пользователь, изменяющий название (должен быть автором истории)
     */
    void SetName(const std::string &name, const std::string &user);

    /*! \brief Установка содержания истории
     *  \param info Новое содержание истории
     *  \param user Пользователь, изменяющий содержание (должен быть автором истории)
     */
    void SetInfo(const std::string &info, const std::string &user);

    /*! \brief Изменение видимости истории
     *  \param is_public Флаг публичности (true - публичная, false - приватная)
     *  \param user Пользователь, изменяющий видимость
     */
    void MakeVisibilityPublic(bool is_public, const std::string &user);

    /*! \brief Получение названия истории
     *  \return Название истории
     */
    std::string GetName();

    /*! \brief Получение содержания истории
     *  \return Содержание истории
     */
    std::string GetInfo();

    /*! \brief Получение категории истории
     *  \return Категория истории
     */
    std::string GetStoryCategory() const;

    /*! \brief Проверка публичности истории
     *  \return true если история публичная, false в противном случае
     */
    bool CheckIsPublic() const;

    /*! \brief Получение id истории
     *  \return Уникальный id истории
     */
    std::string GetId() const;

private:
    std::string id_; /*!< Уникальный id истории */
    std::string name_; /*!< Название истории */
    std::string info_; /*!< Содержание истории */
    StorySettings settings_; /*!< Настройки истории */
    std::string author_; /*!< Автор истории */
};

#endif //STORY_H