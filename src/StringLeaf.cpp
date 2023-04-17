
#include "StringLeaf.hpp"

#include "NodeKind.hpp"

#include <string>

std::string StringLeaf::data() const
{
    return _str;
}
std::string StringLeaf::print() const
{
    return "\"" + _str + "\"";
}
NodeKind StringLeaf::kind() const
{
    return NodeKind::STRING;
}