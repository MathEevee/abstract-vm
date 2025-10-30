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

        bool    comment(void);
        bool    exit(void);
        bool    push(std::string args);
        bool    pop(void);
        bool    dump(void);
        bool    assert(std::string arg);
        bool    print();
        bool    unknow();
        bool    search_operator(Instruction instr);
        bool    calc_operator(const IOperand* (IOperand::*my_operator)(const IOperand&) const);
        bool    createElem(std::string args, const IOperand *&new_elem) const;

    public :
        void print_all();


        StackOperand();
        ~StackOperand();
        bool        checkOp(std::vector<std::string> args, error &bonus);
        bool        execInstr(std::string args, Instruction instr);


};

#endif