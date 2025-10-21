#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "OperandFactory.hpp"
#include "MyExceptions.hpp"



template<typename Unit, eOperandType Type>
class Operand : public IOperand
{
    private :
        Unit            _value;
        std::string     _str;
    public :
        Operand(std::string const &value);
        int getPrecision( void ) const; // Precision of the type of the instance
        eOperandType getType( void ) const; // Type of the instance

        IOperand const * operator+( IOperand const & rhs ) const; // Sum

        IOperand const * operator-( IOperand const & rhs ) const; // Difference

        IOperand const * operator*( IOperand const & rhs ) const; // Product

        IOperand const * operator/( IOperand const & rhs ) const; // Quotient

        IOperand const * operator%( IOperand const & rhs ) const; // Modulo

        std::string const & toString( void ) const; // String representation of the instance
};
    
#include "Operand.tpp"

#endif