
#include "AstNodeProjectRoot.h"

AstNodeProjectRoot::AstNodeProjectRoot(std::string projectIndexFile)
    : m_nodeType(AstNodeKind::ProjectRoot)
    , m_projectIndexFile(std::move(projectIndexFile)) {
}
