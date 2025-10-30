#include "OperandFactory.hpp"
#include "Operand.hpp"
#include "Utils.hpp"

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
    switch (type)
    {
        case Int8:
        {
            checkRange(type, value);
            return (new Operand<int8_t, Int8>(value));
        }
        case Int16:
        {
            checkRange(type, value);
            return (new Operand<int16_t, Int16>(value));
        }
        case Int32:
        {
            checkRange(type, value);
            return (new Operand<int32_t, Int32>(value));
        }
        case Float:
        {
            checkRange(type, value);
            return (new Operand<float, Float>(value));
        }
       case Double:
        {
            checkRange(type, value);
            return (new Operand<double, Double>(value));
        }
        default:
        {
            throw LexicalErrorException();
        }
    }
}

