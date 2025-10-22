#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <climits>
#include <stack>
#include "IOperand.hpp"
#include "MyExceptions.hpp"
#include "Operand.hpp"
#include "OperandFactory.hpp"
#include "Utils.hpp"
#include "Parser.hpp"
#include "StackOperand.hpp"

void test(int a)
{
    if (a == 0)
        throw ModDivNullException();
}

void test_f()
{
    int a = 0;
    try {
        test(a);
    }
    catch (const AVMExceptions &e)
    {
        e.handle();
    }
    try {
        test(a);
    }
    catch (const AVMExceptions &e)
    {
        e.handle();
    }
}

void    open_file(const char *av)
{
    std::ifstream input;
    input.open(av);
    if (!input.is_open())
        throw CantOpenFile();
    std::string line = "";
    std::vector<std::string> parse_line;
    StackOperand my_stack;
    while (getline(input, line, '\n'))
    {
        try {
            parse_line = ParseLine(line);
            my_stack.checkOp(parse_line);

        }
        catch (const AVMExceptions &e)
        {
            e.handle();
            continue;
        }
    }
}

void    open_term(void)
{
    try {

        OperandFactory factory;
        
        const IOperand* a = factory.createOperand(Int8, std::to_string(10));
        const IOperand* b = factory.createOperand(Int8, std::to_string(50));
        
        const IOperand *result_mult = a->operator*(*b);
        
        std::cout << a->toString() << " * " << b->toString() << " = " << result_mult->toString() << std::endl;
        
        delete a;
        delete b;
        delete result_mult;
    }
    catch (const AVMExceptions &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::string line = "";
    int i = 0;
    while (getline(std::cin, line, '\n'))
    {
        i++;
    }

}

int main(int ac, char **av)
{
    try
    {
        if (ac == 2)
            open_file(av[1]);
        else if (ac == 1)
            open_term();
        else
            throw TooManyParams();
    }
    catch (const AVMExceptions &e)
    {
        e.handle();
    }
    return 1;
}
