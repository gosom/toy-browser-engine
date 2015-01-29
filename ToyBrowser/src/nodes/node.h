#ifndef NODE_H
#define NODE_H
#include <vector>
#include <memory>

enum NodeType{
    Element = 1,
    Text = 2
};

class Node;

typedef std::vector<std::unique_ptr<Node>> NodeList;
class Node
{
public:
    Node();
    Node(NodeType _type);
    virtual ~Node();

    NodeType getNodeType() const;
    Node const* getParentNode() const;
    bool hasChildNodes() const;
    const NodeList& getChildNodes();
    virtual std::string getText() const = 0;

    void setParent(Node* node);
    void appendChild(std::unique_ptr<Node> node);
    void setTextNode(std::unique_ptr<Node> node);
protected:
    NodeType _nodeType;
    Node* parentNode;
    NodeList childNodes;
    std::unique_ptr<Node> textNode;
};

#endif // NODE_H
