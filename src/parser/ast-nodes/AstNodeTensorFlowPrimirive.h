#ifndef ASTNODETENSORFLOWPRIMITIVE_H
#define ASTNODETENSORFLOWPRIMITIVE_H

#include <string>

#include "../Lexer.h"
#include "AstNodeAbstract.h"

class AstNodeTensorFlowPrimirive : public AstNodeAbstract {
public:
	AstNodeTensorFlowPrimirive(
		const LexemType lexemKind,
		const std::string lexemName,
		const std::string type
	);
	AstNodeKind getKind() const override { return m_nodeKind; };
	void setName(const std::string nodeName) { m_primitiveName = nodeName;  };
	std::string toString() const override { return "TensorFlowPrimirive: " + m_primitiveName + " -> " + m_primitiveType; }

private:
	AstNodeKind m_nodeKind;
	std::string m_primitiveName;
	std::string m_primitiveType;
};

#endif // ASTNODETENSORFLOWPRIMITIVE_H