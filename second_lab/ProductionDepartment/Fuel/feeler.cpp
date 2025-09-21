#include "basic_params.h"
#include "feeler.h"
#include "../Exceptions/exceptions.h"

Feeler::Feeler()=default;

Feeler::Feeler(int length, int level): length(length), level(level) {}

bool Feeler::set_length(int length) {
    return set_single_value(length, "Length can't be negative or zero", this->length);
}

bool Feeler::set_level(int level) {
    if (level > this->length) return false;
    return set_single_value(level, "Level can't be negative or zero", this->level);
}

int Feeler::get_length() const {
    return this->length;
}

int Feeler::get_level() const {
    return this->level;
}

void Feeler::check_is_the_level_in_norm_state_private() const {
    int res_percent = static_cast<int>(100 * this->get_level() / this->get_length());
    if (res_percent < 40) {
        throw ExceptionIncorrectLevelOil("The level of oil below norm!");
    }
    else if (res_percent > 60) {
        throw ExceptionIncorrectLevelOil("The level of oil above norm!");
    }
}

bool Feeler::check_is_the_level_in_norm_state() const {
    try {
        check_is_the_level_in_norm_state_private();
        return true;
    }
    catch (const ExceptionIncorrectLevelOil& e) {
        log_to_file(e.what());
        return false;
    }
    catch (const Exception & e) {
        log_to_file(e.what());
        return false;
    }
}
