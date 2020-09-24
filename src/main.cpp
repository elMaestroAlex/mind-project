#include <iostream>

#include <string>
#include "parser/AST.h"
#include "parser/Parser.h"

using namespace std;

int main()
{
    cout << "KATE greetings you!" << endl;

    std::string fileName = "D:\\projects\\neuron_models\\salary.katemodel";

    AST modelAst;
    Parser parser;

    parser.parse(fileName, modelAst);
    
    return 0;
}
