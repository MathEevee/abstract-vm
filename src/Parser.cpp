#include "Parser.hpp"

std::vector<std::string>    ParseLine(std::string line)
{
    std::vector<std::string> args;
    size_t start = 0;
    size_t end = line.find(' ');

    while (end != std::string::npos)
    {
        args.push_back(line.substr(start, end - start));
        start = end + 1;
        end = line.find(' ', start);
    }
    args.push_back(line.substr(start));

    for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
    {
        std::cout << "verif " << *it << std::endl;
    }

    return args;
}
