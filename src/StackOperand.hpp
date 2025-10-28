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

        void comment(void);
        void push(std::string args);
        void pop(void);
        void dump(void);
        void assert(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        bool add();
        void sub(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void mul(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void div(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void mod(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void print(std::stack<const IOperand *> &stack, std::vector<std::string> args);
        void exit(std::stack<const IOperand *> &stack, std::vector<std::string> args);

    public :
        void print_all();


        StackOperand();
        ~StackOperand();
        bool        checkOp(std::vector<std::string> args, bool in_term, error &bonus);
        bool        execInstr(std::string args, Instruction instr);


};

#endif