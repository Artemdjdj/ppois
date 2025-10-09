#include "basic_params.h"
#include "feeler.h"
#include "../../Exceptions/exceptions.h"
#include "../Include/settings.h"

Feeler::Feeler() = default;

Feeler::Feeler(int length, int level): length_(length), level_(level) {
}

void Feeler::SetLength(int length) {
	SetSingleValue(length, "Length can't be negative or zero", this->length_);
}

void Feeler::SetLevel(int level) {
	if (level > this->length_) return;
	SetSingleValue(level, "Level can't be negative or zero", this->level_);
}

int Feeler::GetLength() const {
	return this->length_;
}

int Feeler::GetLevel() const {
	return this->level_;
}

void Feeler::CheckIsTheLevelInNormState() const {
	int res_percent = static_cast<int>(100 * this->GetLevel() / this->GetLength());
	if (res_percent < 40) {
		throw ExceptionIncorrectLevelOil("The level of oil below norm!");
	} else if (res_percent > 60) {
		throw ExceptionIncorrectLevelOil("The level of oil above norm!");
	}
}
