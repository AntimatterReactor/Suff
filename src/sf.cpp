#include <string>
#include <fstream>
#include <vector>

#include "Lexer.hpp"
#include "Compiler.hpp"
#include "Token.hpp"

#define COMDEF "\ngcc a.c\n"
#ifdef __WIN32__
#define RUNDEF "./a.exe\n"
#else
#define RUNDEF "./a.out\n"
#endif

int main(int argc, char *argv[])
{
    std::vector<Token> lex;
    if (argc < 2)
    {
        printf("Usage: Suff.exe [file_path] [output_file_name].c");
        return 0;
    }
    else if (argc = 2)
    {
        lex = lexer(argv[1]);
        std::ofstream fileout("a.c");
        fileout << compileToC(lex);
        fileout.close();
        system(COMDEF);
        system(RUNDEF);
    }
    else if (argc = 3)
    {
        lex = lexer(argv[1]);
        std::ofstream fileout(argv[2]);
        fileout << compileToC(lex);
        fileout.close();

        char pla[10];
        sprintf(pla, "gcc %s -o %s", argv[1], argv[2]);

        system(pla);
    }

    return 0;
}