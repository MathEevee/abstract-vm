#include "Utils.hpp"
#include "MyExceptions.hpp"

void    strcmpRange(double min, double max, std::string const &value)
{
    double tmp = std::stod(value);
    std::cout << tmp << std::endl;
    std::cout << min << std::endl;
    std::cout << value << std::endl;
    std::cout << max << std::endl;
    std::cout << "---------------" << std::endl;
    if (std::isinf(tmp))
    {
        if (tmp < 0)
            throw UnderflowException();
        else
            throw OverflowException();
    }
    if (tmp > max)
        throw OverflowException();
    else if (tmp < min)
    {
        throw UnderflowException();
    }
}

void    checkRange(eOperandType type, std::string const &value)
{
    switch (type)
    {
        case Int8:
        {
            strcmpRange((double)(std::numeric_limits<int8_t>::min()), (double)(std::numeric_limits<int8_t>::max()), value);
            break;
        }
        case Int16:
        {
            strcmpRange((double)(std::numeric_limits<int16_t>::min()), (double)(std::numeric_limits<int16_t>::max()), value);
            break;
        }
        case Int32:
        {
            strcmpRange((double)(std::numeric_limits<int32_t>::min()), (double)(std::numeric_limits<int32_t>::max()), value);
            break;
        }
        case Float:
        {
            strcmpRange((double)FLT_MAX, (double)-FLT_MAX, value);//probleme perte avec l'excriture scientifique
            break;
        }
        case Double:
        {
            strcmpRange((double)(std::numeric_limits<double>::min()), (double)(std::numeric_limits<double>::max()), value);
            break;
        }
    }
}