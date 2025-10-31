#include "./Operand/IOperand.hpp"
#include "./Exceptions/MyExceptions.hpp"
#include "./Operand/Operand.hpp"
#include "./Operand/OperandFactory.hpp"
#include "./Utils/Utils.hpp"
#include "./Parser/Parser.hpp"
#include "./Operand/StackOperand.hpp"

void    check_exit(bool exit)
{
    if (exit == false)
        throw NoExitException();
}

bool    in_loop(std::string line, StackOperand &my_stack, error &bonus)
{
    std::vector<std::string> parse_line;

    increment();
    parse_line = ParseLine(line);
    return (my_stack.checkOp(parse_line, bonus));
}

void    open_file(char *file, StackOperand my_stack, error &bonus, std::string line, bool exit)
{
    std::ifstream input;
    input.open(file);
    if (!input.is_open())
        throw CantOpenFile();

    while (getline(input, line, '\n'))
    {
        exit = in_loop(line, my_stack, bonus);
        if (bonus == Manda_failed || exit == true)
            break;
    }
    increment();
    if (bonus != Manda_failed)
        check_exit(exit);
}

void    open_term(error &bonus, StackOperand &my_stack, std::string line, bool exit)
{
    while (getline(std::cin, line, '\n'))
    {
        if (line == ";;")
            break;
        if (exit == false)        
            exit = in_loop(line, my_stack, bonus);
    }
    increment();
    check_exit(exit);
}

int main(int ac, char **av)
{
    try
    {
        error    bonus = Manda_succes;
        std::string line = "";
        StackOperand my_stack;

        if (ac == 2)
            open_file(av[1], my_stack, bonus, line, false);
        else if (ac == 1)
            open_term(bonus, my_stack, line, false);
        else
            throw TooManyParams();
    }
    catch (const AVMExceptions &e)
    {
        e.handle();
    }
    return (0);
}
