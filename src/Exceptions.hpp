#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <iostream>
#include "Utils.hpp"


enum error {
    Manda_succes,
    Manda_failed,
    Bonus
};

class AVMExceptions : public std::exception {
    public :
        AVMExceptions(const char *msg);
        const char* what() const noexcept override;

        error    handle() const;
        error    handle(std::string more_information) const;
        virtual ~AVMExceptions();
    private :
        const char* _msg;
};

#endif