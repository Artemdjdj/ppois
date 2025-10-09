/*! \file generator_id.h
 *  \brief Заголовочный файл с определением  класса генератора id
 */
#ifndef GENERATOR_ID_H
#define GENERATOR_ID_H
#include <unordered_set>
#include <string>
#include <optional>

/*! \class GeneratorId
 *  \brief Класс для определения базовых параметров генератора id
 *  \details Класс предоставляет некоторые возможности взаимодействия с генератором
 */
class GeneratorId {
public:
	/*! \brief Конструктор по умолчанию */
	GeneratorId() = default;

	/*! \brief Генерирование нового id
	*  \param id в нем на выходе будет уникальный id, либо параметр не изменится
	*/
	void GenerateNewId(std::string &id);

	/*! \brief Функция проверяет существует ли уже такой id
	*  \param id Проверяемый id(строка)
	*  \return true если  такой id  существует, false в противном случае
	*/
	bool CheckIdIsTaken(const std::string &id) const;

	/*! \brief Функция удаляет id, если он существует
	*  \param id Удаляемый id(строка)
	*  \return true если  такой id  существует и он был успешно удален, false в противном случае
	*/
	bool DeleteId(const std::string &id);

private:
	std::unordered_set<std::string> list_of_id_{};/*!< Список существующих id*/;
};

#endif //GENERATOR_ID_H
