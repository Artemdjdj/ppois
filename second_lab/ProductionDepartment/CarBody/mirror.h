/*! \file mirror.h
 *  \brief Заголовочный файл с определением класса для зеркала
 */
#ifndef INCLUDE_Mirror_H
#define INCLUDE_Mirror_H
#include <string>
#include "../Include/basic_params.h"
#include "../CarPart/car_part.h"

/*! \class Mirror
 *  \brief Класс для определения параметров зеркала
 *  \details Класс предоставляет возможность работы с параметрами зеркала, включая тонировку
 */
class Mirror : public CarPart, BasicParams {
public:
	/*! \brief Переопределение унаследованной функции
	* \return Описание
	*/
	std::string GetInfoAboutPart() const override {
		return "This detail name is mirror";
	}

	/*! \brief Параметризованный конструктор
	*  \param height Высота
	*  \param width Ширина
	*  \param thickness Толщина
	*  \param is_tinting Наличие тонировки
	*  \param serial_number Серийный номер
	*/
	Mirror(int height, int width, int thickness, bool is_tinting, const std::string &serial_number);

	/*! \brief Конструктор по умолчанию */
	Mirror() =default;

	/*! \brief Тонировка зеркала */
	void MakeMirrorTinting();

	/*! \brief Установка толщины
	*  \param thickness Новая толщина
	*/
	void SetThickness(int thickness);

	/*! \brief Нанесение тонировки */
	void MakeTinting();

	/*! \brief Очистка тонировки */
	void ClearTinting();

	/*! \brief Получение информации о тонировке
	*/
	bool GetIsTinting() const;

	/*! \brief Установка серийного номера
	*  \param serial_number Новый серийный номер
	*/
	void SetSerialNumber(std::string serial_number);

	/*! \brief Получение серийного номера
	*  \return Серийный номер
	*/
	std::string GetSerialNumber();

	/*! \brief Получение всей информации о зеркале
	*  \param height Текущая высота
	*  \param width Текущая ширина
	*  \param thickness Текущая толщина
	*  \param is_tinting Текущее состояние тонировки
	*  \param serial_number Текущий серийный номер
	*/
	void GetInformationAboutMirror(int &height, int &width, int &thickness, bool &is_tinting,
									std::string &serial_number) const;

private:
	/*! \brief Проверка корректности серийного номера
	*  \param serial_number Проверяемый серийный номер
	*  \return true если серийный номер корректен, false в противном случае
	*/
	bool CheckSerialNumber(const std::string &serial_number);

protected:
	std::string serial_number_; /*!< Серийный номер */
	int thickness_{0}; /*!< Толщина */
	bool is_tinting_{false}; /*!< Наличие тонировки */
};

#endif //INCLUDE_Mirror_H
