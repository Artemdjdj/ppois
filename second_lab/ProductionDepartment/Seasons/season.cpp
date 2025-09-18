
#include "include_basic_params.h"
#include "include_exceptions.h"
#include "include_season.h"
#include "settings.h"

Season::Season(){}

Season::Season(std::string season) {
    this->season = season;
}

void Season::set_season_private(std::string season) {
    if (!check_is_statement_correct(seasons,season)) {
        throw ExceptionIncorrectSeason("Incorrect season, you can write winter or summer!");
    }
    this->season = season;
}

bool Season::set_season(std::string season) {
    try {
        set_season_private(season);
        return true;
    }
    catch (const ExceptionIncorrectSeason &e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception& e) {
        log_to_file(e.what());
        return false;
    }
}

std::string Season::get_season() {
    return season;
}