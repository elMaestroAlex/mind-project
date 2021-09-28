#ifndef AST_NODE_METHOD_H
#define AST_NODE_METHOD_H

#include <string>

#include "AstNodeAbstract.h"

class AstNodeMethod : public  AstNodeAbstract {
public:
    AstNodeMethod(std::string token);
	AstNodeKind getKind() const override { return m_nodeType; };

	std::string toString() const override { return "Method: " + m_nodeName; }
// private:
	const AstNodeKind m_nodeType;
	const std::string m_nodeName;
};

#endif // AST_NODE_METHOD_H