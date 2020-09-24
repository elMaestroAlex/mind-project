
#include "AstNodeFile.h"

AstNodeFile::AstNodeFile(std::string filePath)
	: m_nodeType(AstNodeType::ModelFile)
	, m_filePath(std::move(filePath)) {
}
