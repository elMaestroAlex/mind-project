
#include "AstNodeMethod.h"

AstNodeMethod::AstNodeMethod(std::string token)
    : m_nodeType(AstNodeKind::Method)
    , m_nodeName( std::move(token)) {
}
