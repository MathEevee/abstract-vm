#include <iostream>
#include <fstream>
#include <stack>
#include "IOperand.hpp"
#include "MyExceptions.hpp"
#include "Operand.hpp"
#include "OperandFactory.hpp"


void test(int a)
{
    if (a == 0)
        throw ModNullException();
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
    while (getline(input, line, '\n'))
    {
        std::cout << line << std::endl;
        test_f();
    }
}
template <typename T>
void    open_term(void)
{
    std::string line = "";
    int i = 0;
    std::stack<T> my_stack;
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
        if (ac == 2)
            open_file(av[1]);
        else if (ac == 1)
            open_term<IOperand *>();
        else
            throw TooManyParams();
    }
    catch (const AVMExceptions &e)
    {
        e.handle();
    }
    return 1;
}
