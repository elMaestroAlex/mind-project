
#include "AstNodeExpression.h"

AstNodeExpression::AstNodeExpression(std::string token)
    : m_nodeType(AstNodeKind::Expression)
    , m_nodeName( std::move(token)) {
}
