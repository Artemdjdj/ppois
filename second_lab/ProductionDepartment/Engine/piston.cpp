#include "basic_params.h"
#include "piston.h"
#include "../../Exceptions/exceptions.h"

Piston::Piston(const int diameter_p, const int height_p, const int compression_height_p, const int count_of_cycles_p,
               const int weight_p) : diameter_(diameter_p), height_(height_p),
                                     compression_height_(compression_height_p),
                                     count_of_cycles_(count_of_cycles_p),
                                     weight_(weight_p) {
}

void Piston::SetAllParameters(int diameter, int height, int compression_height, int count_of_cycles, int weight) {
    CarSetter::SetSingleValue(diameter, "The diameter should be bigger then 0!", this->diameter_);
    CarSetter::SetSingleValue(height, "The height should be bigger then 0!", this->height_);
    CarSetter::SetSingleValue(compression_height, "The Compression height should be bigger then 0!",
                   this->compression_height_);
    CarSetter::SetSingleValue(count_of_cycles, "The count_of_cycles should be bigger then 0!",
                   this->count_of_cycles_);
    CarSetter::SetSingleValue(weight, "The weight should be bigger then 0!", this->weight_);
}

int Piston::GetDiameter() const {
    return this->diameter_;
}

int Piston::GetCountOfCycles() const {
    return this->count_of_cycles_;
}

int Piston::GetHeight() const {
    return this->height_;
}

int Piston::GetWeight() const {
    return this->weight_;
}

bool Piston::CheckIsPistonInWorkingCondition() const {
    return (this->count_of_cycles_ <= 10000);
}

int Piston::GetCompressionHeight() const {
    return this->compression_height_;
}

void Piston::SetManufacturer(const std::string &manufacturer) {
    this->manufacturer_ = manufacturer;
}

void Piston::SetPistonType(const std::string &piston_type) {
    this->piston_type_ = piston_type;
}

void Piston::SetPinDiameter(const int pin_diameter) {
    if (pin_diameter < 0) {
        throw ExceptionRuntimeError("Incorrect pin diameter");
    }
    this->pin_diameter_ = pin_diameter;
}

void Piston::SetOperatingTemperature(const int temperature) {
    this->operating_temperature_ = temperature;
}

void Piston::SetMaxPressure(const int max_pressure) {
    if (max_pressure < 0) {
        throw ExceptionRuntimeError("Incorrect max pressure");
    }
    this->max_pressure_ = max_pressure;
}

void Piston::SetCompressionRatio(const double compression_ratio) {
    if (compression_ratio < 0) {
        throw ExceptionRuntimeError("Incorrect compression ratio");
    }
    this->compression_ratio_ = compression_ratio;
}

void Piston::SetOilGroovesCount(const int oil_grooves_count) {
    if (oil_grooves_count < 0) {
        throw ExceptionRuntimeError("Incorrect oil grooves count");
    }
    this->oil_grooves_count_ = oil_grooves_count;
}

void Piston::SetHasThermalCoating(const bool is_coating) {
    this->is_coating_ = is_coating;
}

void Piston::SetLifespan(const int life_span) {
    if (life_span < 0) {
        throw ExceptionRuntimeError("Incorrect lifespan");
    }
    this->life_span_ = life_span;
}

void Piston::SetSpeed(const int speed) {
    if (speed < 0) {
        throw ExceptionRuntimeError("Incorrect speed");
    }
    this->speed_ = speed;
}

std::string Piston::GetManufacturer() const {
    return this->manufacturer_;
}

std::string Piston::GetPistonType() const {
    return this->piston_type_;
}

int Piston::GetPinDiameter() const {
    return this->pin_diameter_;
}

int Piston::GetOperatingTemperature() const {
    return this->operating_temperature_;
}

int Piston::GetMaxPressure() const {
    return this->max_pressure_;
}

double Piston::GetCompressionRatio() const {
    return this->compression_ratio_;
}

int Piston::GetOilGroovesCount() const {
    return this->oil_grooves_count_;
}

bool Piston::IsThermalCoating() const {
    return this->is_coating_;
}

int Piston::GetLifespan() const {
    return this->life_span_;
}

int Piston::GetSpeed() const {
    return this->speed_;
}
