#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <array>
#include "IOperand.hpp"
#include "MyExceptions.hpp"

#define VALUE_PATTERN R"(^\s*(int8|int16|int32)\((-?\d+)\)\s*$|^\s*(float|double)\((-?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?)\)\s*$)"

enum Instruction {
    Comment,
    Push,
    Pop,
    Dump,
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


std::vector<std::string>	ParseLine(std::string line);
eOperandType				parseType(const std::string &cmd);
Instruction					parseInstruction(const std::string &cmd);
Instruction					checkOther(std::string args, Instruction instr);
void						checkFormats(std::string args);


#endif