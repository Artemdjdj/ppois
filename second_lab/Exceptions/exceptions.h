/*! \file exceptions.h
 *  \brief Заголовочный файл с определениями классов исключений
 *  \details Содержит иерархию классов исключений для обработки различных ошибок
 */

#ifndef INCLUDE_EXCEPTIONS_H
#define INCLUDE_EXCEPTIONS_H
#include <string>
#include <exception>
#include "../CarPart/car_part.h"

/*! \class Exception
 *  \brief Базовый класс для создания уникальных исключений
 *  \details Класс наследуется от std::exception и предоставляет базовый функционал для всех пользовательских исключений
 */
class Exception : public std::exception {
private:
	std::string message; /*!< Сообщение об ошибке */
public:
	/*! \brief Конструктор с сообщением об ошибке
	*  \param msg Текст сообщения об ошибке
	*/
	explicit Exception(const char *msg);

	/*! \brief Конструктор копирования
	*  \param other Копируемый объект исключения
	*/
	explicit Exception(const Exception &other);

	/*! \brief Получение текста ошибки
	*  \return Текст сообщения об ошибке
	*/
	const char *what() const noexcept override;
};

/*! \class ExceptionIncorrectRadius
 *  \brief Исключение при некорректном значении радиуса
 *  \details Выбрасывается при попытке установить недопустимое значение радиуса
 */
class ExceptionIncorrectRadius final : public Exception {
public:
	explicit ExceptionIncorrectRadius(const char *msg);
};

/*! \class ExceptionIncorrectColor
 *  \brief Исключение при некорректном значении цвета
 *  \details Выбрасывается при попытке установить недопустимое значение цвета
 */
class ExceptionIncorrectColor final : public Exception {
public:
	explicit ExceptionIncorrectColor(const char *msg);
};

/*! \class ExceptionIncorrectMaterial
 *  \brief Исключение при некорректном значении материала
 *  \details Выбрасывается при попытке установить недопустимый тип материала
 */
class ExceptionIncorrectMaterial final : public Exception {
public:
	explicit ExceptionIncorrectMaterial(const char *msg);
};

/*! \class ExceptionIncorrectSize
 *  \brief Базовый класс для исключений, связанных с размерами
 *  \details Используется как базовый класс для всех исключений, связанных с некорректными размерами
 */
class ExceptionIncorrectSize : public Exception {
public:
	explicit ExceptionIncorrectSize(const char *msg);
};

/*! \class ExceptionIncorrectSerialNumber
 *  \brief Исключение при некорректном серийном номере
 *  \details Выбрасывается при попытке установить недопустимый серийный номер
 */
class ExceptionIncorrectSerialNumber final : public Exception {
public:
	explicit ExceptionIncorrectSerialNumber(const char *msg);
};

/*! \class ExceptionIncorrectSeason
 *  \brief Исключение при некорректном значении сезона
 *  \details Выбрасывается при попытке установить недопустимое значение сезона
 */
class ExceptionIncorrectSeason final : public Exception {
public:
	explicit ExceptionIncorrectSeason(const char *msg);
};

/*! \class ExceptionIncorrectFuel
 *  \brief Исключение при некорректном значении топлива
 *  \details Выбрасывается при попытке использовать недопустимый тип топлива
 */
class ExceptionIncorrectFuel final : public Exception {
public:
	explicit ExceptionIncorrectFuel(const char *msg);
};

/*! \class ExceptionIncorrectProcent
 *  \brief Исключение при некорректном процентном значении
 *  \details Выбрасывается при попытке установить недопустимое процентное значение
 */
class ExceptionIncorrectProcent final : public ExceptionIncorrectSize {
public:
	explicit ExceptionIncorrectProcent(const char *msg);
};

/*! \class ExceptionIncorrectVolume
 *  \brief Исключение при некорректном значении объема
 *  \details Выбрасывается при попытке установить недопустимое значение объема
 */
class ExceptionIncorrectVolume final : public ExceptionIncorrectSize {
public:
	explicit ExceptionIncorrectVolume(const char *msg);
};

/*! \class ExceptionIncorrectLevelOil
 *  \brief Исключение при некорректном уровне масла
 *  \details Выбрасывается при попытке установить недопустимый уровень масла
 */
class ExceptionIncorrectLevelOil final : public Exception {
public:
	explicit ExceptionIncorrectLevelOil(const char *msg);
};

/*! \class ExceptionRuntimeError
 *  \brief Исключение при некорректном id
 *  \details Выбрасывается при попытке установить недопустимый id, или id не может быть сгенерирован
 */
class ExceptionRuntimeError final : public Exception {
public:
	explicit ExceptionRuntimeError(const char *msg);
};

/*! \class ExceptionWayError
 *  \brief Исключение при некорректном пути
 *  \details Выбрасывается при попытке установить некорректный путь
 */
class ExceptionWayError final : public Exception {
public:
	explicit ExceptionWayError(const char *msg);
};

#endif
