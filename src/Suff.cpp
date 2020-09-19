#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Compiler.hpp"

string getFileContent(char* filename){
    std::ifstream file (filename);

    string returnValue;
    string fileLine;

    while (getline(file, fileLine))
    {
        returnValue = returnValue + fileLine;
    }
    file.close();
    return returnValue;
}

void commandHandler(int argc, char *argv[])
{
    string fileContent;
    string mode;
    string outFileName;

    fileContent = getFileContent(argv[1]);
    outFileName = argv[2];
    argc == 4 ? mode = (string) argv[3] : mode = (string) "c";

    std::ofstream outFile (outFileName);
    if (mode == "c"){
        outFile << cCompile(fileContent);
    }
    outFile.close();
}

int main(int argc, char *argv[])
{
    commandHandler(argc, argv);
    return 0;
}