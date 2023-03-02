
#include "ArrayNode.hpp"

#include "Node.hpp"
#include "NodeKind.hpp"

#include <sstream>
#include <string>

ArrayNode::ArrayNode()
{}
std::string ArrayNode::print() const
{

    std::string result = "[";
    for (size_t i = 0; i != _array.size(); ++i)
    {
        if (i > 0)
        {

            result += ",";
        }
        result += _array.at(i)->print();
    }
    result += "]";
    return result;
}
NodeKind ArrayNode::kind() const
{
    return NodeKind::ARRAY;
}
unsigned int ArrayNode::child_count() const
{
    return _array.size();
}

void ArrayNode::push_back(NodePtr node)
{
    _array.emplace_back(std::move(node));
}

unsigned int ArrayNode::height() const
{
    unsigned int result = 0u;

    for (size_t i = 0; i != _array.size(); ++i)
    {
        result = std::max(result, _array.at(i)->height());
    }
    return result + 1;
}

unsigned int ArrayNode::node_count() const
{
    unsigned int result = 0u;

    for (size_t i = 0; i != _array.size(); ++i)
    {
        result += _array.at(i)->node_count();
    }
    return result + 1;
}
