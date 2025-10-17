#pragma once
#include "IOperand.hpp"

class OperandFactory
{
    public :
        IOperand const *createOperand(eOperandType type, std::string const &value) const;
        IOperand const *promoteOperand(IOperand const &a, IOperand const &b) const;
};