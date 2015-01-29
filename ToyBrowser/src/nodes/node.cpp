#include "node.h"

Node::Node(){
}

Node::Node(NodeType _type){
    _nodeType = _type;
}

Node::~Node(){
}

NodeType Node::getNodeType() const{
    return _nodeType;
}

Node const* Node::getParentNode() const{
    return parentNode;
}

const NodeList& Node::getChildNodes(){
    return childNodes;
}

bool Node::hasChildNodes() const{
    return childNodes.size() > 0;
}


void Node::setParent(Node *node){
    parentNode = node;
}

void Node::appendChild(std::unique_ptr<Node> node){
    node->parentNode = this;
    childNodes.push_back(std::move(node));
}

void Node::setTextNode(std::unique_ptr<Node> node){
    node->parentNode = this;
    textNode = std::move(node);
}
