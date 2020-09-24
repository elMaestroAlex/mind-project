
#include "AstNodeProjectRoot.h"

AstNodeProjectRoot::AstNodeProjectRoot(std::string projectIndexFile)
	: m_nodeType(AstNodeType::ProjectRoot)
	, m_projectIndexFile(std::move(projectIndexFile)) {
}
