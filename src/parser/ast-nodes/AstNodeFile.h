#ifndef ASTNODEFILE_H
#define ASTNODEFILE_H

#include <string>

#include "AstNodeAbstract.h"

class AstNodeFile : public  AstNodeAbstract {
public:
	AstNodeFile(std::string filePath);
	AstNodeKind getKind() const override { return m_nodeType; };

	std::string toString() const override { return "AstNodeFile: " + m_filePath; }
private:
	const AstNodeKind m_nodeType;
	const std::string m_filePath;
};


#endif // ASTNODEFILE_H