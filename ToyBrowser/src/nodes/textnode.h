#ifndef TEXTNODE_H
#define TEXTNODE_H
#include "node.h"

class TextNode: public Node{
public:
    TextNode(std::string txt=NULL);

    std::string getText() const;
private:
    std::string text;
};

std::unique_ptr<TextNode> TextNodeFactory(std::string txt);
#endif // TEXTNODE_H
