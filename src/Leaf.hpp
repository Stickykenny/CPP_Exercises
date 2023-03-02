#pragma once
#include "Node.hpp"

class Leaf : public Node
{
public:
    unsigned int height() const { return 0u; };
    unsigned int node_count() const { return 1u; };
};