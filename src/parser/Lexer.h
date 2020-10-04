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

    // language entities and reserved words
    Model,
    Placeholder,
    Logic,
    Variable,
    Constant,
    Int,
    Float,
};

struct Lexem {
    LexemType  type;
    std::string token;
    
    bool isTypeLexem() const {
        return type == LexemType::Float || type == LexemType::Int;
    }
};

class Lexer
{
public:
    Lexer();
    std::vector<Lexem> getLexems(const std::string& code);
};

#endif // LEXER_H
