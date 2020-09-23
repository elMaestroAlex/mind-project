#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

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

class Lexer
{
public:
    Lexer();
    std::vector<Lexem> getLexems(const std::string& code);
};

#endif // LEXER_H
