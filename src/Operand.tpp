#include "Operand.hpp"
#include <iostream>
#include "OperandFactory.hpp"

template<typename Unit, eOperandType Type>
Operand<Unit, Type>::Operand(std::string const &value)
{
    //add verif to check overflow
    _value = static_cast<Unit>(std::stod(value));
    _str = value;
    std::cout << "check ici : " << value << " | " << this->getPrecision() << std::endl;
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
std::string const & Operand<Unit, Type>::toString( void ) const // String representation of the instance
{
    return (_str);
}

template<typename Unit, eOperandType Type>
IOperand const * Operand<Unit, Type>::operator+( IOperand const & rhs ) const // Sum
{
    double result;
    eOperandType type = this->getType();

    if (this->getPrecision() < rhs.getPrecision())
        type = rhs.getType();

    result = std::stod(this->toString()) + std::stod(rhs.toString()); //voir overflow

    OperandFactory factory;
    return (factory.createOperand(type, std::to_string(result)));
}

template class Operand<int8_t, Int8>;
template class Operand<short, Int16>;
template class Operand<int, Int32>;
template class Operand<float, Float>;
template class Operand<double, Double>;

// template<typename Unit, eOperandType Type>
// IOperand const * Operand<Unit, Type>::operator-( IOperand const & rhs ) const // Difference
// {
//     double result;
//     eOperandType type = this->getType();

//     if (this->getPrecision() < rhs.getPrecision())
//         type = rhs.getType();

//     result = std::stod(this->toString()) - std::stod(rhs.toString());
//     return (createOperand(type, std::to_string(result)));
// }

// template<typename Unit, eOperandType Type>
// IOperand const * Operand<Unit, Type>::operator*( IOperand const & rhs ) const // Product
// {}

// template<typename Unit, eOperandType Type>
// IOperand const * Operand<Unit, Type>::operator/( IOperand const & rhs ) const // Quotient
// {}

// template<typename Unit, eOperandType Type>
// IOperand const * Operand<Unit, Type>::operator%( IOperand const & rhs ) const // Modulo
// {}