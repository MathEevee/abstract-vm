#include "../Utils/Utils.hpp"

template<typename Unit, eOperandType Type>
Operand<Unit, Type>::Operand(std::string const &value)
{
    _value = static_cast<Unit>(std::stod(value));
    if (Type == Int8 || Type == Int16 || Type == Int32)
    _str = std::to_string(static_cast<int>(_value));
    else
    {
        if (value.find('.') != std::string::npos)
        {
            std::string tmp = value.substr(0, value.find_last_not_of('0') + 1);
            if (tmp[tmp.length() - 1] == '.')
            tmp = tmp.substr(0, tmp.length() - 1);
            _str = tmp;
        }
        else
            _str = value;
    }
}

template<typename Unit, eOperandType Type>
Operand<Unit, Type>::Operand(Operand const & rhs)
{
    *this = rhs;
}

template<typename Unit, eOperandType Type>
Operand<Unit, Type>::Operand(void) : _value(static_cast<Unit>(0)), _str("0")
{}


template<typename Unit, eOperandType Type>
Operand<Unit, Type>& Operand<Unit, Type>::operator=(Operand const & rhs)
{
    if (this != &rhs)
    {
        this->_value = rhs._value;
        this->_str = rhs._str;
    }
    return (*this);
}

template<typename Unit, eOperandType Type>
int Operand<Unit, Type>::getPrecision( void ) const
{
    return (static_cast<int>(Type));
}

template<typename Unit, eOperandType Type>
eOperandType Operand<Unit, Type>::getType( void ) const
{
    return (Type);
}

template<typename Unit, eOperandType Type>
std::string const & Operand<Unit, Type>::toString( void ) const
{
    return (_str);
}

template<typename Unit, eOperandType Type>
eOperandType Operand<Unit, Type>::chooseType( IOperand const & lhs, IOperand const & rhs ) const
{
    eOperandType new_type = lhs.getType();
    if (lhs.getPrecision() < rhs.getPrecision())
        new_type = rhs.getType();
    return (new_type);
}

template<typename Unit, eOperandType Type>
IOperand const * Operand<Unit, Type>::operator+( IOperand const & rhs ) const
{
    double result;
    eOperandType type = chooseType(*this, rhs);

    result = std::stod(this->toString()) + std::stod(rhs.toString());

    OperandFactory factory;
    return (factory.createOperand(type, std::to_string(result)));
}

template<typename Unit, eOperandType Type>
IOperand const * Operand<Unit, Type>::operator-( IOperand const & rhs ) const
{
    double result;
    eOperandType type = chooseType(*this, rhs);

    result = std::stod(this->toString()) - std::stod(rhs.toString());

    OperandFactory factory;
    return (factory.createOperand(type, std::to_string(result)));
}


template<typename Unit, eOperandType Type>
IOperand const * Operand<Unit, Type>::operator*( IOperand const & rhs ) const
{
    double result;
    eOperandType type = chooseType(*this, rhs);

    result = std::stod(this->toString()) * std::stod(rhs.toString());

    OperandFactory factory;
    return (factory.createOperand(type, std::to_string(result)));
}

template<typename Unit, eOperandType Type>
IOperand const * Operand<Unit, Type>::operator/( IOperand const & rhs ) const
{
    double result;
    eOperandType type = chooseType(*this, rhs);

    if (std::stod(rhs.toString()) == 0)
        throw ModDivNullException();

    result = std::stod(this->toString()) / std::stod(rhs.toString());

    OperandFactory factory;
    return (factory.createOperand(type, std::to_string(result)));
}

template<typename Unit, eOperandType Type>
IOperand const * Operand<Unit, Type>::operator%( IOperand const & rhs ) const
{
    double result;
    eOperandType type = chooseType(*this, rhs);

    if (std::stod(rhs.toString()) == 0)
        throw ModDivNullException();

    if (type == Int8 || type == Int16 || type == Int32)
        result = static_cast<long long>(std::stod(this->toString())) % static_cast<long long>(std::stod(rhs.toString()));
    else
        result = std::fmod(std::stod(this->toString()), std::stod(rhs.toString()));

    OperandFactory factory;
    return (factory.createOperand(type, std::to_string(result)));
}

template<typename Unit, eOperandType Type>
bool Operand<Unit, Type>::operator==(IOperand const & rhs) const
{
    if (this->getType() == rhs.getType() && this->toString() == rhs.toString())
        return (true);

    return (false);
}

template class Operand<int8_t, Int8>;
template class Operand<int16_t, Int16>;
template class Operand<int, Int32>;
template class Operand<float, Float>;
template class Operand<double, Double>;
