#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class IntLeaf : public Leaf
{
public:
    IntLeaf(int value);
    int                             data() const;
    std::string                     print() const;
    NodeKind                        kind() const;
    static std::unique_ptr<IntLeaf> make_ptr(int value) { return std::make_unique<IntLeaf>(value); }
    unsigned int                    height() const { return 0u; };
    unsigned int                    node_count() const { return 1u; };

private:
    int          _value;
    unsigned int _height = 0u;
};