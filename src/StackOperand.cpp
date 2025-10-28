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

void     StackOperand::print_all(void)
{
    std::stack<const IOperand *> tmp = this->_stack;
    const IOperand *print_tmp;
    while (!tmp.empty())
    {
        std::cout << tmp.size() << std::endl;
        print_tmp = tmp.top();
        std::cout << "my_value = " << print_tmp->toString() << std::endl;
        tmp.pop();
    }
}

void     StackOperand::comment(void)
{
    return;
}

void     StackOperand::push(std::string args)
{
    std::smatch matches;
    std::regex pattern(VALUE_PATTERN);
    std::regex_match(args, matches, pattern);
    const OperandFactory new_operand;
    const IOperand *new_elem;
    eOperandType type = parseType(matches[1]);
    if (matches[1] == "")
    {
        type = parseType(matches[3]);
        new_elem = new_operand.createOperand(type, matches[4]);
    }
    else
        new_elem = new_operand.createOperand(type, matches[2]);
    this->_stack.push(new_elem);
}

void     StackOperand::dump()
{
    std::stack<const IOperand *> tmp = this->_stack;

    while (!tmp.empty())
    {
        std::cout << tmp.top()->toString() << std::endl;
        tmp.pop();
    }
}

void     StackOperand::pop()
{
    if (this->_stack.empty())
        throw PopEmptyStackException();
    const IOperand *tmp = this->_stack.top();
    this->_stack.pop();
    delete (tmp);
}

bool     StackOperand::add()
{
    if (this->_stack.size() < 2)
        throw ArithmeticException();
    const IOperand *a = this->_stack.top();
    this->_stack.pop();
    const IOperand *b = this->_stack.top();
    this->_stack.pop();
    try {
        const IOperand *result = b->operator+(*a);
        delete (a);
        delete (b);
        this->_stack.push(result);
        return (true);
    }
    catch (const AVMExceptions &e)
    {
        this->_stack.push(b);
        this->_stack.push(a);
        if (e.handle() == Bonus)
            return (true);
        return (false);
    }
}

bool    StackOperand::execInstr(std::string args, Instruction instr)
{
    switch (instr)
    {
        case Push:
            push(args);
            break;
        case Pop:
            pop();
            break;
        case Dump:
            dump();
            break;
        case Assert:
            // break;
        case Add:
            return (add());
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
            comment();
            break;
        case Exit:
            // break;
        default:
        {
        }
    }
    return (true);
}


bool     StackOperand::checkOp(std::vector<std::string> args, bool in_term, error &bonus)
{
    if (args.empty())
        return false;

    Instruction tmp = UNKNOWN;
    bool exec = false;
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end();)
    {
        tmp = parseInstruction(*it);
        it = (args.erase(it));
        if (tmp == Push || tmp == Assert)
        {
            try {
                checkFormats(*it);
            }
            catch (const AVMExceptions &e)
            {
                bonus = e.handle();
                if (bonus != Bonus)
                {
                    bonus = Manda_failed;
                    return (Manda_failed);
                }
            }
            try {

                exec = execInstr(*it, tmp);
                if (exec == true && !args.empty())
                    it = (args.erase(it));
                if (exec == false)
                {
                    bonus = Manda_failed;
                    return (bonus);
                }
            }
            catch (const AVMExceptions &e)
            {
                // bonus = e.handle();
                // if (bonus != Bonus)
                // {
                //     bonus = Manda_failed;
                //     return (Manda_failed);
                // }
            }
        }
        else
        {
            try {
                tmp = checkOther(in_term, *it, tmp);
                exec = execInstr(*it, tmp);
                if (exec == false)
                {
                    bonus = Manda_failed;
                    return (Manda_failed);
                }
            }
            catch (const AVMExceptions &e)
            {
                // bonus = e.handle();
                // if (exec == false && bonus != Bonus)
                // {
                //     bonus = Manda_failed;
                //     return (bonus);
                // }
                // return (Manda_failed);
            }
        }
        if (tmp == Exit && in_term == false)
            return (true);
    }
    if (tmp == Exit)
        return (true);
    return (false);
}

