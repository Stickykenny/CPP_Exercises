#pragma once
#include "Node.hpp"
#include "NodeKind.hpp"

#include <map>
#include <string>

class ObjectNode : public Node
{
public:
    ObjectNode();

    std::string                        print() const;
    NodeKind                           kind() const;
    static std::unique_ptr<ObjectNode> make_ptr() { return std::make_unique<ObjectNode>(); };
    unsigned int                       child_count() const;
    void                               insert(const std::string key, NodePtr value);
    unsigned int                       height() const;
    unsigned int                       node_count() const;

private:
    std::string                    _str;
    unsigned int                   _child_count = 0;
    std::map<std::string, NodePtr> _dico;
};