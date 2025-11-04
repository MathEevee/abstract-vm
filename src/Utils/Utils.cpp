#include "Utils.hpp"
#include "../Exceptions/MyExceptions.hpp"

int g_line_error = 0;

void increment() {
    g_line_error++;
}

std::string     instruction_to_string(Instruction my_instruction)
{
    switch (my_instruction)
    {
        case Push :
            return ("Push");
        case Pop :
            return ("Pop");
        case Dump :
            return ("Dump");
        case Rdump :
            return ("Rdump");
        case Swap :
            return ("Swap");
        case Min :
            return ("Min");
        case Max :
            return ("Max");
        case Assert :
            return ("Assert");
        case Add :
            return ("Add");
        case Sub :
            return ("Sub");
        case Mul :
            return ("Mul");
        case Div :
            return ("Div");
        case Mod :
            return ("Mod");
        case Print :
            return ("Print");
        case Exit :
            return ("Exit");
        default :
            return ("Unknow");
    }
}

void    strcmpRange(double min, double max, std::string const &value)
{
    double tmp = std::stod(value);
    if (std::isinf(tmp))
    {
        if (tmp < 0)
            throw UnderflowException();
        else
            throw OverflowException();
    }
    if (tmp > max)
    {
        throw OverflowException();
    }
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
            strcmpRange(std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max(), value);
            break;
        }
        case Int16:
        {
            strcmpRange(std::numeric_limits<int16_t>::min(), std::numeric_limits<int16_t>::max(), value);
            break;
        }
        case Int32:
        {
            strcmpRange(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max(), value);
            break;
        }
        case Float:
        {
            strcmpRange(-std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), value);//probleme perte avec l'excriture scientifique
            break;
        }
        case Double:
        {
            strcmpRange(-std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), value);
            break;
        }
        default:
        {
            throw LexicalErrorException();
        }
    }
}