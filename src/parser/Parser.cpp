#include "Parser.h"
#include "ast-nodes/AstNodeFile.h"
#include "ast-nodes/AstNodeModel.h"
#include "ast-nodes/AstNodeTensorFlowPrimirive.h"
#include "ast-nodes/AstNodeMethod.h"
#include "ast-nodes/AstNodeExpression.h"

#include <fstream>

#include <iostream>
#include <vector>
#include <stack>
#include <memory>


Parser::Parser() :
    m_lexer { new Lexer() }
{
}


std::string Parser::readFileContent(const std::string& fileName) {
    std::ifstream ifs(fileName);
    std::string content((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));

    return content;
}

int Parser::getNextLexemPos(const std::vector<Lexem>& lexems, const unsigned int cursor) {
    size_t size = lexems.size();

    for (unsigned int pos = cursor; pos < size; ++pos) {
        const Lexem& nextLexem = lexems[pos];
        if (nextLexem.type != LexemType::Space) {
            return pos;
        }
    }

    return -1;
}

void Parser::parse(const std::string& indexFileName, AST &ast) {
    AstNodeAbstractUptr rootNode(new AstNodeProjectRoot(indexFileName));
    auto nodeFile = new AstNodeFile(indexFileName);

    AstNodeAbstractUptr indexFileNode(nodeFile);
    
    rootNode->addChild(std::move(indexFileNode));
    ast.setRootNode(std::move(rootNode));

    std::string code = readFileContent(indexFileName);

    auto lexemBuffer = m_lexer->getLexems(code);
    if (lexemBuffer.size() == 0) {
        return;
    }

    syntesAst(lexemBuffer, 0, nodeFile);

    ast.dumpAsString();
    std::cout << "" << std::endl;
}

void Parser::syntesAst(const std::vector<Lexem>& lexems, unsigned int lexemCursor, AstNodeAbstract* contextNode) {
    size_t size = lexems.size();

    std::stack<AstNodeAbstract*> contextNodeStack;
    contextNodeStack.push(contextNode);

    AstNodeAbstract* lastNode = nullptr;

    for (unsigned int cursor = lexemCursor; cursor < size - 1; ) {
        const Lexem& lexem = lexems[cursor];

        switch (lexem.type) {
        case LexemType::Model:
            lastNode = buildModelNode(lexems, cursor);
            break;
        case LexemType::BracerOpen:
            contextNode->addChild(lastNode);
            contextNode = lastNode;
            contextNodeStack.push(contextNode);
            break;
        case LexemType::BracerClose:
            contextNodeStack.pop();
            contextNode = contextNodeStack.top();
            break;
        case LexemType::Placeholder:
        case LexemType::Constant:
        case LexemType::Variable:
            contextNode->addChild(buildTensorFlowEntity(lexems, cursor));
            break;
        case LexemType::Return:
            contextNode->addChild(buildExpressionNode(lexems, cursor));
            break;
        case LexemType::Logic:
            lastNode = new AstNodeMethod("logic");
            break;

        }
        
        ++cursor;
    }

}



AstNodeAbstract* Parser::buildExpressionNode(const std::vector<Lexem>& lexems, unsigned int& cursor) {
    return new AstNodeExpression("x + y + z");
}

AstNodeAbstract* Parser::buildModelNode(const std::vector<Lexem>& lexems, unsigned int& cursor) {
    ++cursor;

    unsigned int nextLexemIndex = getNextLexemPos(lexems, cursor);

    if (nextLexemIndex == -1) {
        std::cout << "Expected Model name. But end found" << std::endl;
        return nullptr;
    }

    cursor = nextLexemIndex;
    const Lexem& modelNameLexem = lexems[cursor];
    
    if (modelNameLexem.type != LexemType::Token) {
        std::cout << "String token expexted. But " << modelNameLexem.token << " found"  << std::endl;
        return nullptr;
    }

    
    return new AstNodeModel(modelNameLexem.token);
}

AstNodeTensorFlowPrimirive* Parser::buildTensorFlowEntity(const std::vector<Lexem>& lexems, unsigned int& cursor) {

    auto currentLexem = lexems[cursor];
    ++cursor;

    unsigned int propertyNameLexemeIndex = getNextLexemPos(lexems, cursor);

    if (propertyNameLexemeIndex == -1) {
        std::cout << "Expected property name. But end found" << std::endl;
        return nullptr;
    }

    cursor = propertyNameLexemeIndex;
    const Lexem& propertyNameLexeme = lexems[cursor];

    if (propertyNameLexeme.type != LexemType::Token) {
        std::cout << "String token expexted. But " << propertyNameLexeme.token << " found" << std::endl;
        return nullptr;
    }
    cursor++;

    unsigned int propertyTypeLexemeIndex = getNextLexemPos(lexems, cursor);
    if (propertyTypeLexemeIndex == -1) {
        std::cout << "Expected property type. But end found" << std::endl;
        return nullptr;
    }

    cursor = propertyTypeLexemeIndex;
    const Lexem& propertyTypeLexeme = lexems[cursor];

    if (!propertyTypeLexeme.isTypeLexem()) {
        std::cout << "Type token expexted. But " << propertyNameLexeme.token << " found" << std::endl;
        return nullptr;
    }

    return new AstNodeTensorFlowPrimirive(currentLexem.type, propertyNameLexeme.token, propertyTypeLexeme.token);
}

