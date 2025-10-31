#include "Exceptions.hpp"

AVMExceptions::AVMExceptions(const char *msg) : _msg(msg) {}

AVMExceptions::~AVMExceptions(){}

const char* AVMExceptions::what() const noexcept
{
    return (_msg);
}

error    AVMExceptions::handle() const
{
    std::cerr << "Line " << g_line_error << " : Error : " << what() << std::endl;
    #ifndef BONUS
        return Manda_succes;
    #else
        return Bonus;
    #endif
}

error    AVMExceptions::handle(std::string more_information) const
{
    std::cerr << "Line " << g_line_error << " : Error : " << what() << " : " << more_information << std::endl;
    #ifndef BONUS
        return Manda_succes;
    #else
        return Bonus;
    #endif
}
