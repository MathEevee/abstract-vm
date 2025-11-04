#ifndef UTILS_HPP
# define UTILS_HPP

#include <limits>
#include <cmath>
#include <fstream>
#include "../Operand/IOperand.hpp"

#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

enum Instruction {
    Comment,
    Push,
    Pop,
    Dump,
    Rdump,
    Swap,
    Min,
    Max,
    Assert,
    Print,
    Exit,
	UNKNOWN,
    Add,
    Sub,
    Mul,
    Div,
    Mod
};

extern int g_line_error;

void            checkRange(eOperandType type, std::string const &value);
void            increment();
std::string     instruction_to_string(Instruction my_instruction);

#endif