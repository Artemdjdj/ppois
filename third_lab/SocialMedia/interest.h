#ifndef INTEREST_H
#define INTEREST_H
#include <string>
#include <vector>
#include "../Utils/project_utils.h"

class Interest : public Info {
public:
    Interest() = default;

    Interest(const std::string &name, const std::string &info, const std::string &duration, int level);

    void SetDuration(const std::string &duration);

    std::string GetDuration();

    void SetLevel(int level);

    int GetLevel() const;

private:
    std::string duration_;
    int level_;
};


class Book {
public:
    Book();

    Book(const std::string &title, const std::string &genre, int reader_age);

    virtual ~Book();

    void SetTitle(const std::string &title);

    void SetGenre(const std::string &genre);

    virtual void SetInfoAboutAuthor(const std::string &info) = 0;

    void SetCountOfPages(int count_of_pages);

    void SetPublicationYear(int publication_year);

    void SetReaderAge(int reader_age);

    std::string GetTitle() const;

    std::string GetGenre() const;

    virtual std::string GetInfoAboutAuthors() const = 0;

    int GetCountOfPages() const;

    int GetPublicationYear() const;

    int GetReaderAge() const;

protected:
    std::string title_;
    std::string genre_;
    std::string info_about_authors_;
    int count_of_pages_{0};
    int publication_year_{0};
    int reader_age_{0};
};

class BookWithOneAuthor final : public Book {
public:
    BookWithOneAuthor(const std::string &title, const std::string &genre, int reader_age,
                      const std::string &base_info) : Book(title, genre, reader_age), author_(base_info) {
    };

    void SetInfoAboutAuthor(const std::string &base_info) override;

    std::string GetInfoAboutAuthors() const override;

private:
    std::string author_;
};


class BookWithAnyAuthors final : public Book {
    BookWithAnyAuthors(const std::string &title, const std::string &genre, int reader_age,
                       const std::vector<std::string> &base_info) : Book(title, genre, reader_age),
                                                                    authors_(base_info) {
    };

    void SetInfoAboutAuthor(const std::string &base_info) override;

    std::string GetInfoAboutAuthors() const override;

private:
    std::vector<std::string> authors_;
};

class Song {
    Song() = default;

    Song(const std::vector<std::string> &performer, const std::string &title, const std::string &language, int year,
         double time);

    void AddPerformer(const std::string &performer);

    void DeletePerformer(int number_of_performer);

    void SetTitle(const std::string &title);

    void SetLanguage(const std::string &language);

    void SetYear(int year);

    void SetTime(double time);

    std::vector<std::string> GetPerformers() const;

    std::string GetTitle() const;

    std::string GetLanguage() const;

    std::optional<int> GetYear() const;

    std::optional<double> GetTime() const;

private:
    std::vector<std::string> performers_;
    std::string title_;
    std::string language_;
    int year_{0};
    double time_{0.0};
};

class Album {
public:
    Album() = default;

    void AddSong(const Song &song);

    void DeleteSong(int number_of_song);

private:
    std::vector<Song> songs_;
};


class Film {
public:
    Film() = default;

    Film(const std::string &title, const std::string &director, const std::string &genre,
         const std::vector<std::string> &actors);

    void SetTitle(const std::string &title);

    void SetDirector(const std::string &director);

    void SetGenre(const std::string &genre);

    void SetPlot(const std::string &plot);

    void SetTime(double time);

    void SetRating(int rating);

    void SetOscar();

    void TakeOscar();

    void UseComputerGraphic();

    void DoNotUseComputerGraphic();

    void SetYear();

    void AddActor(const std::string &actor);

    void DeleteActor(int number_of_actor);

    std::string GetTitle() const;

    std::string GetDirector() const;

    std::string GetGenre() const;

    std::string GetPlot() const;

    std::optional<double> GetTIme() const;

    std::optional<int> GetRating() const;

    bool GetIsOscar() const;

    bool GetIsComputerGraphic() const;

    std::optional<int> GetYear() const;

    std::vector<std::string> GetActors() const;

    bool CheckIsFilmInteresting();

private:
    std::string title_;
    std::string director_;
    std::string genre_;
    std::string plot_;
    double time{0.0};
    int rating_{0};
    bool is_oscar_{false};
    bool is_computer_graphic_{false};
    int year_{0};
    std::vector<std::string> actors_;
};
#endif //INTEREST_H
