
#include "AstNodeReturnExpression.h"

AstNodeReturnExpression::AstNodeReturnExpression(std::string token)
    : m_nodeType(AstNodeKind::ReturnExpression)
    , m_nodeName( std::move(token)) {
}
