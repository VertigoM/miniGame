#pragma once
#include <exception>
#include <string>

class Exception : public std::exception {
public:
    explicit Exception(const char* message) :
        msg_(message) {}

    explicit Exception(const std::string& message) :
        msg_(message) {}

    virtual ~Exception() noexcept {}

    virtual const char* what() noexcept {
        return msg_.c_str();
    }
protected:
    std::string msg_;
};

