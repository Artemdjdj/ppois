/*! \file interest.h
 *  \brief Заголовочный файл с определением классов, которые описывают интересы пользователя, например книга, песня и тд
 */
#ifndef INTEREST_H
#define INTEREST_H
#include <string>
#include <vector>
#include <optional>
#include "../Utils/project_utils.h"

/*! \class Interest
 *  \brief Класс для представления интереса пользователя
 *  \details Наследуется от класса Info и хранит информацию об интересе
 */
class Interest final : public Info {
public:
    /*! \brief Конструктор по умолчанию */
    Interest() = default;

    /*! \brief Параметризованный конструктор
     *  \param name Название интереса
     *  \param info Описание интереса
     *  \param duration Продолжительность занятия
     *  \param level Уровень интереса (увлеченность)
     */
    Interest(const std::string &name, const std::string &info, const std::string &duration, int level);

    /*! \brief Установка продолжительности занятия
     *  \param duration Продолжительность времени
     */
    void SetDuration(const std::string &duration);

    /*! \brief Получение продолжительности занятия
     *  \return Продолжительность
     */
    std::string GetDuration();

    /*! \brief Установка уровня интереса
     *  \param level Уровень интереса
     */
    void SetLevel(int level);

    /*! \brief Получение уровня интереса
     *  \return Уровень интереса
     */
    int GetLevel() const;

private:
    std::string duration_; /*!< Продолжительность занятия интереса */
    int level_{0}; /*!< Уровень интереса (1-10) */
};

/*! \class Book
 *  \brief Класс для представления книги
 *  \details Хранит информацию о книге: название, жанр, авторы, год издания и т.д.
 */
class Book {
public:
    /*! \brief Конструктор по умолчанию */
    Book() = default;

    /*! \brief Параметризованный конструктор
     *  \param title Название книги
     *  \param genre Жанр книги
     *  \param reader_age Минимально-допустимый возраст для читателя
     */
    Book(const std::string &title, const std::string &genre, int reader_age);

    /*! \brief Виртуальный деструктор */
    virtual ~Book() = default;

    /*! \brief Установка названия книги
     *  \param title Название книги
     */
    void SetTitle(const std::string &title);

    /*! \brief Установка жанра книги
     *  \param genre Жанр книги
     */
    void SetGenre(const std::string &genre);

    /*! \brief Установка информации об авторах
     *  \param info Информация об авторах
     */
    void SetInfoAboutAuthors(const std::string &info);

    /*! \brief Установка количества страниц
     *  \param count_of_pages Количество страниц
     */
    void SetCountOfPages(int count_of_pages);

    /*! \brief Установка года публикации
     *  \param publication_year Год публикации
     */
    void SetPublicationYear(int publication_year);

    /*! \brief Установка возрастного ограничения
     *  \param reader_age Возрастное ограничение
     */
    void SetReaderAge(int reader_age);

    /*! \brief Получение названия книги
     *  \return Название книги
     */
    std::string GetTitle() const;

    /*! \brief Получение жанра книги
     *  \return Жанр книги
     */
    std::string GetGenre() const;

    /*! \brief Получение информации об авторах
     *  \return Информация об авторах
     */
    std::string GetInfoAboutAuthors() const;

    /*! \brief Получение количества страниц
     *  \return Количество страниц (optional)
     */
    std::optional<int> GetCountOfPages() const;

    /*! \brief Получение года публикации
     *  \return Год публикации (optional)
     */
    std::optional<int> GetPublicationYear() const;

    /*! \brief Получение возрастного ограничения
     *  \return Возрастное ограничение (optional)
     */
    std::optional<int> GetReaderAge() const;

protected:
    std::string title_; /*!< Название книги */
    std::string genre_; /*!< Жанр книги */
    int count_of_pages_{0}; /*!< Количество страниц */
    int publication_year_{0}; /*!< Год публикации */
    int reader_age_{0}; /*!< Возрастное ограничение для читателя */
    std::string authors_; /*!< Информация об авторах */
};

/*! \class Song
 *  \brief Класс для представления песни
 *  \details Хранит информацию о песне: исполнители, название, язык, год выпуска и длительность
 */
class Song {
public:
    /*! \brief Конструктор по умолчанию */
    Song() = default;

    /*! \brief Параметризованный конструктор
     *  \param performers Список исполнителей
     *  \param title Название песни
     *  \param language Язык песни
     *  \param year Год выпуска
     *  \param time Длительность песни
     */
    Song(const std::vector<std::string> &performers, const std::string &title, const std::string &language, int year,
         double time);

    /*! \brief Добавление исполнителя
     *  \param performer Имя исполнителя
     */
    void AddPerformer(const std::string &performer);

    /*! \brief Удаление исполнителя по номеру
     *  \param number_of_performer Номер исполнителя для удаления
     */
    void DeletePerformer(int number_of_performer);

    /*! \brief Установка названия песни
     *  \param title Название песни
     */
    void SetTitle(const std::string &title);

    /*! \brief Установка языка песни
     *  \param language Язык песни
     */
    void SetLanguage(const std::string &language);

    /*! \brief Установка года выпуска
     *  \param year Год выпуска
     */
    void SetYear(int year);

    /*! \brief Установка длительности песни
     *  \param time Длительность песни
     */
    void SetTime(double time);

    /*! \brief Получение списка исполнителей
     *  \return Вектор исполнителей
     */
    std::vector<std::string> GetPerformers() const;

    /*! \brief Получение названия песни
     *  \return Название песни
     */
    std::string GetTitle() const;

