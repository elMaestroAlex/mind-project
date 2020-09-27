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
    void syntesAst(const std::vector<Lexem>& lexems, int lexemCursor, AstNodeAbstract* contextNode);
    std::unique_ptr< AstNodeAbstract > getTreeNodeByLexem(const Lexem& lexem);

private:
    std::unique_ptr<Lexer> m_lexer;
};

#endif // PARSER_H
