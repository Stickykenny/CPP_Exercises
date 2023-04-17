
#include "IntLeaf.hpp"

#include "NodeKind.hpp"

#include <memory>
#include <string>

int IntLeaf::data() const
{
    return _value;
}
std::string IntLeaf::print() const
{
    return std::to_string(_value);
}
NodeKind IntLeaf::kind() const
{
    return NodeKind::INT;
}
