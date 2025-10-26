/*! \file exceptions.h
 *  \brief Заголовочный файл с определениями классов исключений
 *  \details Содержит иерархию классов исключений для обработки различных ошибок
 */
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>

/*! \class Exception
 *  \brief Базовый класс для создания уникальных исключений
 *  \details Класс наследуется от std::exception (стандартный класс в C++ для обработки исключений) и предоставляет базовый функционал для всех пользовательских исключений
 */
class Exception : public std::exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст ошибки
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

private:
    std::string message_; /*!< Сообщение об ошибке */
};

/*! \class ExceptionUserName
 *  \brief Исключение для ошибок имени пользователя
 */
class ExceptionUserName final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке имени пользователя
     */
    explicit ExceptionUserName(const char *msg);
};

/*! \class ExceptionName
 *  \brief Исключение для ошибок имени
 */
class ExceptionName final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке имени
     */
    explicit ExceptionName(const char *msg);
};

/*! \class ExceptionSurName
 *  \brief Исключение для ошибок фамилии
 */
class ExceptionSurName final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке фамилии
     */
    explicit ExceptionSurName(const char *msg);
};

/*! \class ExceptionEmail
 *  \brief Исключение для ошибок email
 */
class ExceptionEmail final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке email
     */
    explicit ExceptionEmail(const char *msg);
};

/*! \class ExceptionPhoneNumber
 *  \brief Исключение для ошибок номера телефона
 */
class ExceptionPhoneNumber final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке номера телефона
     */
    explicit ExceptionPhoneNumber(const char *msg);
};

/*! \class ExceptionPassword
 *  \brief Исключение для ошибок пароля
 */
class ExceptionPassword final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке пароля
     */
    explicit ExceptionPassword(const char *msg);
};

/*! \class ExceptionIncorrectMessage
 *  \brief Исключение для некорректных сообщений
 */
class ExceptionIncorrectMessage final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректного сообщения
     */
    explicit ExceptionIncorrectMessage(const char *msg);
};

/*! \class ExceptionIncorrectNumber
 *  \brief Исключение для некорректных номеров
 */
class ExceptionIncorrectNumber final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректного номера
     */
    explicit ExceptionIncorrectNumber(const char *msg);
};

/*! \class ExceptionAccess
 *  \brief Исключение для ошибок доступа
 */
class ExceptionAccess final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке доступа
     */
    explicit ExceptionAccess(const char *msg);
};

/*! \class ExceptionUserExist
 *  \brief Исключение для случая существующего пользователя
 */
class ExceptionUserExist final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке существующего пользователя
     */
    explicit ExceptionUserExist(const char *msg);
};

/*! \class ExceptionNothingToPrint
 *  \brief Исключение для случая отсутствия данных для печати
 */
class ExceptionNothingToPrint final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке отсутствия данных для печати
     */
    explicit ExceptionNothingToPrint(const char *msg);
};

/*! \class ExceptionIncorrectReaction
 *  \brief Исключение для некорректных реакций
 */
class ExceptionIncorrectReaction final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректной реакции
     */
    explicit ExceptionIncorrectReaction(const char *msg);
};

/*! \class ExceptionIncorrectHashTag
 *  \brief Исключение для некорректных хэштегов
 */
class ExceptionIncorrectHashTag final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректного хэштега
     */
    explicit ExceptionIncorrectHashTag(const char *msg);
};

/*! \class ExceptionRuntimeError
 *  \brief Исключение для ошибок времени выполнения
 */
class ExceptionRuntimeError final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке времени выполнения
     */
    explicit ExceptionRuntimeError(const char *msg);
};

/*! \class ExceptionIncorrectRole
 *  \brief Исключение для некорректных ролей
 */
class ExceptionIncorrectRole final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректной роли
     */
    explicit ExceptionIncorrectRole(const char *msg);
};

/*! \class ExceptionIncorrectLevelOfInterest
 *  \brief Исключение для некорректных уровней интереса
 */
class ExceptionIncorrectLevelOfInterest final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректного уровня интереса
     */
    explicit ExceptionIncorrectLevelOfInterest(const char *msg);
};

/*! \class ExceptionIncorrectRegistration
 *  \brief Исключение для ошибок регистрации
 */
class ExceptionIncorrectRegistration final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке регистрации
     */
    explicit ExceptionIncorrectRegistration(const char *msg);
};

/*! \class ExceptionIncorrectAuthorization
 *  \brief Исключение для ошибок авторизации
 */
class ExceptionIncorrectAuthorization final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке авторизации
     */
    explicit ExceptionIncorrectAuthorization(const char *msg);
};

/*! \class ExceptionIncorrectYear
 *  \brief Исключение для некорректных годов
 */
class ExceptionIncorrectYear final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректного года
     */
    explicit ExceptionIncorrectYear(const char *msg);
};

/*! \class ExceptionIncorrectTime
 *  \brief Исключение для некорректного времени
 */
class ExceptionIncorrectTime final : public Exception {
public:
    /*! \brief Конструктор с сообщением
     *  \param msg Текст сообщения об ошибке некорректного времени
     */
    explicit ExceptionIncorrectTime(const char *msg);
};

#endif //EXCEPTIONS_H
