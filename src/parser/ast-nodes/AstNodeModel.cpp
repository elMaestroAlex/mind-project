
#include "AstNodeModel.h"

AstNodeModel::AstNodeModel(std::string token)
	: m_nodeType(AstNodeType::Model)
	, m_nodeName( std::move(token)) {
}
