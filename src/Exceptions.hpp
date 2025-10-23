#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <iostream>

class AVMExceptions : public std::exception {
    public :
        AVMExceptions(const char *msg);
        const char* what() const noexcept override;

        void    handle() const;
        virtual ~AVMExceptions();
    private :
        const char* _msg;
};

#endif