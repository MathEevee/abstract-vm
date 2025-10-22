#include "StackOperand.hpp"

StackOperand::StackOperand()
{}

void     StackOperand::comment(std::vector<std::string> args)
{
    OperandFactory factory;
    (void) args;
    const IOperand* a = factory.createOperand(Float, std::to_string(841564512135143.15614685120));
    this->_stack.push(a);
}

void     StackOperand::checkOp(std::vector<std::string> args, bool in_term)
{
    (void) args;

    if (args[0].empty())
        return;

    Instruction tmp = parseInstruction(args[0]);
    tmp = checkOther(in_term, args, tmp);
}

