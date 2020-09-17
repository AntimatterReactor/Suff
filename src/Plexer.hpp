#include <string>
#include <map>
#include <iostream>
#include <cstdio>

void Plexer(std::string lines)
{
    size_t linesLength = lines.length();

    unsigned int pointer = 0;
    unsigned int loops = 0;
    std::map<unsigned int, unsigned int> pointerValue;
    std::map<unsigned int, unsigned int> loopsValue;

    for (size_t i = 0; i < linesLength; ++i)
    {
        switch (lines[i])
        {
        case '>':
            pointer++;
            break;

        case '<':
            pointer--;
            break;

        case '+':
            pointerValue[pointer]++;
            break;

        case '-':
            pointerValue[pointer]--;
            break;

        case '.':
            putchar(pointerValue[pointer]);
            break;

        case ',':
            pointerValue[pointer] = getchar();
            break;

        case '[':
            loopsValue[loops++] = i;
            break;

        case ']':
            if (pointerValue[pointer] > 0)
            {i = loopsValue[loops-1];}
            else
            {loops--;}
            break;

        default:
            break;
        }
    }
    
}