#include "basic_params.h"
#include "../../Exceptions/exceptions.h"
#include "season.h"
#include "../Include/settings.h"

Season::Season() {
}

Season::Season(const std::string& season) {
	this->season_ = season;
}

bool Season::SetSeason(std::string season) {
	try {
		if (!CheckIsStatementCorrect(seasons, season)) {
			throw ExceptionIncorrectSeason("Incorrect season, you can write winter or summer!");
		}
		this->season_ = season;
		return true;
	} catch (const ExceptionIncorrectSeason &e) {
		LogToFile(e.what(), PATH_TO_FILE);
		return false;
	}
	catch (const Exception &e) {
		LogToFile(e.what(), PATH_TO_FILE);
		return false;
	}
}

std::string Season::GetSeason() const{
	return season_;
}
