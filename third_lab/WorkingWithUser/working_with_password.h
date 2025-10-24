/*! \file working_with_password.h
 *  \brief Заголовочный файл с определением класов, которые работают с паролем
 */
#ifndef WORKING_WITH_PASSWORD_H
#define WORKING_WITH_PASSWORD_H
#include <string>
#ifdef _WIN32
#include <windows.h>
#pragma comment(lib, "crypt32.lib")
#endif

/*! \class HidePassword
 *  \brief Класс для безопасного ввода пароля с скрытием отображения
 *  \details Предоставляет функционал для чтения пароля без отображения символов на экране
 */
class HidePassword {
public:
    /*! \brief Чтение пароля с скрытием ввода
     *  \return Введенный пароль в виде строки
     */
    static std::string ReadPassword();
};

/*! \class Hash
 *  \brief Класс для хранения хэша и соли пароля
 *  \details Содержит хэшированное значение пароля и соль, использованную при хэшировании
 */
class Hash {
public:
    /*! \brief Установка хэша пароля
     *  \param hash Хэш пароля
     */
    void SetHash(const std::string& hash);

    /*! \brief Установка соли для пароля
     *  \param salt Соль, использованная при хэшировании
     */
    void SetSalt(const std::string& salt);

    /*! \brief Получение хэша пароля
     *  \return Хэш пароля
     */
    std::string GetHash() const;

    /*! \brief Получение соли пароля
     *  \return Соль пароля
     */
    std::string GetSalt() const;

private:
    std::string hash_; /*!< Хэшированное значение пароля */
    std::string salt_; /*!< Соль, использованная при хэшировании */
};

/*! \class HashPassword
 *  \brief Класс для работы с хэшированием паролей
 *  \details Предоставляет функционал для генерации соли, хэширования паролей и проверки соответствия
 */
class HashPassword {
public:
    /*! \brief Генерация случайной соли
     *  \param length Длина соли (по умолчанию 4 байта)
     *  \return Сгенерированная соль
     */
    static std::string GenerateSalt(size_t length = 4);

    /*! \brief Хэширование введенного пароля
     *  \param password Пароль для хэширования
     *  \return Объект Hash с хэшем и солью
     */
    static Hash HashInputPassword(const std::string& password);

    /*! \brief Проверка соответствия пароля хэшу
     *  \param check_password Проверяемый пароль
     *  \param hash Объект Hash с хэшем и солью для проверки
     *  \return true если пароль соответствует хэшу, false в противном случае
     */
    static bool IsPasswordMatch(const std::string& check_password, const Hash& hash);

private:
    /*! \brief Алгоритм хэширования
     *  \param input Входные данные для хэширования
     *  \return Хэшированная строка
     */
    static std::string HashAlgorithm(const std::string& input);
};

#endif //WORKING_WITH_PASSWORD_H