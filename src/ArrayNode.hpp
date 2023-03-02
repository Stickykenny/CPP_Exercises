#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <string>
#include <vector>

class ArrayNode : public Node
{
public:
    ArrayNode();

    std::string                       print() const;
    NodeKind                          kind() const;
    static std::unique_ptr<ArrayNode> make_ptr() { return std::make_unique<ArrayNode>(); };
    unsigned int                      child_count() const;
    void                              push_back(NodePtr node);
    unsigned int                      height() const;
    unsigned int                      node_count() const;

private:
    std::string          _str;
    unsigned int         _child_count = 0;
    std::vector<NodePtr> _array = {}; // Impossible de faire un vector de Node car tableau dynamique, il faut
                                      // connaitre la taille or, Node est abstraite
};