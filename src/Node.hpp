#pragma once
#include "InstanceCounter.hpp"
#include "NodeKind.hpp"

#include <memory>
#include <string>

class Node;
class IntLeaf;
class StringLeaf;
class ArrayNode;
class ObjectNode;
using NodePtr = std::unique_ptr<Node>;

class Node : public InstanceCounter
{
protected:
    Node(NodeKind kind)
        : _kind { kind } {};

public:
    NodeKind            kind() const { return _kind; }
    virtual std::string print() const = 0;
    virtual ~Node() {}; // dire que le destructeur a utilisé n'est pas celui par défaut
    virtual unsigned int height() const     = 0;
    virtual unsigned int node_count() const = 0;

    IntLeaf*    as_IntLeaf();
    StringLeaf* as_StringLeaf();
    ArrayNode*  as_ArrayNode();
    ObjectNode* as_ObjectNode();

    const IntLeaf*    as_IntLeaf() const;
    const StringLeaf* as_StringLeaf() const;
    const ArrayNode*  as_ArrayNode() const;
    const ObjectNode* as_ObjectNode() const;

private:
    const NodeKind _kind;
};
