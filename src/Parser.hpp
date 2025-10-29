#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <array>
#include "IOperand.hpp"
#include "MyExceptions.hpp"


// #define PUSH_DF R"(^(push) (\w+)\(([-+]?\d+(\.\d*)?([eE][-+]?\d+)?)\)$)"
// #define PUSH_INT R"(^(push) (\w+)\(([-+]?\d+)\)$)"

// #define ASSERT_DF R"(^(assert) (\w+)\(([-+]?\d+(\.\d*)?([eE][-+]?\d+)?)\)$)"
// #define ASSERT_INT R"(^(assert) (\w+)\(([-+]?\d+)\)$)"

// #define INT_PATTERN R"(^\w+ (int(8|16|32))\((-?\d+)\)$)"

// #define OTHER_PATTERN R"(^\w+ (float|double)\((-?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?|\.\d+(?:[eE][-+]?\d+)?)\)$)"

// #define VALUE_PATTERN R"(^\w+ ((?:int(8|16|32))\((-?\d+)\)|(float|double)\((-?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?)\))$)"

#define VALUE_PATTERN R"(^\s*(int8|int16|int32)\((-?\d+)\)\s*$|^\s*(float|double)\((-?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?)\)\s*$)"

enum Instruction {
    Comment,
    Push,
    Pop,
    Dump,
    Assert,
    Add,
    Sub,
    Mul,
    Div,
    Mod,
    Print,
    Exit,
	UNKNOWN
};


std::vector<std::string>	ParseLine(std::string line);
eOperandType				parseType(const std::string &cmd);
Instruction					parseInstruction(const std::string &cmd);
Instruction					checkOther(std::string args, Instruction instr);
void						checkFormats(std::string args);


#endif