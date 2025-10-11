#include "exceptions.h"

Exception::Exception(const char *msg): message(msg) {
}

Exception::Exception(const Exception &other): message(other.message) {
}

const char *Exception::what() const noexcept {
	return this->message.c_str();
}

ExceptionUserName::ExceptionUserName(const char *msg): Exception(msg) {
}

ExceptionName::ExceptionName(const char *msg): Exception(msg) {
}

ExceptionSurName::ExceptionSurName(const char *msg): Exception(msg) {
}

ExceptionEmail::ExceptionEmail(const char *msg): Exception(msg) {
}

ExceptionPhoneNumber::ExceptionPhoneNumber(const char *msg): Exception(msg) {
}

ExceptionPassword::ExceptionPassword(const char *msg): Exception(msg) {
}

ExceptionIncorrectMessage::ExceptionIncorrectMessage(const char *msg): Exception(msg) {
}

ExceptionIncorrectNumber::ExceptionIncorrectNumber(const char *msg): Exception(msg) {
}

ExceptionAccess::ExceptionAccess(const char *msg): Exception(msg) {
}

ExceptionUserExist::ExceptionUserExist(const char *msg): Exception(msg) {
}

ExceptionNothingToPrint::ExceptionNothingToPrint(const char *msg): Exception(msg) {
}

ExceptionIncorrectReaction::ExceptionIncorrectReaction(const char *msg): Exception(msg) {
}

ExceptionIncorrectHashTag::ExceptionIncorrectHashTag(const char *msg): Exception(msg) {
}

ExceptionRuntimeError::ExceptionRuntimeError(const char *msg): Exception(msg) {
}

ExceptionIncorrectRole::ExceptionIncorrectRole(const char *msg): Exception(msg) {
}