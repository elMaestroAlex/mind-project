#include "Parser.h"

#include <iostream>
#include <vector>

Parser::Parser()
{
    lexer = new Lexer();
}


void Parser::parse(const std::string &code, AST &ast) {
    std::cout << code << std::endl;

    auto lexemBuffer = lexer->getLexems(code);
    std::cout << "File parsed" << std::endl;
}

