#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <iostream>

class AVMExceptions : public std::exception {
    public :
        AVMExceptions(const std::string &msg);
        const char* what() const noexcept override;

        void    handle() const;
        virtual ~AVMExceptions() = 0;
    private :
        std::string _msg;
};

#endif