#ifndef ASTNODETENSORFLOWPRIMITIVE_H
#define ASTNODETENSORFLOWPRIMITIVE_H

#include <string>

#include "../Lexer.h"
#include "AstNodeAbstract.h"

class AstNodeTensorFlowPrimirive : public AstNodeAbstract {
public:
	AstNodeTensorFlowPrimirive(LexemType lexemType);
	AstNodeKind getKind() const override { return m_nodeType; };
	void setName(const std::string nodeName) { m_nodeName = nodeName;  };

private:
	AstNodeKind m_nodeType;
	std::string m_nodeName;
};

#endif // ASTNODETENSORFLOWPRIMITIVE_H