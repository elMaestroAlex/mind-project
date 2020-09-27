#include "Parser.h"
#include "ast-nodes/AstNodeFile.h"

#include <fstream>

#include <iostream>
#include <vector>
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

void Parser::syntesAst(const std::vector<Lexem>& lexems, int lexemCursor, AstNodeAbstract* contextNode) {
    size_t size = lexems.size();
    
    AstNodeAbstract* parentContext = contextNode;

    for (int cursor = lexemCursor; cursor < size; ) {
        const Lexem& lexem = lexems[cursor];

        std::unique_ptr<AstNodeAbstract> treeNode = getTreeNodeByLexem(lexems[cursor]);

        std::cout << "syntes" << std::endl;
        ++cursor;
    }

}

std::unique_ptr< AstNodeAbstract > Parser::getTreeNodeByLexem(const Lexem& lexem) {
    if (lexem.type == LexemType::Token) {
        //switch (lexem.token)
        //{
        //case "": 
        //    break;
        //default:
        //    break;
        //}
    }

    return nullptr;
}