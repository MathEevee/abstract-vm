#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include "../Utils/Utils.hpp"


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
        error    handle(Instruction my_instruction) const;
        virtual ~AVMExceptions();
    private :
        const char* _msg;
};

#endif