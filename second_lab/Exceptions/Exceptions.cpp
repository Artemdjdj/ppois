
#include <string>

#include "include_exceptions.h"
using namespace std;

Exception::Exception(const char * msg): message(msg) {}

Exception::Exception(const Exception& other): message(other.message) {}

const char * Exception::what() const noexcept{
    return this->message.c_str();
}

ExceptionIncorrectRadius::ExceptionIncorrectRadius(const char * msg): Exception(msg) {}

ExceptionIncorrectColor::ExceptionIncorrectColor(const char * msg): Exception(msg) {}

ExceptionIncorrectMaterial::ExceptionIncorrectMaterial(const char * msg): Exception(msg) {}

ExceptionIncorrectSize::ExceptionIncorrectSize(const char * msg): Exception(msg) {}

ExceptionIncorrectSerialNumber::ExceptionIncorrectSerialNumber(const char * msg): Exception(msg) {}

ExceptionIncorrectSerialNumberLength::ExceptionIncorrectSerialNumberLength(const char * msg): ExceptionIncorrectSerialNumber(msg){}
