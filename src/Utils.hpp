#ifndef UTILS_HPP
# define UTILS_HPP

#include <limits>
#include <string>
#include <cmath>
#include <cfloat>
#include <iostream>
#include "IOperand.hpp"

extern int g_line_error;


void            checkRange(eOperandType type, std::string const &value);
void            increment();

#endif