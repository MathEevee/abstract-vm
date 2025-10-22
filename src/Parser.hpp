#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <regex>
#include <string>
#include <sstream>

// #define PUSH_DF R"(^(push) (\w+)\(([-+]?\d+(\.\d*)?([eE][-+]?\d+)?)\)$)"
// #define PUSH_INT R"(^(push) (\w+)\(([-+]?\d+)\)$)"

// #define ASSERT_DF R"(^(assert) (\w+)\(([-+]?\d+(\.\d*)?([eE][-+]?\d+)?)\)$)"
// #define ASSERT_INT R"(^(assert) (\w+)\(([-+]?\d+)\)$)"

// enum Instruction {
//     comment,
//     push,
//     pop,
//     dump,
//     assert,
//     add,
//     sub,
//     mul,
//     div,
//     mod,
//     print,
//     exit
// };

std::vector<std::string>            ParseLine(std::string line);
std::map<std::regex, std::string>   RegexGenerator();

#endif