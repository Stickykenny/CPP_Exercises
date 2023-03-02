
#include "StringLeaf.hpp"

#include "NodeKind.hpp"

#include <string>

StringLeaf::StringLeaf(const std::string& str)
    : _str { str }
{}
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