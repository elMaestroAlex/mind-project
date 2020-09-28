#ifndef ASTNODEPROJECTROOT_H
#define ASTNODEPROJECTROOT_H

#include <string>

#include "AstNodeAbstract.h"

class AstNodeProjectRoot : public  AstNodeAbstract {
public:
	AstNodeProjectRoot(std::string filePath);
	AstNodeKind getKind() const override { return m_nodeType; };

private:
	const AstNodeKind m_nodeType;
	const std::string m_projectIndexFile;
};


#endif // ASTNODEPROJECTROOT_H