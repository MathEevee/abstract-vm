#ifndef STACKOPERAND_HPP
#define STACKOPERAND_HPP

#include <stack>
#include <vector>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Parser.hpp"

class StackOperand {
    private :
        std::stack<const IOperand *> _stack;
        void     comment(std::vector<std::string> args);
        void     push(std::stack<IOperand> stack, std::vector<std::string> args);
        void     pop(std::stack<IOperand> stack, std::vector<std::string> args);
        void     dump(std::stack<IOperand> stack, std::vector<std::string> args);
        void     assert(std::stack<IOperand> stack, std::vector<std::string> args);
        void     add(std::stack<IOperand> stack, std::vector<std::string> args);
        void     sub(std::stack<IOperand> stack, std::vector<std::string> args);
        void     mul(std::stack<IOperand> stack, std::vector<std::string> args);
        void     div(std::stack<IOperand> stack, std::vector<std::string> args);
        void     mod(std::stack<IOperand> stack, std::vector<std::string> args);
        void     print(std::stack<IOperand> stack, std::vector<std::string> args);
        void     exit(std::stack<IOperand> stack, std::vector<std::string> args);
    public :
        StackOperand();
        ~StackOperand();
        void        checkOp(std::vector<std::string> args, bool in_term);
        void        execInstr(std::vector<std::string> args, bool in_term, Instruction instr);


};

#endif