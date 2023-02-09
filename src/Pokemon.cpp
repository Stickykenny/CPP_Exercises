#include "Pokemon.h"

int Pokemon::id_cpt = 1;
Pokemon::Pokemon(const std::string &name)

    : _name{name}, _id{id_cpt++}
{
}
Pokemon::Pokemon(const Pokemon &other)

    : _name{other._name}, _id{id_cpt++}
{
}

const std::string &Pokemon::name() const
{
    return Pokemon::_name;
}

int Pokemon::id() const
{
    return Pokemon::_id;
}

Pokemon &Pokemon::operator=(const Pokemon &other)
{
    if (this != &other)
    {
        _name = other._name;
        _id = other._id;
    }
    return *this;
}