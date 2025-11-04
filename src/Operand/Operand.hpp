#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "OperandFactory.hpp"
#include "../Exceptions/MyExceptions.hpp"
#include "../Parser/Parser.hpp"


template<typename Unit, eOperandType Type>
class Operand : public IOperand
{
    private :
        Unit            _value;
        std::string     _str;

        Operand(Operand const & rhs);
        Operand(void);
        Operand<Unit, Type>& operator=(Operand const & rhs);

    public :
        Operand(std::string const &value);
        
        int getPrecision( void ) const;
        eOperandType getType( void ) const;

        IOperand const * operator+( IOperand const & rhs ) const;

        IOperand const * operator-( IOperand const & rhs ) const;

        IOperand const * operator*( IOperand const & rhs ) const;

        IOperand const * operator/( IOperand const & rhs ) const;

        IOperand const * operator%( IOperand const & rhs ) const;

        bool operator==(IOperand const & rhs) const;

        std::string const & toString( void ) const;

        eOperandType chooseType( IOperand const & lhs, IOperand const & rhs ) const;

};
    
#include "Operand.tpp"

#endif