#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "AST.h"

class Parser
{
public:
    Parser();

    void parse(std::string& code, AST* ast);
};

#endif // PARSER_H
