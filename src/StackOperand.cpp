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
        // std::cout << tmp.size() << std::endl;
        print_tmp = tmp.top();
        // std::cout << "my_value = " << print_tmp->toString() << std::endl;
        tmp.pop();
    }
}

bool     StackOperand::comment(void)
{
    return (true);
}

bool     StackOperand::push(std::string args)
{
    /*  checkformat = 
        std::smatch matches;
        std::regex pattern(VALUE_PATTERN);
        if (!std::regex_match(args, matches, pattern))
            throw LexicalErrorException();
    */

    std::smatch matches;
    std::regex pattern(VALUE_PATTERN);
    const OperandFactory new_operand;
    const IOperand *new_elem;
    try {

        if (!std::regex_match(args, matches, pattern))
            throw LexicalErrorException();
         // voir pour mettre dans un if et si !std::regex_match(args, matches, pattern) return false dans un try & catch pour retirer le checkformat et le try catch
        eOperandType type = parseType(matches[1]);
        if (matches[1] == "")
        {
            type = parseType(matches[3]);
            new_elem = new_operand.createOperand(type, matches[4]);
        }
        else
            new_elem = new_operand.createOperand(type, matches[2]);
        this->_stack.push(new_elem);
        return (true);
    }
    catch (const AVMExceptions &e)
    {
        e.handle();
        return (false);
    }
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

bool     StackOperand::pop()
{
    try {
        if (this->_stack.empty())
            throw PopEmptyStackException();
        const IOperand *tmp = this->_stack.top();
        this->_stack.pop();
        delete (tmp);
        return (true);
    }
    catch (const AVMExceptions &e)
    {
        if (e.handle() == Bonus)
            return (true);
        return (false);
    }
}

bool     StackOperand::add()
{
    const IOperand *a = NULL;
    const IOperand *b = NULL;
    try {
        if (this->_stack.size() < 2)
            throw ArithmeticException();
        a = this->_stack.top();
        this->_stack.pop();
        b = this->_stack.top();
        this->_stack.pop();
        const IOperand *result = b->operator+(*a);
        delete (a);
        delete (b);
        this->_stack.push(result);
        return (true);
    }
    catch (const AVMExceptions &e)
    {
        if (b != NULL)
            this->_stack.push(b);
        if (a != NULL)
            this->_stack.push(a);
        if (e.handle() == Bonus)
            return (true);
        return (false);
    }
}

bool    StackOperand::sub()
{
    const IOperand *a = NULL;
    const IOperand *b = NULL;
    try {
        if (this->_stack.size() < 2)
            throw ArithmeticException();
        a = this->_stack.top();
        this->_stack.pop();
        b = this->_stack.top();
        this->_stack.pop();
        const IOperand *result = b->operator-(*a);
        delete (a);
        delete (b);
        this->_stack.push(result);
        return (true);
    }
    catch (const AVMExceptions &e)
    {
        if (b != NULL)
            this->_stack.push(b);
        if (a != NULL)
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
            return (push(args));
        case Pop:
            return (pop());
        case Dump:
            dump();
            break;
        case Assert:
            // break;
        case Add:
            return (add());
        case Sub:
            return (sub());
        case Mul:
            // break;
        case Div:
            // break;
        case Mod:
            // break;
        case Print:
            // break;
        case Comment:
            return (comment());
        case Exit:
            return (true);
            // break;
        default:
        {
            throw NotAnInstructionException();
            return (false);
        }
    }
    return (true);
}


bool     StackOperand::checkOp(std::vector<std::string> args, error &bonus)
{
    if (args.empty())
        return (false);

    Instruction tmp = UNKNOWN;
    bool exec = false;
    for (std::vector<std::string>::iterator it = args.begin(); it != args.end();)
    {
        tmp = parseInstruction(*it);
        if (tmp == UNKNOWN)
        {
            tmp = checkOther(*it, tmp);
            if (tmp == Comment)
                break;
        }
        it = (args.erase(it));
        if (tmp == Push || tmp == Assert)
        {/*voir pour enlever ca avec un return false sur le exec 
            comme ca y'a plus que le erase et on rassemble le reste*/
            /*try {
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
                if (!args.empty())
                    it = (args.erase(it));
                continue;
            }*/
            try {

                exec = execInstr(*it, tmp);
                if (!args.empty())
                    it = (args.erase(it));
                if (exec == false)
                {
                    bonus = Manda_failed;
                    return (Manda_failed);
                }
            }
            catch (const AVMExceptions &e)
            {
                if (e.handle() != Bonus)
                {
                    bonus = Manda_failed;
                    return (Manda_failed);
                }
            }
        }
        else
        {
            try {
                tmp = checkOther(*it, tmp);
                exec = execInstr(*it, tmp);
                if (exec == false)
                {
                    bonus = Manda_failed;
                    return (Manda_failed);
                }
            }
            catch (const AVMExceptions &e)
            {
                if (e.handle() != Bonus)
                    return (Manda_failed);
            }
        }
    }
    if (tmp == Exit)
        return (true);
    return (false);
}

