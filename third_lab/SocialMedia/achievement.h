/*! \file achievement.h
 *  \brief Заголовочный файл с определением  класса, который описывает достижения пользователя
 */
#ifndef ACHIVEMENT_H
#define ACHIVEMENT_H
#include <string>
#include <vector>
#include "../Utils/project_utils.h"

/*! \class Achievement
 *  \brief Класс для представления достижения в системе
 *  \details Наследуется от класса Info и предоставляет функционал для работы с достижениями,
 *           включая условия получения, награды и местоположение
 */
class Achievement : public Info {
public:
    /*! \brief Конструктор по умолчанию */
    Achievement() = default;

    /*! \brief Параметризованный конструктор
     *  \param name Название достижения
     *  \param info Описание достижения
     *  \param reward Награда за достижение
     *  \param city Город, связанный с достижением
     */
    Achievement(const std::string &name, const std::string &info,
                const std::string &reward, const std::string &city);

    /*! \brief Добавление условия получения достижения
     *  \param condition Условие
     */
    void AddCondition(const std::string &condition);

    /*! \brief Удаление условия по номеру
     *  \param number Номер условия
     */
    void DeleteCondition(int number);

    /*! \brief Редактирование условия
     *  \param condition Новое условие
     *  \param number Номер условия
     */
    void RefactorCondition(const std::string &condition, int number);

    /*! \brief Установка награды за достижение
     *  \param reward Награда
     */
    void SetReward(const std::string &reward);

    /*! \brief Установка города достижения
     *  \param city Город
     */
    void SetCity(const std::string &city);

    /*! \brief Получение награды за достижение
     *  \return Награда
     */
    std::string GetReward() const;

    /*! \brief Получение города, где было достижение
     *  \return Город
     */
    std::string GetCity() const;

    /*! \brief Получение всех условий достижения
     *  \return Условия
     */
    std::vector<std::string> GetConditions() const;

private:
    std::vector<std::string> conditions_; /*!<Условия для получения достижения */
    std::string reward_; /*!< Награда за выполнение достижения */
    std::string city_; /*!< Город, где было достигнуто*/
};
#endif //ACHIVEMENT_H
