#ifndef UTILS_HPP
# define UTILS_HPP

#include <limits>
#include <cmath>
#include <fstream>
#include "../Operand/IOperand.hpp"

extern int g_line_error;

void            checkRange(eOperandType type, std::string const &value);
void            increment();

#endif