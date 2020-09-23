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
    void handleLexem(
        char character,
        LexemType type,
        Lexem& currentLexeme,
        std::vector<Lexem>& lexems,
        bool sequenceable = false
    );
public:
    Lexer();
    void getLexems(std::string& code, std::vector<Lexem>& lexems);
};

#endif // LEXER_H
