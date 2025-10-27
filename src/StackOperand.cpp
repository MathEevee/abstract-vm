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

bool    StackOperand::execInstr(std::string args, Instruction instr)
{
    // (void) args;
    std::cout << "in exec instr args = " << args << std::endl;
    std::cout << "in exec instr instr = " << instr << std::endl;
    switch (instr)
    {
        case Push:
            // break;
        case Pop:
            // break;
        case Dump:
            // break;
        case Assert:
            // break;
        case Add:
            // break;
        case Sub:
            // break;
        case Mul:
            // break;
        case Div:
            // break;
        case Mod:
            // break;
        case Print:
            // break;
        case Comment:
            // break;
        case Exit:
            // break;
        default:
        {
        }
    }
    return (true);
}


bool     StackOperand::checkOp(std::vector<std::string> args, bool in_term)
{
    if (args.empty())
        return false;

    Instruction tmp = UNKNOWN;
    std::string val = "";
    bool exec = false;
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end();)
    {
        tmp = parseInstruction(*it);
        it = (args.erase(it));
        if (tmp == Push || tmp == Assert)
        {
            try {

                val = checkFormats(*it);
            // if (val.empty())
            // {
                // it = (args.erase(it));
                // continue;
            // }
            }
            catch (const AVMExceptions &e){
                std::cerr << e.what() << std::endl;
                continue;
            }
            exec = execInstr(*it, tmp);
            if (exec == true && !args.empty())
                it = (args.erase(it));
        }
        else
            tmp = checkOther(in_term, *it, tmp);
        
        std::cout << "Je lis ici : " << *it << " | " << tmp << std::endl;
        if (tmp == Exit && in_term == false)
            return (true);

    }
        // execInstr(args, in_term, tmp);
    return (false);
}

