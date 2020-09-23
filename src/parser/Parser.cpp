#include "Parser.h"

#include <iostream>
#include <vector>

Parser::Parser()
{
    lexer = new Lexer();
}


void Parser::parse(std::string &code, AST *ast) {
    std::cout << code << std::endl;

    std::vector<Lexem> lexemBuffer;
    lexer->getLexems(code, lexemBuffer);
    std::cout << "File parsed" << std::endl;
}

