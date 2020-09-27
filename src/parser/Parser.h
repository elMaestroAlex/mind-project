#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "AST.h"
#include "Lexer.h"
#include <memory>

class Parser
{
public:
    Parser();
    void parse(const std::string& indexFileName, AST& ast);

private:
    std::string readFileContent(const std::string& fileName);
    void syntesAst(const std::vector<Lexem>& lexems, unsigned int lexemCursor, AstNodeAbstract* contextNode);

    AstNodeAbstractUptr buildModelNode(const std::vector<Lexem>& lexems, unsigned int& cursor);
    int getNextLexemPos(const std::vector<Lexem>& lexems, const unsigned int cursor);

private:
    std::unique_ptr<Lexer> m_lexer;
};

#endif // PARSER_H
