#include "AST.h"

#include <iostream>
#include <vector>
#include <string>

namespace {

	std::string getTabStr(int tabs) {
		std::string result = "";
		for (int i = 0; i < tabs; ++i) {
			result += "    ";
		}

		return result;
	}

}

AST::AST()
{
}


void AST::dumpAsString(AstNodeAbstract* node, int sTabs) {
	std::string tabs = getTabStr(sTabs);

	if (node == nullptr) {
		node = getRootNode();
	}

	std::cout << tabs << node->toString() << std::endl;
	const std::vector<AstNodeAbstractUptr>& children = node->getChildren();
	
	for (auto const& value : children) {
		dumpAsString(value.get(), sTabs + 1);
	}
}


