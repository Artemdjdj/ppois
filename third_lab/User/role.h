/*! \file role.h
 *  \brief Заголовочный файл с определением класса роль
 */
#ifndef ROLE_H
#define ROLE_H
#include <string>
#include <unordered_set>

/*! \var const std::unordered_set<std::string> kAloudRoles
 *  \brief Множество допустимых ролей в системе
 */
const std::unordered_set<std::string> kAloudRoles{"admin", "user"};

/*! \class Role
 *  \brief Класс для представления роли пользователя в системе
 *  \details Определяет роль пользователя и предоставляет методы для управления ею
 */
class Role {
public:
	/*! \brief Конструктор по умолчанию */
	Role();

	/*! \brief Параметризованный конструктор
	 *  \param name_of_role Название роли (должно быть из kAloudRoles)
	 */
	explicit Role(const std::string &name_of_role);

	/*! \brief Выбор роли пользователя
	 *  \param name_of_role Название роли для установки
	 */
	void ChooseRole(const std::string &name_of_role);

	/*! \brief Получение текущей роли пользователя
	 *  \return Название роли
	 */
	std::string GetRole() const;

private:
	std::string name_of_role_; /*!< Название текущей роли пользователя */
};
#endif //ROLE_H