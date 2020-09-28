
#include <map>

#include "AstNodeTensorFlowPrimirive.h"

namespace {
	std::map<LexemType, AstNodeKind> __lexemToAstTypeMap = {
		{LexemType::Placeholder, AstNodeKind::Placeholder},
		{LexemType::Variable, AstNodeKind::Variable},
		{LexemType::Constant, AstNodeKind::Constant}
	};
}

AstNodeTensorFlowPrimirive::AstNodeTensorFlowPrimirive(LexemType lexemType) {
	m_nodeType = __lexemToAstTypeMap[lexemType];
}

