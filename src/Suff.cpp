#include <string>
#include <vector>
#include <fstream>

#include "Plexer.hpp"

std::string getFileContent(char* filename){
    std::ifstream file (filename);

    std::string returnValue;
    std::string fileLine;

    while (getline(file, fileLine))
    {
        returnValue = returnValue + fileLine;
    }
    return returnValue;
}

int main(int argc, char *argv[])
{
    std::string lines;
    lines = getFileContent(argv[1]);
    Plexer(lines);

    return 0;
}