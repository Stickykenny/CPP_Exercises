#include "Kitchen.hpp"

#include "../lib/Unit.hpp"

#include <algorithm>
#include <memory>
#include <utility>
const Unit& Kitchen::register_unit(Unit u)
{
    return lst.emplace_back((u));

    // return lst.emplace_back(std::move(u));

    // on renvoie l'élem de la liste

    // move = cast de type
    //  appel fct de détruire / il est possible qu'il n'est pas détruit
};

const Unit* Kitchen::find_unit(const std::string& name) const
{
    const auto it =
        std::find_if(lst.begin(), lst.end(), [name](const Unit& unitu) { return unitu.name == name; });

    if (it == lst.end())
    {
        return nullptr;
    }
    return &(*it); // to obtain Unit* and not the value it points to
};
