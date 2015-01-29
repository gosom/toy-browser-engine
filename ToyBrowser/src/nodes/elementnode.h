#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H
#include "node.h"
#include <string>
#include <map>

typedef std::map<std::string, std::string> AttrMap;

class ElementNode : public Node{
public:
    ElementNode();
    ElementNode(std::string name);

    std::string getTagName() const;
    std::string getAttribute(const std::string& name) const;
    std::string getText() const;

    void setTagName(std::string name);
    void setAttribute(std::string name, std::string value);

private:
    std::string tagName;
    AttrMap attributes;
};

std::unique_ptr<ElementNode> ElementNodeFactory(std::string name);

#endif // ELEMENTNODE_H
