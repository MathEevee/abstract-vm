#ifndef STACKOPERAND_HPP
#define STACKOPERAND_HPP

#include <stack>
#include <vector>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Parser.hpp"
#include <iostream>
#include <string>

class StackOperand {
    private :
    
        std::stack<const IOperand *>    _stack;

        bool comment(void);
        bool exit(void);
        bool push(std::string args);
        bool pop(void);
        bool dump(void);
        bool assert(std::string arg);
        bool add();
        bool sub();
        bool mul();
        bool div();
        bool mod();
        void print(std::stack<const IOperand *> &stack, std::vector<std::string> args);

    public :
        void print_all();


        StackOperand();
        ~StackOperand();
        bool        checkOp(std::vector<std::string> args, error &bonus);
        bool        execInstr(std::string args, Instruction instr);


};

#endif