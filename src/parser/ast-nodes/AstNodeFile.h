#ifndef ASTNODEFILE_H
#define ASTNODEFILE_H

#include <string>

#include "AstNodeAbstract.h"

class AstNodeFile : public  AstNodeAbstract {
public:
	AstNodeFile(std::string filePath);
	AstNodeType getType() const override { return m_nodeType; };

private:
	const AstNodeType m_nodeType;
	const std::string m_filePath;
};


#endif // ASTNODEFILE_H