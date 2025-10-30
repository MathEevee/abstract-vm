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

bool     StackOperand::push(std::string args)
{
    std::smatch matches;
    std::regex pattern(VALUE_PATTERN);
    const OperandFactory new_operand;
    const IOperand *new_elem;
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
        this->_stack.push(new_elem);
        return (true);
    }
    catch (const AVMExceptions &e)
    {
        if (e.handle() != Bonus)
            return (false);
        return (true);
    }
}

bool     StackOperand::dump()
{
    std::stack<const IOperand *> tmp = this->_stack;

    while (!tmp.empty())
    {
        std::cout << tmp.top()->toString() << std::endl;
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

bool     StackOperand::mod()
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
        const IOperand *result = b->operator%(*a);
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

bool    StackOperand::mul()
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
        const IOperand *result = b->operator*(*a);
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

bool    StackOperand::div()
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
        const IOperand *result = b->operator/(*a);
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

bool StackOperand::exit(void)
{
    return (true);
}

bool StackOperand::assert(std::string args)
{

	/*const IOperand *a = NULL;
    const IOperand *b = NULL;
    try {
        if (this->_stack.size() < 2)
            throw ArithmeticException();
        a = this->_stack.top();
        this->_stack.pop();
        b = this->_stack.top();
        this->_stack.pop();
        const IOperand *result = b->operator/(*a);
        delete (a);
        delete (b);
        this->_stack.push(result);
        return (true);
    }*/
	const IOperand *a = NULL;
	std::smatch matches;
    std::regex pattern(VALUE_PATTERN);
    const OperandFactory new_operand;
    const IOperand *new_elem;
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
		a = this->_stack.top();
		if (a == new_elem)
		{
			std::cout << "check ici" << std::endl;
		}
		else
			std::cout << "C'es fo" << std::endl;
	}
	catch (const AVMExceptions &e)
	{
		if (e.handle() == Bonus)
            return (true);
		return (false);
	}
	return (false);
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
        	// break;
		case Exit:
        	return (exit());
		case Add: //op
			return (add());
		case Sub://op
			return (sub());
		case Mul://op
			return (mul());
		case Div://op
			return (div());
		case Mod://op
			return (mod());
        default:
        {
            throw NotAnInstructionException();
            return (false);
        } //mettre le default pour les op et ajouter la case UNKNOW après le exit
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

