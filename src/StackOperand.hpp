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
        bool push(std::string args);
        bool pop(void);
        void dump(void);
        void assert(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        bool add();
        bool sub();
        void mul(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void div(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void mod(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void print(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void exit(std::stack<const IOperand *> &stack, std::vector<std::string> args);

    public :
        void print_all();


        StackOperand();
        ~StackOperand();
        bool        checkOp(std::vector<std::string> args, error &bonus);
        bool        execInstr(std::string args, Instruction instr);


};

#endif