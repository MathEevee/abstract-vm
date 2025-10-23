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
        {
            std::cout << "ici ?" << std::endl;
            std::exit(0);
        }
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
    if (!args[0].empty())
    {
        tmp = parseInstruction(args[0]);
        tmp = checkOther(in_term, args[0], tmp);
        std::cout << args[0] << "|" << tmp << std::endl;
        if (tmp == Exit)
            return;
        // execInstr(args, in_term, tmp);
    }
    // std::cout << "check = " << tmp << std::endl;
    // if (tmp == Comment || tmp == Exit)
    // {
    //     execInstr(args, in_term, tmp);
    //     break;
    // }
    // if (args.empty())
        // break;
    // std::cout << "args = " << *it << "| instr = " << tmp << std::endl;
    // std::cout << *it << std::endl;
    // tmp = checkOther(in_term, args, tmp);
}

