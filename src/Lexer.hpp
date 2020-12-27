#include <fstream>
#include <string>
#include <vector>

#include "Token.hpp"

std::vector<Token> lexer(char *fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        throw "can't open file";
    }

    Token placeholder;
    std::vector<Token> result;
    char plc;

    file.get(placeholder.object);

    while (file.get(plc))
    {
        if (plc == placeholder.object)
        {
            placeholder.ocount++;
        }
        else
        {
            result.push_back(placeholder);
            placeholder.object = plc;
            placeholder.ocount = 1;
        }
    }

    result.push_back(placeholder);

    return result;
}