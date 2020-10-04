#include <iostream>

#include <string>
#include "parser/AST.h"
#include "parser/Parser.h"

int main(int argc, char* argv[])
{
    if (argc <= 1) {
        std::cout << "There is no model filename." << std::endl;
        return 1;
    }

    std::cout << "Mind Engine greetings you!" << std::endl;

    std::string fileName = argv[1];

    AST modelAst;
    Parser parser;

    parser.parse(fileName, modelAst);
    
    return 0;
}
