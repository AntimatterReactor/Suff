#include <string>
#include <vector>
#include <iostream>
#include "Token.hpp"

std::string compileToC(std::vector<Token> lex)
{
    std::string presult;
    for (auto s : lex)
    {
        if (s.object == '>')
        {
            presult += "ptr += " + std::to_string(s.ocount);
            presult += ";\n";
        }
        else if (s.object == '<')
        {
            presult += "ptr -= " + std::to_string(s.ocount);
            presult += ";\n";
        }
        else if (s.object == '+')
        {
            presult += "ptv[ptr]+=" + std::to_string(s.ocount);
            presult += ";\n";
        }
        else if (s.object == '-')
        {
            presult += "ptv[ptr] -= " + std::to_string(s.ocount);
            presult += ";\n";
        }
        else if (s.object == '.')
        {
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "putchar(ptv[ptr]);\n";
            }
        }
        else if (s.object == ',')
        {
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "ptv[ptr] = getchar();\n";
            }
        }
        else if (s.object == '[')
        {
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "while(ptv[ptr]){\n";
            }
        }
        else if (s.object == ']')
        {
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "}\n";
            }
        }
    }
    std::string result;

    result += "int main(){\n\n";
    result += "char ptv[30000] = {0};\nint ptr = 0;\n";
    result += presult;
    result += "\n}";

    return result;
}