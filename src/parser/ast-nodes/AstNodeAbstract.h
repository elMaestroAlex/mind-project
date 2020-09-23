#ifndef ASTNODEABSTRACT_H
#define ASTNODEABSTRACT_H

#include <vector>

enum class AstNodeType {
    ArithmeticOperator = 0,
    Model,
    Placeholder,
    Variable,
    Constant,
    Output,
    NamedObject // variables inside the logic blocks
};


class AstNodeAbstract {
    std::vector<AstNodeAbstract> chidlren;
public:
    virtual ~AstNodeAbstract() = default;
    virtual AstNodeType getType() const = 0;
    std::vector<AstNodeAbstract>& getChildren() { return chidlren; }

};

#endif // ASTNODEABSTRACT_H
