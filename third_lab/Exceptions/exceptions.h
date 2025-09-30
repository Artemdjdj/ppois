#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>
#include <string>

class Exception : public std::exception {
private:
	std::string message;

public:
	explicit Exception(const char *msg);

	explicit Exception(const Exception &other);

	const char *what() const noexcept override;
};

class ExceptionUserName final : public Exception {
public:
	explicit ExceptionUserName(const char *msg);
};

class ExceptionName final : public Exception {
public:
	explicit ExceptionName(const char *msg);
};

class ExceptionSurName final : public Exception {
public:
	explicit ExceptionSurName(const char *msg);
};

class ExceptionEmail final : public Exception {
public:
	explicit ExceptionEmail(const char *msg);
};

class ExceptionPhoneNumber final : public Exception {
public:
	explicit ExceptionPhoneNumber(const char *msg);
};

class ExceptionPassword final :public Exception{
public:
	explicit ExceptionPassword(const char *msg);
};

class ExceptionIncorrectMessage final :public Exception{
public:
	explicit ExceptionIncorrectMessage(const char *msg);
};

class ExceptionIncorrectNumberOfMessage final :public Exception{
public:
	explicit ExceptionIncorrectNumberOfMessage(const char *msg);
};

class ExceptionAccess final :public Exception{
public:
	explicit ExceptionAccess(const char *msg);
};
#endif //EXCEPTIONS_H
