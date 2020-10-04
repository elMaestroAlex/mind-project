#ifndef AST_NODE_MODEL_H
#define AST_NODE_MODEL_H

#include <string>

#include "AstNodeAbstract.h"

class AstNodeModel : public  AstNodeAbstract {
public:
	AstNodeModel(std::string token);
	AstNodeKind getKind() const override { return m_nodeType; };

	std::string toString() const override { return "Model: " + m_nodeName; }
// private:
	const AstNodeKind m_nodeType;
	const std::string m_nodeName;
};

#endif // AST_NODE_MODEL_H