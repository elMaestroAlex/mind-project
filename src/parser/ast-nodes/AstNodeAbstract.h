#ifndef ASTNODEABSTRACT_H
#define ASTNODEABSTRACT_H

#include <vector>
#include <memory>

class AstNodeAbstract;

using AstNodeAbstractUptr = std::unique_ptr<AstNodeAbstract>;


enum class AstNodeKind {
    ProjectRoot = 0, // root node of whole project
    ModelFile,
    ArithmeticOperator,
    Model,
    Placeholder,
    Variable,
    Constant,
    Output,
    NamedObject // variables inside the logic blocks
};


class AstNodeAbstract {
public:
    virtual ~AstNodeAbstract() = default;
    virtual AstNodeKind getKind() const = 0;
    std::vector< AstNodeAbstractUptr >& getChildren() { return m_chidlren; }
    void addChild(AstNodeAbstractUptr child) {
        m_chidlren.push_back(std::move(child));
    }

private:
    std::vector<AstNodeAbstractUptr> m_chidlren;

};

#endif // ASTNODEABSTRACT_H
