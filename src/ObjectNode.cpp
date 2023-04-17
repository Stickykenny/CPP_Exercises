
#include "ObjectNode.hpp"

#include "NodeKind.hpp"

#include <string>

std::string ObjectNode::print() const
{
    std::string result = "{";
    for (auto i = _dico.begin(); i != _dico.end(); ++i)
    {
        if (i != _dico.begin())
        {
            result += ",";
        }
        result += "\"" + i->first + "\":" + i->second->print();
    }
    result += "}";
    return result;
}
NodeKind ObjectNode::kind() const
{
    return NodeKind::OBJECT;
}
unsigned int ObjectNode::child_count() const
{
    return _dico.size();
}

void ObjectNode::insert(const std::string key, NodePtr value)
{
    _dico.emplace(key, std::move(value));
}
unsigned int ObjectNode::height() const
{
    unsigned int result = 0u;
    if (this->child_count() == 0)
    {
        return 0u;
    }

    for (auto i = _dico.begin(); i != _dico.end(); ++i)
    {
        result = std::max(result, i->second->height());
    }
    return result + 1;
}

unsigned int ObjectNode::node_count() const
{
    unsigned int result = 1u;

    for (auto i = _dico.begin(); i != _dico.end(); ++i)
    {
        result += i->second->node_count();
    }
    return result;
}
Node* ObjectNode::at(const std::string& key)
{
    if (has_child(key))
        return _dico.at(key).get();
    else
        return nullptr;
}