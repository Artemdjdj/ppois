
#ifndef GENERATOR_H
#define GENERATOR_H
#include <string>
#include <unordered_set>
constexpr int kLengthOfId = 5;
constexpr int kMaxCountOfAttempts = 100000;

/*! \class GeneratorId
	 * \brief Класс для определения базовых параметров генератора id
	 * \details Класс предоставляет некоторые возможности взаимодействия с генератором
	 */
class GeneratorId {
public:
	/*! \brief Конструктор по умолчанию */
	GeneratorId() = default;

	/*! \brief Генерирование нового id
	* \param id в нем на выходе будет уникальный id, либо параметр не изменится
	* \return true если генерация прошла успешно, false в противном случае
	*/
	void GenerateNewId(std::string &id);

	/*! \brief Функция проверяет существует ли уже такой id
	* \param id Проверяемый id(строка)
	* \return true если  такой id  существует, false в противном случае
	*/
	bool CheckIdIsTaken(const std::string& id) const;

	/*! \brief Функция удаляет id, если он существует
	* \param id Удаляемый id(строка)
	* \return true если  такой id  существует и он был успешно удален, false в противном случае
	*/
	bool DeleteId(const std::string &id);

private:
	std::unordered_set<std::string> list_of_id_{};/*!< Список существующих id*/;
};
#endif //GENERATOR_H