    /*! \brief Получение языка песни
     *  \return Язык песни
     */
    std::string GetLanguage() const;

    /*! \brief Получение года выпуска
     *  \return Год выпуска (optional)
     */
    std::optional<int> GetYear() const;

    /*! \brief Получение длительности песни
     *  \return Длительность песни (optional)
     */
    std::optional<double> GetTime() const;

private:
    std::vector<std::string> performers_; /*!< Список исполнителей */
    std::string title_; /*!< Название песни */
    std::string language_; /*!< Язык песни */
    int year_{0}; /*!< Год выпуска */
    double time_{0.0}; /*!< Длительность песни в минутах */
};

/*! \class Album
 *  \brief Класс для представления музыкального альбома
 *  \details Содержит коллекцию песен
 */
class Album {
public:
    /*! \brief Конструктор по умолчанию */
    Album() = default;

    /*! \brief Добавление песни в альбом
     *  \param song Песня для добавления
     */
    void AddSong(const Song &song);

    /*! \brief Удаление песни из альбома по номеру
     *  \param number_of_song Номер песни для удаления
     */
    void DeleteSong(const int number_of_song);

    /*! \brief Получение всех песен альбома
     *  \return Вектор песен альбома
     */
    std::vector<Song> GetAlbum() const;

private:
    std::vector<Song> songs_; /*!< Вектор песен в альбоме */
};

/*! \class Film
 *  \brief Класс для представления фильма
 *  \details Хранит полную информацию о фильме: название, режиссер, актеры, рейтинг и т.д.
 */
class Film {
public:
    /*! \brief Конструктор по умолчанию */
    Film() = default;

    /*! \brief Параметризованный конструктор
     *  \param title Название фильма
     *  \param director Режиссер фильма
     *  \param genre Жанр фильма
     *  \param actors Список актеров
     */
    Film(const std::string &title, const std::string &director, const std::string &genre,
         const std::vector<std::string> &actors);

    /*! \brief Установка названия фильма
     *  \param title Название фильма
     */
    void SetTitle(const std::string &title);

    /*! \brief Установка режиссера фильма
     *  \param director Режиссер фильма
     */
    void SetDirector(const std::string &director);

    /*! \brief Установка жанра фильма
     *  \param genre Жанр фильма
     */
    void SetGenre(const std::string &genre);

    /*! \brief Установка сюжета фильма
     *  \param plot Сюжет фильма
     */
    void SetPlot(const std::string &plot);

    /*! \brief Установка длительности фильма
     *  \param time Длительность фильма
     */
    void SetTime(const double time);

    /*! \brief Установка рейтинга фильма
     *  \param rating Рейтинг фильма
     */
    void SetRating(const int rating);

    /*! \brief Отметка получения Оскара */
    void SetOscar();

    /*! \brief Снятие отметки получения Оскара */
    void TakeOscar();

    /*! \brief Отметка использования компьютерной графики */
    void UseComputerGraphic();

    /*! \brief Снятие отметки использования компьютерной графики */
    void DoNotUseComputerGraphic();

    /*! \brief Установка года выпуска фильма
     *  \param year Год выпуска
     */
    void SetYear(const int year);

    /*! \brief Добавление актера в список
     *  \param actor Имя актера
     */
    void AddActor(const std::string &actor);

    /*! \brief Удаление актера по номеру
     *  \param number_of_actor Номер актера для удаления
     */
    void DeleteActor(int number_of_actor);

    /*! \brief Получение названия фильма
     *  \return Название фильма
     */
    std::string GetTitle() const;

    /*! \brief Получение режиссера фильма
     *  \return Режиссер фильма
     */
    std::string GetDirector() const;

    /*! \brief Получение жанра фильма
     *  \return Жанр фильма
     */
    std::string GetGenre() const;

    /*! \brief Получение сюжета фильма
     *  \return Сюжет фильма
     */
    std::string GetPlot() const;

    /*! \brief Получение длительности фильма
     *  \return Длительность фильма (optional)
     */
    std::optional<double> GetTime() const;

    /*! \brief Получение рейтинга фильма
     *  \return Рейтинг фильма (optional)
     */
    std::optional<int> GetRating() const;

    /*! \brief Проверка получения Оскара
     *  \return true если фильм получил Оскар, false в противном случае
     */
    bool GetIsOscar() const;

    /*! \brief Проверка использования компьютерной графики
     *  \return true если используется компьютерная графика, false в противном случае
     */
    bool GetIsComputerGraphic() const;

    /*! \brief Получение года выпуска фильма
     *  \return Год выпуска (optional)
     */
    std::optional<int> GetYear() const;

    /*! \brief Получение списка актеров
     *  \return Вектор актеров
     */
    std::vector<std::string> GetActors() const;

    /*! \brief Проверка, является ли фильм хорошим
     *  \return true если фильм хороший (на основе рейтинга и наличия Оскара), false в противном случае
     */
    bool CheckIsFilmGood() const;

private:
    std::string title_; /*!< Название фильма */
    std::string director_; /*!< Режиссер фильма */
    std::string genre_; /*!< Жанр фильма */
    std::string plot_; /*!< Сюжет фильма */
    double time_{0.0}; /*!< Длительность фильма в минутах */
    int rating_{0}; /*!< Рейтинг фильма */
    bool is_oscar_{false}; /*!<Есть ли Оскар */
    bool is_computer_graphic_{false}; /*!< Использовалась ли компьютерной графики */
    int year_{0}; /*!< Год выпуска фильма */
    std::vector<std::string> actors_; /*!< Список актеров */
};
#endif //INTEREST_H
