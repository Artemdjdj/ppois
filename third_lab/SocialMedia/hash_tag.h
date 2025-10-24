/*! \file hash_tag.h
 *  \brief Заголовочный файл с определением класса, который описывает хэштег
 */
#ifndef HASH_TAG_H
#define HASH_TAG_H
#include <string>
#include "../User/user.h"

/*! \class HashTag
 *  \brief Класс для представления хэштега в системе
 *  \details Хранит информацию о хэштеге, включая автора и дату создания
 */
class HashTag {
public:
    /*! \brief Конструктор по умолчанию */
    HashTag();

    /*! \brief Параметризованный конструктор
     *  \param hash_tag Текст хэштега
     *  \param author Автор хэштега
     */
    explicit HashTag(const std::string &hash_tag, const std::string &author);

    /*! \brief Установка хэштега
     *  \param hash_tag Текст хэштега
     *  \param author Автор хэштега
     */
    void SetHashTag(const std::string &hash_tag, const std::string &author);

    /*! \brief Получение текста хэштега
     *  \return Текст хэштега
     */
    std::string GetHashTag() const;

    /*! \brief Получение автора хэштега
     *  \return Username автора
     */
    std::string SeeAuthor() const;

private:
    std::string hash_tag_; /*!< Текст хэштега */
    std::string date_time_; /*!<Время создания хэштега */
    std::string author_; /*!< Автор хэштега */
};

#endif //HASH_TAG_H
