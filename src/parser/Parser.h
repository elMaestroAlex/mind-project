#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "AST.h"

enum class LexemType {
    Token,
    Comment,
    Space,
    EndLine,
    BracerOpen,
    BracerClose,

    // ariphmetic
    Plus,
    Minus,
    Divide,
    Multiply,
};

struct Lexem {
    LexemType  _type;
    std::string token;
};


class Parser
{
    void handleLexem(
        char character,
        LexemType type,
        Lexem& currentLexeme,
        std::vector<Lexem>& lexems,
        bool sequenceable = false
    );
    void getLexems(std::string& code, std::vector<Lexem>& lexems);
public:
    Parser();

    void parse(std::string& code, AST* ast);
};

#endif // PARSER_H
