
#ifndef INCLUDE_EXCEPTIONS_H
#define INCLUDE_EXCEPTIONS_H
#include <string>
#include <exception>


class Exception:public std::exception {
private:
    std::string message;
public:
    Exception(const char * msg);
    Exception(const Exception& other);
    const char * what() const noexcept override;
};

class ExceptionIncorrectRadius:public Exception {
public:
    ExceptionIncorrectRadius(const char * msg);
};

class ExceptionIncorrectColor:public Exception {
public:
    ExceptionIncorrectColor(const char * msg);
};

class ExceptionIncorrectMaterial:public Exception {
public:
    ExceptionIncorrectMaterial(const char * msg);
};

class ExceptionIncorrectSize:public Exception {
public:
    ExceptionIncorrectSize(const char * msg);
};

class ExceptionIncorrectSerialNumber:public Exception {
public:
    ExceptionIncorrectSerialNumber(const char * msg);
};

class ExceptionIncorrectSeason :public Exception {
public:
    ExceptionIncorrectSeason(const char * msg);
};

class ExceptionIncorrectFuel :public Exception {
public:
    ExceptionIncorrectFuel(const char * msg);
};

class ExceptionIncorrectProcent :public ExceptionIncorrectSize {
public:
    ExceptionIncorrectProcent(const char * msg);
};
#endif
