/*! \file reaction.h
 *  \brief Заголовочный файл с определением класса реакция
 */
#ifndef REACTION_H
#define REACTION_H
#include <memory>
#include <string>
#include <unordered_set>
#include "user.h"

/*! \var const std::unordered_set<std::string> kReactions
 *  \brief Множество допустимых типов реакций
 */
const std::unordered_set<std::string> kReactions{"angry", "sadness", "love", "like"};

/*! \class Reaction
 *  \brief Класс для представления реакции на контент
 *  \details Хранит информацию о типе реакции, авторе и времени создания
 */
class Reaction {
public:
	/*! \brief Конструктор по умолчанию */
	Reaction()= default;

	/*! \brief Параметризованный конструктор
	 *  \param type_of_reaction Тип реакции (должен быть из kReactions)
	 *  \param author Автор реакции
	 */
	explicit Reaction(const std::string &type_of_reaction, const std::string &author);

	/*! \brief Установка реакции
	 *  \param type_of_reaction Тип реакции
	 *  \param author Автор реакции
	 */
	void SetReaction(std::string type_of_reaction, const std::string &author);

	/*! \brief Получение автора реакции
	 *  \return Имя автора реакции
	 */
	std::string SeeAuthor() const;

	/*! \brief Получение типа реакции
	 *  \return Тип реакции
	 */
	std::string GetReaction() const;

private:
	std::string type_of_reaction_; /*!< Тип реакции  */
	std::string date_time_; /*!< Дата и время создания реакции */
	std::string author_; /*!< Автор реакции */
};
#endif //REACTION_H