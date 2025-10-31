#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"

class OperandFactory
{
    public :
        IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif