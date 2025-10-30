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
        std::cout << "my_value = " << print_tmp->toString() << std::endl;
        tmp.pop();
    }
}

bool     StackOperand::comment(void)
{
    return (true);
}

bool StackOperand::createElem(std::string args, const IOperand *&new_elem) const
{
    std::smatch matches;
    std::regex pattern(VALUE_PATTERN);
    const OperandFactory new_operand;
    try {

        if (!std::regex_match(args, matches, pattern))
            throw LexicalErrorException();
        eOperandType type = parseType(matches[1]);
        if (matches[1] == "")
        {
            type = parseType(matches[3]);
            new_elem = new_operand.createOperand(type, matches[4]);
        }
        else
            new_elem = new_operand.createOperand(type, matches[2]);
        return (true);
    }
    catch (const AVMExceptions &e)
    {
        if (e.handle() != Bonus)
            return (false);
        return (true);
    }
}

bool     StackOperand::push(std::string args)
{
    const IOperand *new_elem = NULL;
    bool res = createElem(args, new_elem);
    if (new_elem == NULL && res == false)
        return (false);
    if (new_elem != NULL)
        this->_stack.push(new_elem);
    return (true);
}

bool StackOperand::assert(std::string args)
{
    const IOperand *check = NULL;
    bool res = createElem(args, check);
    if (check == NULL && res == false)
        return (false);
    try {
        if (*check == *(this->_stack.top()))
        {
            delete (check);
            return (true);
        }
        else
        {
            delete (check);
            throw AssertFalseException();
        }
    }
    catch (const AVMExceptions &e)
    {
        if (e.handle() == Bonus)
            return (true);
        return (false);
    }
}
    
bool     StackOperand::dump()
{
    std::stack<const IOperand *> tmp = this->_stack;
    int size = 0;

    while (!tmp.empty())
    {
        size = (tmp.top()->toString()).find_last_not_of('0') + 1;
        std::cout << (tmp.top()->toString()).substr(0, size) << std::endl;
        tmp.pop();
    }
    return (true);
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

bool StackOperand::exit(void)
{
    return (true);
}


bool    StackOperand::print()
{
    try {
        if (this->_stack.top()->getType() == Int8)
        {
            std::cout << static_cast<char>(std::atoi((this->_stack.top()->toString().c_str()))) << std::endl;
            return (true);
        }
        else
            throw AssertFalseException();
    }
    catch (const AVMExceptions &e)
    {
        if (e.handle() == Bonus)
            return (true);
        return (false);
    }
    
}

bool    StackOperand::calc_operator(const IOperand* (IOperand::*my_operator)(const IOperand&) const)
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
        const IOperand *result = (b->*my_operator)(*a);
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

bool    StackOperand::search_operator(Instruction instr)
{
    Instruction instructions[5] = {Add, Sub, Mul, Div, Mod};
    IOperand const* (IOperand::*functptr[])(IOperand const&) const = {
        &IOperand::operator+,
        &IOperand::operator-,
        &IOperand::operator*,
        &IOperand::operator/,
        &IOperand::operator%
    };
    int i = 0;
    for (int j = 0; j <= 4; j++)
	{
		if (instr == instructions[j])
			break;
		i++;
	}
    return (calc_operator(functptr[i]));
}


bool    StackOperand::execInstr(std::string args, Instruction instr)
{
    switch (instr)
    {
		case Comment:
			return (comment());
        case Push:
            return (push(args));
        case Pop:
            return (pop());
        case Dump:
            return (dump());
        case Assert:
            return (assert(args));
		case Print:
        	return (print());
		case Exit:
        	return (exit());
        case UNKNOWN:
        {
            throw NotAnInstructionException();
            return (false);
        }
        default:
            return (search_operator(instr));
    }
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
        if (tmp == Comment || tmp == Exit)
                break;
        it = (args.erase(it));
        exec = execInstr(*it, tmp);
        if (tmp == Push || tmp == Assert)
        {
            if (!args.empty())
                it = (args.erase(it));
        }
        if (exec == false)
        {
            if (bonus != Bonus)
                return (Manda_failed);
        }
    }
    if (tmp == Exit)
        return (true);
    return (false);
}

