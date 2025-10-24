/*! \file notification.h
 *  \brief Заголовочный файл с определением класса уведомления
 */
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include "../User/user.h"
#include "../Utils/project_utils.h"

/*! \class Notification
 *  \brief Класс для представления уведомления в системе
 *  \details Наследуется от класса Info и предоставляет функционал для работы с уведомлениями,
 *           включая отправителя, получателя и статус отображения
 */
class Notification final : public Info {
public:
    /*! \brief Параметризованный конструктор
     *  \param name Название уведомления
     *  \param info Текст уведомления
     *  \param sender Отправитель уведомления
     *  \param receiver Получатель уведомления
     */
    Notification(const std::string &name, const std::string &info, const std::string &sender, const std::string &receiver);

    /*! \brief Показать уведомление */
    void ShowNotification();

    /*! \brief Скрыть уведомление */
    void DoNotShowNotification();

    /*! \brief Получение времени создания уведомления
     *  \return Время создания
     */
    std::string GetTime() const;

    /*! \brief Получение отправителя уведомления
     *  \return Имя отправителя
     */
    std::string GetSender() const;

    /*! \brief Получение получателя уведомления
     *  \return Имя получателя
     */
    std::string GetReceiver() const;

    /*! \brief Проверка, отображается ли уведомление
     *  \return true если уведомление отображается, false в противном случае
     */
    bool IsShow() const;

private:
    std::string sender_; /*!< Отправитель уведомления */
    std::string receiver_; /*!< Получатель уведомления */
    std::string time_; /*!< Время создания уведомления */
    bool is_show_{true}; /*!< Флаг отображения уведомления */
};
#endif //NOTIFICATION_H