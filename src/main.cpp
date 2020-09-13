#include <iostream>
#include <fstream>
#include <string>


#include "parser/AST.h"
#include "parser/Parser.h"

using namespace std;


std::string readTestModelFile() {
    std::string fileName = "/Users/alexandr/projects/neuron_models/salary.mlmodel";
    std::ifstream ifs(fileName);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()) );
    return content;
}

int main()
{
    cout << "KATE greetings you!" << endl;

    AST* modelAst = new AST();

    Parser* parser = new Parser();

    std::string code = readTestModelFile();
    parser->parse(code, modelAst);

    return 0;
}
