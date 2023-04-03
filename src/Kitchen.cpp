#include "Kitchen.hpp"

#include "../lib/Consumable.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <algorithm>
#include <cstring>
#include <memory>
#include <random>
#include <utility>

const Unit& Kitchen::register_unit(Unit u)
{
    return *_lst.emplace_back(std::make_unique<Unit>(u));

    // return lst.emplace_back(std::move(u));

    // on renvoie l'élem de la liste

    // move = cast de type
    //  appel fct de détruire / il est possible qu'il n'est pas détruit
};
const Unit* Kitchen::find_unit(const std::string& name) const
{
    const auto it = std::find_if(_lst.begin(), _lst.end(),
                                 [name](const std::unique_ptr<Unit>& unitu) { return unitu->name == name; });

    if (it == _lst.end())
    {
        return nullptr;
    }
    return (*it).get(); // same as it->get()
    // it => l'itérateur
    // *it => valeur pointé par l'itérateur : dans ce cas c'est unique_ptr : const std::unique_ptr<Unit>
    // **it => valeur de l'unique_ptr dans l'itérateur : Unit

    // &(*it) => l'addresse de l'unique_ptr
    //
};

const Ingredient& Kitchen::register_ingredient(Ingredient ing)
{
    return *_ingredients.emplace_back(std::make_unique<Ingredient>(ing));
};

const Ingredient* Kitchen::find_ingredient(const std::string& name) const
// Pour comparer case insensitive
// lire les strings char par char
// et std::tolower chaque char
{
    const auto it = std::find_if(_ingredients.begin(), _ingredients.end(),
                                 [name](const std::unique_ptr<Ingredient>& ingredient)
                                 {
                                     for (unsigned int s = 0; s < name.length(); ++s)
                                     {
                                         if (std::tolower(ingredient->name[s]) != std::tolower(name[s]))
                                         {
                                             return false;
                                         }
                                     }
                                     return true;
                                 });
    if (it == _ingredients.end())
    {
        return nullptr;
    }
    return it->get();
};
std::optional<Consumable> Kitchen::make_random_consumable(float qty, unsigned int expiration)
{
    if (_ingredients.empty())
    {
        return std::nullopt;
    }
    auto pos = std::uniform_int_distribution<size_t>(0u, _ingredients.size() - 1u);

    const auto& ing = *std::next(_ingredients.begin(), pos(_rd))->get();

    return Consumable { ing, qty, expiration };
};
