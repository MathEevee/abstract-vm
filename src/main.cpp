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
        e.what();
    }
    try {
        test(a);
    }
    catch (const AVMExceptions &e)
    {
        e.what();
    }
}

void    open_file(std::ifstream &input, error &bonus)
{
    bool    exit = false;

    std::vector<std::string> parse_line;
    StackOperand my_stack;
    std::string line = "";
    int i = 0;
    while (getline(input, line, '\n'))
    {
        parse_line = ParseLine(line);
        // try{
        exit = my_stack.checkOp(parse_line, false, bonus);
        if (bonus == Manda_failed)
        {
            std::cout << "check ? = " << bonus << std::endl;
            break;
        }
        // }
        // catch (const AVMExceptions &e){
        //     std::cerr << e.what() << std::endl;
        // }
        if (exit == true)
            break;
        i++;
    }
    if (exit == false && bonus != Manda_failed)
        throw NoExitException();
    my_stack.print_all(); //suppr
}

void    open_term(error &bonus)
{
    // try {

    //     OperandFactory factory;
        
    //     const IOperand* a = factory.createOperand(Int8, std::to_string(10));
    //     const IOperand* b = factory.createOperand(Int8, std::to_string(50));
        
    //     const IOperand *result_mult = a->operator*(*b);
        
    //     std::cout << a->toString() << " * " << b->toString() << " = " << result_mult->toString() << std::endl;

            
    //     delete a;
    //     delete b;
    //     delete result_mult;
    // }
    // catch (const AVMExceptions &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    bool    exit = false;
    std::vector<std::string> parse_line;
    StackOperand my_stack;
    std::string line = "";
    int i = 0;
    while (getline(std::cin, line, '\n'))
    {

        if (line == ";;" && exit == false)
            throw NoExitException();
        else if (line == ";;" && exit == true)
            return;
        parse_line = ParseLine(line);
        exit = my_stack.checkOp(parse_line, true, bonus);
        if (bonus == Manda_failed)
        {
            std::cout << "je veux check :" << std::endl;
            break;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    try
    {
        error    bonus = Manda_succes;
        if (ac == 2)
        {
            std::ifstream input;
            input.open(av[1]);
            if (!input.is_open())
                throw CantOpenFile();
            open_file(input, bonus);
        }
        else if (ac == 1)
            open_term(bonus);
        else
            throw TooManyParams();
    }
    catch (const AVMExceptions &e)
    {
        std::cout << e.handle() << std::endl;
    }
    return 1;
}
