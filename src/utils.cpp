#include "utils.hpp"
#include "MyExceptions.hpp"


void    checkRange(eOperandType type, std::string const &value)
{
    switch (type)
    {
        case Int8:
        {
            if (value.length() >= 4)
            {
                if (value[0] == '-' && value > "-128")
                    throw UnderflowException();
            }
            else if (value.length() >= 3 && value > "127")
                throw OverflowException();
        }
        case Int16:
        {
            if (value.length() >= 6)
            {
                if (value[0] == '-' && value > "-32768")
                    throw UnderflowException();
            }
            else if (value.length() >= 5 && value > "32767")
                throw OverflowException();
        }
        case Int32:
        {
            if (value.length() >= 11)
            {
                if (value[0] == '-' && value > "-2147483648")
                    throw UnderflowException();
            }
            else if (value.length() >= 10 && value > "2147483647")
                throw OverflowException();
        }
        case Float:
        {
            float tmp = std::strtof(value.c_str(), nullptr);

            std::cout << "verif isinf = "<< std::isinf(tmp) << std::endl;
            if (std::isinf(tmp))
            {
                if (value[0] =='-')
                    throw UnderflowException();
                throw OverflowException();
            }
            // else if (value > std::to_string(FLT_MAX))
            //     throw OverflowException();
            // std::string maxFloat = std::to_string(FLT_MAX);
            // std::string minFloat = std::to_string(-FLT_MAX);
            // std::cout << "Min = " << minFloat << std::endl;
            // std::cout << "Max = " << maxFloat << std::endl;
            std::cout << "value = " << value << std::endl;
        }
        case Double:
        {

        }
    }
}