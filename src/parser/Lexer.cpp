#include "Lexer.h"

#include <string>
#include <vector>
#include <map>

namespace {

    std::map<std::string, LexemType> __tokenToLexemCastMap = {
        {"model", LexemType::Model },
        {"placeholder", LexemType::Placeholder },
        {"variable", LexemType::Variable },
        {"int", LexemType::Int },
        {"float", LexemType::Float },
        {"logic", LexemType::Logic },
    };

    void pushLexem(Lexem& lexem, std::vector<Lexem>& lexems) {
        if (lexem.type == LexemType::Token && __tokenToLexemCastMap.find(lexem.token) != __tokenToLexemCastMap.end()) {
            lexem.type = __tokenToLexemCastMap[lexem.token];
        }
        lexems.push_back(lexem);
    }

    void handleLexem(
        char character,
        LexemType type,
        Lexem& currentLexeme,
        std::vector<Lexem>& lexems,
        bool sequenceable = false
    ) {
        if (currentLexeme.type == LexemType::Comment) {
            currentLexeme.token += character;
            return;
        }

        if (!sequenceable) {
            pushLexem(currentLexeme, lexems);
        }
        else if (currentLexeme.type != type) {
            pushLexem(currentLexeme, lexems);
        }

        currentLexeme.type = type;
        currentLexeme.token = "";

    }
}

Lexer::Lexer() {
	
}


std::vector<Lexem> Lexer::getLexems(const std::string& code)  {
    size_t cursor = 0;
    const auto codeLen = code.size();
    std::vector<Lexem> lexems;

    if (codeLen == 0) {
        return lexems;
    }

    Lexem lexem;

    while (true) {
        if (cursor >= codeLen) {
            return lexems;
        }
        char character = code[cursor];
        bool isLast = cursor >= codeLen - 1;

        char lookahead = 0;
        if (!isLast) {
            lookahead = code[cursor + 1];
        }

        switch (character) {
            // absolute delemiter
        case '\t':
        case ' ':
            handleLexem(character, LexemType::Space, lexem, lexems, true);
            break;
        case '\n':
            if (lexem.type != LexemType::EndLine) {
                pushLexem(lexem, lexems);
                lexem.type = LexemType::EndLine;
                lexem.token = "";
            }
            break;
        case '{':
            handleLexem(character, LexemType::BracerOpen, lexem, lexems);
            break;
        case '}':
            handleLexem(character, LexemType::BracerClose, lexem, lexems);
            break;

        case '+':
            handleLexem(character, LexemType::Plus, lexem, lexems);
            break;
        case '-':
            handleLexem(character, LexemType::Minus, lexem, lexems);
            break;
        case '*':
            handleLexem(character, LexemType::Multiply, lexem, lexems);
            break;

            // comments
        case '/':
            if (lexem.type != LexemType::Comment && lexem.type != LexemType::Divide) {
                pushLexem(lexem, lexems);
            }

            if (lookahead == '/') {
                lexem.type = LexemType::Comment;
                lexem.token = "//";
                cursor++;
            }
            else {
                lexem.type = LexemType::Divide;
            }
            break;


        default:
            if (lexem.type != LexemType::Comment) {
                lexem.type = LexemType::Token;
            }
            lexem.token += character;
        }

        if (isLast) {
            pushLexem(lexem, lexems);
            return lexems;
        }

        ++cursor;
    } // while (true)

    return lexems;
}
