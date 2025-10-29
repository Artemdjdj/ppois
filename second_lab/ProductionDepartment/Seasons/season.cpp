#include "basic_params.h"
#include "../../Exceptions/exceptions.h"
#include "season.h"
#include "../Include/settings.h"

Season::Season(const std::string &season) {
    SetSeason(season);
}

void Season::SetSeason(std::string season) {
    if (!CarValidator::CheckIsStatementCorrect(kSeasons, season)) {
        throw ExceptionIncorrectSeason("Incorrect season, you can write winter or summer!");
    }
    this->season_ = season;
}

std::string Season::GetSeason() const {
    return season_;
}
