
#ifndef INCLUDE_EXCEPTIONS_H
#define INCLUDE_EXCEPTIONS_H
#include <string>
#include <exception>


class Exception:public std::exception {
private:
    std::string message;
public:
    explicit Exception(const char * msg);
    explicit Exception(const Exception& other);
    const char * what() const noexcept override;
};

class ExceptionIncorrectRadius final:public Exception {
public:
    explicit ExceptionIncorrectRadius(const char * msg);
};

class ExceptionIncorrectColor final:public Exception {
public:
    explicit ExceptionIncorrectColor(const char * msg);
};

class ExceptionIncorrectMaterial final:public Exception {
public:
    explicit ExceptionIncorrectMaterial(const char * msg);
};

class ExceptionIncorrectSize:public Exception {
public:
    explicit ExceptionIncorrectSize(const char * msg);
};

class ExceptionIncorrectSerialNumber final:public Exception {
public:
    explicit ExceptionIncorrectSerialNumber(const char * msg);
};

class ExceptionIncorrectSeason final:public Exception {
public:
    explicit ExceptionIncorrectSeason(const char * msg);
};

class ExceptionIncorrectFuel final:public Exception {
public:
    explicit ExceptionIncorrectFuel(const char * msg);
};

class ExceptionIncorrectProcent final:public ExceptionIncorrectSize {
public:
    explicit ExceptionIncorrectProcent(const char * msg);
};

class ExceptionIncorrectVolume final :public ExceptionIncorrectSize {
public:
    explicit ExceptionIncorrectVolume(const char * msg);
};

// class ExceptionIncorrectWeight final:public ExceptionIncorrectSize {
// public:
//     explicit ExceptionIncorrectWeight(const char * msg);
// };
#endif
