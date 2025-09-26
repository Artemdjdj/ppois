#include <string>
#include "exceptions.h"
using namespace std;

Exception::Exception(const char *msg): message(msg) {
}

Exception::Exception(const Exception &other): message(other.message) {
}

const char *Exception::what() const noexcept {
	return this->message.c_str();
}

ExceptionIncorrectRadius::ExceptionIncorrectRadius(const char *msg): Exception(msg) {
}

ExceptionIncorrectColor::ExceptionIncorrectColor(const char *msg): Exception(msg) {
}

ExceptionIncorrectMaterial::ExceptionIncorrectMaterial(const char *msg): Exception(msg) {
}

ExceptionIncorrectSize::ExceptionIncorrectSize(const char *msg): Exception(msg) {
}

ExceptionIncorrectSerialNumber::ExceptionIncorrectSerialNumber(const char *msg): Exception(msg) {
}

ExceptionIncorrectSeason::ExceptionIncorrectSeason(const char *msg): Exception(msg) {
}

ExceptionIncorrectFuel::ExceptionIncorrectFuel(const char *msg): Exception(msg) {
}

ExceptionIncorrectProcent::ExceptionIncorrectProcent(const char *msg): ExceptionIncorrectSize(msg) {
}

ExceptionIncorrectVolume::ExceptionIncorrectVolume(const char *msg): ExceptionIncorrectSize(msg) {
}

ExceptionIncorrectLevelOil::ExceptionIncorrectLevelOil(const char *msg): Exception(msg) {
}

ExceptionRuntimeError::ExceptionRuntimeError(const char *msg): Exception(msg) {
}

ExceptionWayError::ExceptionWayError(const char *msg): Exception(msg) {
}
