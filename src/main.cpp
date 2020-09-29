#include <iostream>

#include <string>
#include "parser/AST.h"
#include "parser/Parser.h"

int main(int argc, char* argv[])
{
    std::cout << "Mind Engine greetings you!" << std::endl;

    std::string fileName = std::string(argv[1]);

    AST modelAst;
    Parser parser;

    parser.parse(fileName, modelAst);
    
    return 0;
}
