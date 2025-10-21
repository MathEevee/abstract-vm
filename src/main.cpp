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
    while (getline(input, line, '\n'))
    {
        try {
            parse_line = ParseLine(line);
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
        
        const IOperand* a = factory.createOperand(Float, std::to_string(841564512135143.15614685120));
        const IOperand* b = factory.createOperand(Double, std::to_string(4851.1564));
        
        // const IOperand *c = a->operator+(*b);
        const IOperand* result = *a + *b;  // ou a->operator+(*b);
        const IOperand *result_mult = a->operator%(*b);
        
        // std::cout << a->toString() << " + " << b->toString() << " = " << result->toString() << std::endl;
        // std::cout << a->toString() << " + " << b->toString() << " = " << c->toString() << std::endl;
        std::cout << a->toString() << " % " << b->toString() << " = " << result_mult->toString() << std::endl;
        
        delete a;
        delete b;
        delete result;
        delete result_mult;
    }
    catch (const AVMExceptions &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::string line = "";
    int i = 0;
    std::stack<IOperand *> my_stack;
    while (getline(std::cin, line, '\n'))
    {
        // std::cout << line << std::endl;
        if (i >= 4)
            test_f();
        i++;
    }

}

int main(int ac, char **av)
{
    try
    {
        // Lexer my_op;
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
