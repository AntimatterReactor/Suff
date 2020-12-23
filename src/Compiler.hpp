#include <string>
#include <vector>
#include <iostream>
#include "Token.hpp"
std::string compileToC(std::vector<Token> lex)
{
    std::string presult;
    for (auto s : lex)
    {
        switch (s.object)
        {
        case '>':
            presult += "ptr += " + std::to_string(s.ocount);
            presult += ";\n";
            break;

        case '<':
            presult += "ptr -= " + std::to_string(s.ocount);
            presult += ";\n";
            break;

        case '+':
            presult += "ptv[ptr]+=" + std::to_string(s.ocount);
            presult += ";\n";
            break;

        case '-':
            presult += "ptv[ptr] -= " + std::to_string(s.ocount);
            presult += ";\n";
            break;

        case '.':
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "putchar(ptv[ptr]);\n";
            }
            break;

        case ',':
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "ptv[ptr] = getchar();\n";
            }
            break;

        case '[':
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "while(ptv[ptr]){\n";
            }
            break;

        case ']':
            for (size_t i = 0; i < s.ocount; i++)
            {
                presult += "}\n";
            }
            break;
        }
    }

    std::string result;
    sprintf(result.data(),
            "int main(){\n\nchar ptv[30000] = {0};\nint ptr = 0;\n%s\n}",
            presult);
    return result;
}