#include "Exceptions.hpp"

AVMExceptions::AVMExceptions(const char *msg) : _msg(msg) {}

AVMExceptions::~AVMExceptions(){}

const char* AVMExceptions::what() const noexcept
{
    return (_msg);
}

void    AVMExceptions::handle() const //ajouter ici d'autres params pour mettre des précisions (num de ligne + la ligne)
{
    std::cerr << what() << std::endl;
    #ifndef BONUS
        exit(1);
    #else
        throw;
    #endif
}
