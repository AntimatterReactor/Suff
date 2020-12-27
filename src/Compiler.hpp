#include <string>
#include <vector>
#include <sstream>
#include "Token.hpp"

std::string compileToC(std::vector<Token> lex)
{
    std::ostringstream result;

    result << "#include <stdio.h>\n\n"
           << "int main(){\nchar ptv[30000] = {0};\nint ptr = 0;\n";

    for (auto s : lex)
    {
        switch (s.object)
        {
        case '>':
            result << "ptr += " << std::to_string(s.ocount) << ";\n";
            break;

        case '<':
            result << "ptr -= " << std::to_string(s.ocount) << ";\n";
            break;

        case '+':
            result << "ptv[ptr]+=" << std::to_string(s.ocount) << ";\n";
            break;

        case '-':
            result << "ptv[ptr] -= " << std::to_string(s.ocount) << ";\n";
            break;

        case '.':
            for (size_t i = 0; i < s.ocount; i++)
            {
                result << "putchar(ptv[ptr]);\n";
            }
            break;

        case ',':
            for (size_t i = 0; i < s.ocount; i++)
            {
                result << "ptv[ptr] = getchar();\n";
            }
            break;

        case '[':
            for (size_t i = 0; i < s.ocount; i++)
            {
                result << "while(ptv[ptr]){\n";
            }
            break;

        case ']':
            for (size_t i = 0; i < s.ocount; i++)
            {
                result << "}\n";
            }
            break;
        }
    }

    result << "}";

    return result.str();
}