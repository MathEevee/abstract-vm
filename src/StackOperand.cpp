#include "StackOperand.hpp"

StackOperand::StackOperand()
{}


StackOperand::~StackOperand()
{
    while (!_stack.empty())
    {
        delete _stack.top();
        _stack.pop();
    }
}

void     StackOperand::comment(std::vector<std::string> args)
{
    // OperandFactory factory;
    (void) args;
    // const IOperand* a = factory.createOperand(Float, std::to_string(841564512135143.15614685120));
    // this->_stack.push(a);
}

void    StackOperand::execInstr(std::vector<std::string> args, bool in_term, Instruction instr)
{
    (void) args;
    (void) in_term;
    switch (instr)
    {
        case Push:
            break;
        case Pop:
            break;
        case Dump:
            break;
        case Assert:
            break;
        case Add:
            break;
        case Sub:
            break;
        case Mul:
            break;
        case Div:
            break;
        case Mod:
            break;
        case Print:
            break;
        case Comment:
            break;
        case Exit:
            std::exit(0);
        default:
        {
            //throw
        }
    }
}


void     StackOperand::checkOp(std::vector<std::string> args, bool in_term)
{
    if (args.empty())
        return ;

    Instruction tmp = UNKNOWN;
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
    {
        if (args.empty())
            break;
        tmp = parseInstruction(*it);
        tmp = checkOther(in_term, args, tmp);
        if (tmp == Comment || tmp == Exit)
        {
            execInstr(args, in_term, tmp);
            std::cout << "is comm" << std::endl;
            break;
        }
        it = args.erase(it);
        execInstr(args, in_term, tmp);
        if (tmp == Exit)
            std::exit(0);
        std::cout << "args = " << *it << "| instr = " << tmp << std::endl;
        // std::cout << *it << std::endl;
    }
    // tmp = checkOther(in_term, args, tmp);
}

