#include "Parser.h"

#include <iostream>
#include <vector>
#include <set>


Parser::Parser()
{

}


void Parser::parse(std::string &code, AST *ast) {
    std::cout << code << std::endl;

    std::vector<Lexem> lexemBuffer;
    getLexems(code, lexemBuffer);
    std::cout << "File parsed" << std::endl;
}


void Parser::handleLexem(
    char character, 
    LexemType type,
    Lexem& currentLexeme,
    std::vector<Lexem>& lexems,
    bool sequenceable
) {
    if (currentLexeme._type == LexemType::Comment) {
        currentLexeme.token += character;
        return;
    }

    if (!sequenceable) {
        lexems.push_back(currentLexeme);
    } else if (currentLexeme._type != type) {
        lexems.push_back(currentLexeme);
    }

    currentLexeme._type = type;
    currentLexeme.token = "";

}

void Parser::getLexems(std::string& code, std::vector<Lexem>& lexems) {
    int cursor = 0;
    int codeLen = code.size();
    if (codeLen == 0) {
        return;
    }

    Lexem lexem;

    while (true) {
        if (cursor >= codeLen) {
            return;
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
            if (lexem._type != LexemType::EndLine) {
                lexems.push_back(lexem);
                lexem._type = LexemType::EndLine;
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
            if (lexem._type != LexemType::Comment && lexem._type != LexemType::Divide) {
                lexems.push_back(lexem);
            }

            if (lookahead == '/') {
                lexem._type = LexemType::Comment;
                lexem.token = "//";
                cursor++;
            } else {
                lexem._type = LexemType::Divide;
            }
            break;
      

        default:
            if (lexem._type != LexemType::Comment) {
                lexem._type = LexemType::Token;
            }
            lexem.token += character;
        }

        if (isLast) {
            lexems.push_back(lexem);
            return;
        }

        ++cursor;
    } // while (true)

}
