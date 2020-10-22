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

    std::string pls;
    Token placeholder;
    std::vector<Token> result;
    char plc;

    while (file.get(plc))
    {
        pls.push_back(plc);
    }

    file.close();

    placeholder.object = pls[0];
    placeholder.ocount = 1;

    for (size_t i = 1; i < pls.length(); i++)
    {
        if (pls[i] == placeholder.object)
        {
            placeholder.ocount++;
        }
        else
        {
            result.push_back(placeholder);
            placeholder.object = pls[i];
            placeholder.ocount = 1;
        }
    }

    result.push_back(placeholder);

    return result;
}