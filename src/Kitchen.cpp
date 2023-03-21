#include "Kitchen.hpp"

#include "../lib/Unit.hpp"

#include <algorithm>
#include <memory>
#include <utility>
const Unit& Kitchen::register_unit(Unit u)
{
    return *lst.emplace_back(std::make_unique<Unit>(u));

    // return lst.emplace_back(std::move(u));

    // on renvoie l'élem de la liste

    // move = cast de type
    //  appel fct de détruire / il est possible qu'il n'est pas détruit
};
const Unit* Kitchen::find_unit(const std::string& name) const
{
    const auto it = std::find_if(lst.begin(), lst.end(),
                                 [name](const std::unique_ptr<Unit>& unitu) { return unitu->name == name; });

    if (it == lst.end())
    {
        return nullptr;
    }
    return (*it).get();
    // it => l'itérateur
    // *it => valeur pointé par l'itérateur : dans ce cas c'est unique_ptr : const std::unique_ptr<Unit>
    // **it => valeur de l'unique_ptr dans l'itérateur : Unit

    // &(*it) => l'addresse de l'unique_ptr
    //
};

// (it->get()); c'est pareil que (*it).get();

/*
const Unit* Kitchen::find_unit(const std::string& name) const
{
    const auto it = std::find_if(lst.begin(), lst.end(),
                                 [name](const std::unique_ptr<Unit>& unitu) { return unitu->name == name; });

    if (it == lst.end())
    {
        return nullptr;
    }
    return (it->get());
};*/
