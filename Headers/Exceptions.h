#ifndef POO_EXCEPTIONS_H
#define POO_EXCEPTIONS_H

#include <exception>
#include <string>
#include <utility>

class AppException : public std::exception {
protected:
    std::string msg;

public:
    explicit AppException(std::string m) : msg(std::move(m)) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class InvalidOption : public AppException {
public:
    explicit InvalidOption(std::string m = "Optiune invalida.")
        : AppException(std::move(m)) {}
};

class NotEnoughMoney : public AppException {
public:
    explicit NotEnoughMoney(std::string m = "Fonduri insuficiente.")
        : AppException(std::move(m)) {}
};

class OutOfRange : public AppException {
public:
    explicit OutOfRange(std::string m = "Index in afara intervalului.")
        : AppException(std::move(m)) {}
};

#endif
