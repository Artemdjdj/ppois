#ifndef INTEREST_H
#define INTEREST_H
#include <string>
#include <vector>
#include "../Utils/project_utils.h"

class Interest final : public Info {
public:
    Interest() = default;

    Interest(const std::string &name, const std::string &info, const std::string &duration, int level);

    void SetDuration(const std::string &duration);

    std::string GetDuration();

    void SetLevel(int level);

    int GetLevel() const;

private:
    std::string duration_;
    int level_{0};
};


class Book {
public:
    Book() = default;

    Book(const std::string &title, const std::string &genre, int reader_age);

    virtual ~Book() = default;

    void SetTitle(const std::string &title);

    void SetGenre(const std::string &genre);

    void SetInfoAboutAuthors(const std::string &info);

    void SetCountOfPages(int count_of_pages);

    void SetPublicationYear(int publication_year);

    void SetReaderAge(int reader_age);

    std::string GetTitle() const;

    std::string GetGenre() const;

    std::string GetInfoAboutAuthors() const;

    std::optional<int> GetCountOfPages() const;

    std::optional<int> GetPublicationYear() const;

    std::optional<int> GetReaderAge() const;

protected:
    std::string title_;
    std::string genre_;
    int count_of_pages_{0};
    int publication_year_{0};
    int reader_age_{0};
    std::string authors_;
};


class Song {
public:
    Song() = default;

    Song(const std::vector<std::string> &performers, const std::string &title, const std::string &language, int year,
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

    void DeleteSong(const int number_of_song);

    std::vector<Song> GetAlbum() const;

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

    void SetTime(const double time);

    void SetRating(const int rating);

    void SetOscar();

    void TakeOscar();

    void UseComputerGraphic();

    void DoNotUseComputerGraphic();

    void SetYear(const int year);

    void AddActor(const std::string &actor);

    void DeleteActor(int number_of_actor);

    std::string GetTitle() const;

    std::string GetDirector() const;

    std::string GetGenre() const;

    std::string GetPlot() const;

    std::optional<double> GetTime() const;

    std::optional<int> GetRating() const;

    bool GetIsOscar() const;

    bool GetIsComputerGraphic() const;

    std::optional<int> GetYear() const;

    std::vector<std::string> GetActors() const;

    bool CheckIsFilmGood() const;

private:
    std::string title_;
    std::string director_;
    std::string genre_;
    std::string plot_;
    double time_{0.0};
    int rating_{0};
    bool is_oscar_{false};
    bool is_computer_graphic_{false};
    int year_{0};
    std::vector<std::string> actors_;
};
#endif //INTEREST_H
