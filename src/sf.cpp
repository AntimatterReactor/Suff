#include <string>
#include <fstream>
#include <vector>

#include "Lexer.hpp"
#include "Compiler.hpp"
#include "Token.hpp"

int main(int argc, char *argv[])
{
    std::vector<Token> lex;
    if (argc < 2)
    {
        printf("Usage: Suff.exe [file-path] [output-file-name].c");
        return 0;
    }
    else if (argc = 2)
    {
        lex = lexer(argv[1]);
        std::ofstream fileout("a.c");
        fileout << compileToC(lex);
        fileout.close();
    }
    else if (argc = 3)
    {
        lex = lexer(argv[1]);
        std::ofstream fileout(argv[2]);
        fileout << compileToC(lex);
        fileout.close();
    }

    return 0;
}