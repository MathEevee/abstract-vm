#ifndef STACKOPERAND_HPP
#define STACKOPERAND_HPP

#include <stack>
#include <vector>
#include "Operand.hpp"
#include "../Parser/Parser.hpp"

class StackOperand {
    private :
    
        std::stack<const IOperand *>    _stack;

        StackOperand& operator=(StackOperand const & rhs);


        bool    comment(void);
        bool    exit(void);
        bool    push(std::string args);
        bool    pop(void);
        bool    dump(void);
        bool    rdump(void); //bonus
        bool    swap(void); //bonus
        bool    min(void); //bonus
        bool    max(void); //bonus
        bool    assert(std::string arg);
        bool    print();
        bool    unknow(std::string args);
        bool    search_operator(Instruction instr);
        bool    calc_operator(const IOperand* (IOperand::*my_operator)(const IOperand&) const, Instruction instr);
        bool    createElem(std::string args, const IOperand *&new_elem) const;

    public :
        StackOperand(StackOperand const & rhs);

        StackOperand();
        ~StackOperand();
        bool        checkOp(std::vector<std::string> args, error &bonus);
        bool        execInstr(std::string args, Instruction instr);
};

#endif