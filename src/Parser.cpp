#include "Parser.hpp"

Instruction parseInstruction(const std::string &cmd)
{
    static const std::array<std::pair<const char*, Instruction>, 11> table = {{
    {"push", Push},
    {"pop", Pop},
    {"dump", Dump},
    {"assert", Assert},
    {"add", Add},
    {"sub", Sub},
    {"mul", Mul},
    {"div", Div},
    {"mod", Mod},
    {"print", Print},
    {"exit", Exit}}};

    for (auto &pair : table)
    {
        const std::string &name = pair.first;
        Instruction instr = pair.second;
        if (cmd == name)
            return (instr);
    }
    return (UNKNOWN);
}


bool checkFormats(std::string args, Instruction instr)
{
    (void) args;
    (void) instr;
    return (true);
}


Instruction checkOther(bool in_term, std::string args, Instruction instr)
{
    if (instr == Comment)
        return (instr);
    if (instr == Exit && args[0] == ';')
        return (instr);
    if (args[0] == ';' && in_term == false)
        return (Comment);
    return (instr);
}

eOperandType parseType(const std::string &cmd)
{
    static const std::array<std::pair<const char*, eOperandType>, 5> typeTable = {{
        {"int8",  Int8},
        {"int16", Int16},
        {"int32", Int32},
        {"float", Float},
        {"double", Double}
    }};
    for (auto &pair : typeTable)
    {
        const std::string &name = pair.first;
        eOperandType type = pair.second;
        if (cmd == name)
            return (type);
    }
    return (DOESNOTEXIST);
}



std::vector<std::string>    ParseLine(std::string line)
{
    std::vector<std::string> args;
    std::string              str = "";
    bool                     is_com = false;

    for (std::string::iterator it = line.begin(); it != line.end(); it++)
    {
        if (*it == ';' && is_com == false)
        {
            if (str != "")
                args.push_back(str);
            if (*(it + 1) == ';' && (*it) == ';')
            {
                args.push_back(";;");
                it += 2;
            }
            else
                is_com = true;
            str = "";
        }
        if (is_com == false && *it == ' ')
        {
            if (str != "")
                args.push_back(str);
            str = "";
        }
        if (it == line.end())
            break;
        if (is_com == false && *it == ' ')
            continue;
        str += *it;
    }
    if (str != "")
        args.push_back(str);
    return (args);
}
