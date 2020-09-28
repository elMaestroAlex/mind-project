
#include <map>

#include "AstNodeTensorFlowPrimirive.h"

namespace {
	std::map<LexemType, AstNodeType> __lexemToAstTypeMap = {
		{LexemType::Placeholder, AstNodeType::Placeholder},
		{LexemType::Variable, AstNodeType::Variable},
		{LexemType::Constant, AstNodeType::Constant}
	};
}

AstNodeTensorFlowPrimirive::AstNodeTensorFlowPrimirive(LexemType lexemType) {
	m_nodeType = __lexemToAstTypeMap[lexemType];
}

