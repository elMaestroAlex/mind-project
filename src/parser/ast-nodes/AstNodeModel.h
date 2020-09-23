#ifndef AST_NODE_MODEL_H
#define AST_NODE_MODEL_H

#include <string>

#include "AstNodeAbstract.h"

class AstNodeModel : public  AstNodeAbstract {
public:
	AstNodeModel(std::string token);
	AstNodeType getType() const override { return m_nodeType; };

private:
	const AstNodeType m_nodeType;
	const std::string m_nodeName;
};

#endif // AST_NODE_MODEL_H