
#include "AstNodeFile.h"

AstNodeFile::AstNodeFile(std::string filePath)
	: m_nodeType(AstNodeKind::ModelFile)
	, m_filePath(std::move(filePath)) {
}
