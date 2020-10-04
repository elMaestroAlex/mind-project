#ifndef AST_H
#define AST_H

#include "ast-nodes/AstNodeAbstract.h"
#include "ast-nodes/AstNodeProjectRoot.h"

class AST
{
public:
    AST();
    void setRootNode(AstNodeAbstractUptr rootNode) { m_rootNode = std::move(rootNode) ; }
    AstNodeAbstract* getRootNode() { return m_rootNode.get(); }

    void dumpAsString(AstNodeAbstract* node = nullptr, int sTabs = 0);

private:
    AstNodeAbstractUptr m_rootNode;
};

#endif // AST_H
