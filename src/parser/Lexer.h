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

    //Statements
    Return
};

struct  Lexem {
    LexemType  type;
    std::string token;
    
    bool isTypeLexeme() const {
        return type == LexemType::Float || type == LexemType::Int;
    }

    bool isPhantomLexeme() const {
        return type == LexemType::Token && token.empty();
    }
};

class Lexer
{
public:
    Lexer();
    std::vector<Lexem> getLexems(const std::string& code);
};

#endif // LEXER_H
