#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "AST.h"
#include "Lexer.h"
#include "ast-nodes/AstNodeTensorFlowPrimirive.h"
#include <memory>

class Parser
{
public:
    Parser();
    void parse(const std::string& indexFileName, AST& ast);

private:
    std::string readFileContent(const std::string& fileName);
    void syntesAst(const std::vector<Lexem>& lexems, unsigned int lexemCursor, AstNodeAbstract* contextNode);

    int getNextLexemPos(const std::vector<Lexem>& lexems, const unsigned int cursor);

    // language entities
    AstNodeAbstract* buildModelNode(const std::vector<Lexem>& lexems, unsigned int& cursor);

    AstNodeTensorFlowPrimirive* buildTensorFlowEntity(const std::vector<Lexem>& lexems, unsigned int& cursor);
private:
    std::unique_ptr<Lexer> m_lexer;
};

#endif // PARSER_H
