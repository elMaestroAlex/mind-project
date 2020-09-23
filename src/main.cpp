#include <iostream>
#include <fstream>
#include <string>


#include "parser/AST.h"
#include "parser/Parser.h"

using namespace std;


std::string readTestModelFile() {
    std::string fileName = "D:\\projects\\neuron_models\\salary.katemodel";
    std::ifstream ifs(fileName);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()) );
    return content;
}

int main()
{
    cout << "KATE greetings you!" << endl;

    AST modelAst;
    Parser parser;
    std::string code = readTestModelFile();

    parser.parse(code, modelAst);
    
    return 0;
}
