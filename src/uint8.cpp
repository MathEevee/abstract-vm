#include "uint8.hpp"

int Int8::getPrecision( void ) const // Precision of the type of the instance
{
	return (eOperandType(Int8));
}


eOperandType getType( void ) const; // Type of the instance
IOperand const * operator+( IOperand const & rhs ) const; // Sum
IOperand const * operator-( IOperand const & rhs ) const; // Difference
IOperand const * operator*( IOperand const & rhs ) const; // Product
IOperand const * operator/( IOperand const & rhs ) const; // Quotient
IOperand const * operator%( IOperand const & rhs ) const; // Modulo
std::string const & toString( void ) const; // String representation of the instance
~IOperand( void ) {}