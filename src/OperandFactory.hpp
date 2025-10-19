#pragma once
#include "IOperand.hpp"
#include <limits>
#include <string>
#include <cmath>
#include <cfloat>
#include <iostream>

class OperandFactory
{
    public :
        IOperand const *createOperand(eOperandType type, std::string const &value) const;
        IOperand const *promoteOperand(IOperand const &a, IOperand const &b) const;
};