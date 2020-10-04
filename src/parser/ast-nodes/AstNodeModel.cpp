
#include "AstNodeModel.h"

AstNodeModel::AstNodeModel(std::string token)
    : m_nodeType(AstNodeKind::Model)
    , m_nodeName( std::move(token)) {
}
