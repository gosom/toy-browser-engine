#include "elementnode.h"

ElementNode::ElementNode(): Node(NodeType::Element){
}

ElementNode::ElementNode(std::string name):
Node(NodeType::Element){
    tagName = name;
}

std::string ElementNode::getAttribute(const std::string& name) const{
    return attributes.at(name);
}

std::string ElementNode::getText() const{
    std::string txt;
    if(textNode)
        txt += textNode->getText();
    for(auto& child: childNodes){
        std::string tmp(child->getText());
        if(tmp != "")
            txt += "\n" + tmp;
    }
    return txt;
}

void ElementNode::setTagName(std::string name){
    tagName = name;
}

void ElementNode::setAttribute(std::string name, std::string value){
    attributes[name] = value;
}

std::unique_ptr<ElementNode> ElementNodeFactory(std::string name){

    return std::unique_ptr<ElementNode>(new ElementNode(name));
}


