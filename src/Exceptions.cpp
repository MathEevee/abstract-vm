#include "Exceptions.hpp"

AVMExceptions::AVMExceptions(const std::string &msg) : _msg(msg) {}

AVMExceptions::~AVMExceptions(){}

const char* AVMExceptions::what() const noexcept
{
    return (_msg.c_str());
}

void    AVMExceptions::handle() const //ajouter ici d'autres params pour mettre des précisions (num de ligne + la ligne)
{
    std::cerr << what() << std::endl;
    #ifndef BONUS
        exit(1);
    #endif
}
