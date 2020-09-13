#ifndef ASTNODE_H
#define ASTNODE_H

#include <vector>

class AstNode {

    std::vector<AstNode> chidlren;
public:

    enum AstNodeType {
        ArithmeticOperator = 0,
        Model,
        Placeholder,
        Variable,
        Constant,
        Output,
        NamedObject // variables inside the logic blocks
    };
    virtual int getType() = 0;
    virtual std::vector<AstNode>& getChildren() { return chidlren; }

};

#endif // ASTNODE_H
