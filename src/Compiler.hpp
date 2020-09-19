#include <string>
#include <iostream>

#define string std::string

string cCompile(string lines)
{
    string returnValue = "char ptrVal[30000] = {0};\nunsigned int ptr = 0;\n";
    size_t linesLength = lines.length();
    for (size_t i = 0; i < linesLength; ++i)
    {
        switch (lines[i])
        {
        case '+':
            returnValue = returnValue + "++ptrVal[ptr];\n";
            break;

        case '-':
            returnValue = returnValue + "--ptrVal[ptr];\n";
            break;

        case '>':
            returnValue = returnValue + "++ptr;\n";
            break;

        case '<':
            returnValue = returnValue + "--ptr;\n";
            break;

        case '.':
            returnValue = returnValue + "putchar(ptrVal[ptr]);\n";
            break;

        case ',':
            returnValue = returnValue + "ptrVal[ptr]=getchar();\n";
            break;

        case '[':
            returnValue = returnValue + "while (ptrVal[ptr]) {\n";
            break;

        case ']':
            returnValue = returnValue + "}\n";
            break;

        default:
            break;
        }
    }
    returnValue = "#include <stdio.h>\nint main(){\n" + returnValue + "}";
    return returnValue;
}