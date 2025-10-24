/*! \file report.h
 *  \brief Заголовочный файл с определением класса жалоба
 */
#ifndef REPORT_H
#define REPORT_H
#include "../User/user.h"

/*! \class Report
 *  \brief Класс для представления жалобы на пользователя
 *  \details Предоставляет функционал для создания жалоб, указания причины и доказательств,
 *           а также управления статусом одобрения жалобы
 */
class Report {
public:
    /*! \brief Параметризованный конструктор
     *  \param sender Отправитель жалобы
     *  \param bad_user Пользователь, на которого подается жалоба
     */
    Report(const std::string &sender, const std::string& bad_user);

    /*! \brief Установка причины жалобы
     *  \param cause Причина жалобы
     *  \param sender Отправитель, устанавливающий причину (должен быть автором жалобы)
     */
    void SetCause(const std::string &cause, const std::string &sender);

    /*! \brief Установка доказательств жалобы
     *  \param proof Доказательства жалобы
     *  \param sender Отправитель, устанавливающий доказательства (должен быть автором жалобы)
     */
    void SetProof(const std::string &proof, const std::string &sender);

    /*! \brief Одобрение жалобы */
    void Approve();

    /*! \brief Отклонение жалобы */
    void Disapprove();

    /*! \brief Получение отправителя жалобы
     *  \return Имя отправителя
     */
    std::string GetSender() const;

    /*! \brief Получение пользователя, на которого подана жалоба
     *  \return Имя пользователя, на которого подана жалоба
     */
    std::string GetBadUser() const;

    /*! \brief Проверка статуса одобрения жалобы
     *  \return true если жалоба одобрена, false в противном случае
     */
    bool IsApproved() const;

    /*! \brief Получение причины жалобы
     *  \return Причина жалобы
     */
    std::string GetCause() const;

    /*! \brief Получение доказательств жалобы
     *  \return Доказательства жалобы
     */
    std::string GetProof() const;

private:
    std::string sender_; /*!< Отправитель жалобы */
    std::string bad_user_; /*!< Пользователь, на которого подана жалоба */
    std::string cause_; /*!< Причина жалобы */
    std::string proof_; /*!< Доказательства жалобы */
    bool is_approved_{false}; /*!< Флаг одобрения жалобы */
};
#endif //REPORT_H
