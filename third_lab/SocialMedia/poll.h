/*! \file poll.h
 *  \brief Заголовочный файл с определением класса опросника
 */
#ifndef Poll_H
#define Poll_H
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <optional>
#include "../User/user.h"

/*! \class Poll
 *  \brief Класс для представления опроса в системе
 *  \details Предоставляет базовый функционал для создания опросов, добавления ответов и сбора статистики
 */
class Poll {
public:
    /*! \brief Конструктор по умолчанию */
    Poll() = default;

    /*! \brief Параметризованный конструктор
     *  \param question Вопрос опроса
     *  \param answers Варианты ответов
     *  \param user Автор опроса
     */
    Poll(const std::string &question, const std::vector<std::string> &answers, const std::string &user);

    /*! \brief Оператор сравнения опросов
     *  \param other Другой опрос для сравнения
     *  \return true если опросы идентичны, false в противном случае
     */
    bool operator==(const Poll &other) const {
        return this->question_ == other.question_ and this->answers_ == other.answers_;
    }

    /*! \brief Добавление ответа пользователя
     *  \param number_of_answer Номер выбранного ответа
     *  \param user Пользователь, добавляющий ответ
     */
    void AddAnswer(int number_of_answer, std::string user);

    /*! \brief Просмотр ответа конкретного пользователя
     *  \param user Пользователь для поиска ответа
     *  \param result Строка для сохранения результата
     */
    void SeeUserAnswer(const std::string &user, std::string &result) const;

    /*! \brief Получение ответа автора и изменение его выбора
     *  \param user Пользователь (автор)
     *  \param new_answer Новый выбранный ответ
     *  \return Старый ответ пользователя (optional)
     */
    std::optional<int> GetAuthorAndHisAnswer(const std::string &user, int new_answer);

    /*! \brief Получение вопроса опроса
     *  \return Вопрос опроса
     */
    std::string GetQuestion() const;

protected:
    std::string question_; /*!< Вопрос опроса */
    std::vector<std::string> answers_; /*!< Вектор вариантов ответов */
    std::map<std::string, int> statistics_; /*!< Статистика ответов по пользователям */
    std::vector<std::pair<std::string, int> > users_and_their_answers_; /*!< Пары пользователь-ответ */
    int result_count_of_voices_{0}; /*!< Общее количество голосов */
    std::string author_; /*!< Автор опроса */

    /*! \brief Получение ответа пользователя
     *  \param user Пользователь для поиска
     *  \return Номер ответа пользователя или -1 если не найден
     */
    int GetAnswerOfUser(const std::string &user) const;
};

/*! \class PollWithRefactoringChoose
 *  \brief Класс опроса с возможностью изменения выбора
 *  \details Наследуется от Poll и добавляет функционал изменения уже сделанного выбора
 */
class PollWithRefactoringChoose : public Poll {
public:
    /*! \brief Конструктор по умолчанию */
    PollWithRefactoringChoose() = default;

    /*! \brief Параметризованный конструктор
     *  \param question Вопрос опроса
     *  \param answers Варианты ответов
     *  \param user Автор опроса
     */
    PollWithRefactoringChoose(const std::string &question, const std::vector<std::string> &answers,
                              const std::string &user);

    /*! \brief Изменение выбора пользователя
     *  \param user Пользователь, изменяющий выбор
     *  \param new_answer Новый выбранный ответ
     */
    void RefactorYourChoose(const std::string &user, int new_answer);
};

/*! \class PollWithGettingAnswer
 *  \brief Класс опроса с правильным ответом
 *  \details Наследуется от Poll и добавляет функционал для опросов с правильным ответом
 */
class PollWithGettingAnswer : public Poll {
public:
    /*! \brief Конструктор по умолчанию */
    PollWithGettingAnswer() = default;

    /*! \brief Параметризованный конструктор
     *  \param question Вопрос опроса
     *  \param answers Варианты ответов
     *  \param number_of_correct_answer Номер правильного ответа
     *  \param user Автор опроса
     */
    PollWithGettingAnswer(const std::string &question, const std::vector<std::string> &answers,
                          int number_of_correct_answer, const std::string &user);

    /*! \brief Добавление ответа пользователя с проверкой правильности
     *  \param number_of_answer Номер выбранного ответа
     *  \param user Пользователь, добавляющий ответ
     */
    void AddAnswer(int number_of_answer, std::string user);

    /*! \brief Просмотр всех ответов
     *  \return Вектор всех ответов
     */
    std::vector<std::string> SeeAnswers() const;

private:
    int correct_answer_{}; /*!< Номер правильного ответа */
};

#endif //Poll_H
