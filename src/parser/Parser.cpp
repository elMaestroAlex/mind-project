#include "Parser.h"
#include "ast-nodes/AstNodeFile.h"
#include "ast-nodes/AstNodeModel.h"

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
    AstNodeAbstractUptr indexFileNode(new AstNodeFile(indexFileName));
    
    rootNode->addChild(std::move(indexFileNode));
    ast.setRootNode(std::move(rootNode));

    std::string code = readFileContent(indexFileName);

    auto lexemBuffer = m_lexer->getLexems(code);
    if (lexemBuffer.size() == 0) {
        return;
    }

    syntesAst(lexemBuffer, 0, ast.getRootNode()->getChildren()[0].get());
}

void Parser::syntesAst(const std::vector<Lexem>& lexems, unsigned int lexemCursor, AstNodeAbstract* contextNode) {
    size_t size = lexems.size();

    std::stack<AstNodeAbstract*> contextNodeStack;
    contextNodeStack.push(contextNode);

    AstNodeAbstractUptr lastNode = nullptr;

    for (int cursor = lexemCursor; cursor < size; ) {
        const Lexem& lexem = lexems[cursor];

        switch (lexem.type) {
        case LexemType::Model:
            lastNode = buildModelNode(lexems, lexemCursor);
            break;
        case LexemType::BracerOpen:
            contextNode = lastNode.get();
            contextNodeStack.push(contextNode);
            break;
        case LexemType::BracerClose:
            contextNodeStack.pop();
            contextNode = contextNodeStack.top();
            break;
        }

        std::cout << "syntes" << std::endl;
        ++cursor;
    }

}


AstNodeAbstractUptr Parser::buildModelNode(const std::vector<Lexem>& lexems, unsigned int& cursor) {
    size_t size = lexems.size();

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

    AstNodeAbstractUptr modelNode(new AstNodeModel(modelNameLexem.token));
    
    return modelNode;
}

