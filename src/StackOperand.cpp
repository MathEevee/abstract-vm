#include "StackOperand.hpp"

StackOperand::StackOperand()
{}

void     StackOperand::comment(std::vector<std::string> args)
{
    OperandFactory factory;
    (void) args;
    const IOperand* a = factory.createOperand(Float, std::to_string(841564512135143.15614685120));
    this->_stack.push(a);
    std::cout << this->_stack.size() << std::endl;
}

void     StackOperand::checkOp(std::vector<std::string> args)
{
    
}

