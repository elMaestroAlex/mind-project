
#include <map>

#include "AstNodeTensorFlowPrimirive.h"

namespace {
    std::map<LexemType, AstNodeKind> __lexemToAstTypeMap = {
        { LexemType::Placeholder, AstNodeKind::Placeholder },
        { LexemType::Variable, AstNodeKind::Variable },
        { LexemType::Constant, AstNodeKind::Constant }
    };
}

AstNodeTensorFlowPrimirive::AstNodeTensorFlowPrimirive(
    const LexemType lexemKind,
    const std::string lexemName,
    const std::string type
) {
    m_nodeKind = __lexemToAstTypeMap[lexemKind];
    m_primitiveName = lexemName;
    m_primitiveType = type;
}

