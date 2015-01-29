#include "textnode.h"

TextNode::TextNode(std::string txt):
Node(NodeType::Text){
    text = txt;
}

std::string TextNode::getText() const{
    return text;
}

std::unique_ptr<TextNode> TextNodeFactory(std::string txt){
    return std::unique_ptr<TextNode>(new TextNode(txt));
}
