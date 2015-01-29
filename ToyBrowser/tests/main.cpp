#include <UnitTest++/UnitTest++.h>
#include <iostream>
#include "nodes/node.h"
#include "nodes/textnode.h"
#include "nodes/elementnode.h"

using namespace std;

TEST(checkNode){
    auto html_node = ElementNodeFactory("html");
    auto body_node = ElementNodeFactory("body");
    auto p_node = ElementNodeFactory("p");
    auto txt_node = TextNodeFactory("hello");

    p_node->setTextNode(std::move(txt_node));
    body_node->appendChild(std::move(p_node));
    html_node->appendChild(std::move(body_node));

    cout << html_node->getText() << std::endl;
    auto& c = html_node->getChildNodes();
    CHECK(c.size() == 1);
    auto& e = c[0]; // should be body
    CHECK(e->getNodeType() == NodeType::Element);
}

int main()
{
    return UnitTest::RunAllTests();
}

