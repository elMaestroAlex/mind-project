#ifndef AST_NODE_EXPRESSION_H
#define AST_NODE_EXPRESSION_H

#include <string>

#include "AstNodeAbstract.h"

class AstNodeReturnExpression : public  AstNodeAbstract {
public:
    AstNodeReturnExpression(std::string token);
	AstNodeKind getKind() const override { return m_nodeType; };

	std::string toString() const override { return "Expression(Return): " + m_nodeName; }
// private:
	const AstNodeKind m_nodeType;
	const std::string m_nodeName;
};

#endif // AST_NODE_EXPRESSION_H