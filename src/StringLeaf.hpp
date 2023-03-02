#pragma once
#include "Leaf.hpp"
#include "NodeKind.hpp"

#include <string>

class StringLeaf : public Leaf
{
public:
    StringLeaf(const std::string& str);
    std::string                        data() const;
    std::string                        print() const;
    NodeKind                           kind() const;
    static std::unique_ptr<StringLeaf> make_ptr(std::string value)
    {
        return std::make_unique<StringLeaf>(value);
    }

    unsigned int height() const { return 0u; };
    unsigned int node_count() const { return 1u; };

private:
    std::string _str;
};