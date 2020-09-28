#include <iostream>

#include <string>
#include "parser/AST.h"
#include "parser/Parser.h"

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Mind Engine greetings you!" << endl;

    std::string fileName = std::string(argv[1]);

    AST modelAst;
    Parser parser;

    parser.parse(fileName, modelAst);
    
    return 0;
}
