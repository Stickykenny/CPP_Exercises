#pragma once
#include "../lib/Consumable.hpp"
#include "../lib/Cupboard.hpp"
#include "../lib/Ingredient.hpp"
#include "../lib/Unit.hpp"

#include <memory>
#include <optional>
#include <random>
#include <set>
#include <utility>
#include <vector>

class Kitchen
{
public:
    const Unit&       register_unit(Unit u);
    const Unit*       find_unit(const std::string& name) const;
    const Ingredient& register_ingredient(Ingredient ing);
    const Ingredient* find_ingredient(const std::string& name) const;

    std::optional<Consumable> make_random_consumable(float qty, unsigned int expiration);

    const Cupboard& get_cupboard() const { return _cupboard; };

private:
    std::random_device                       _rd;
    std::vector<std::unique_ptr<Unit>>       _lst;
    std::vector<std::unique_ptr<Ingredient>> _ingredients;

    Cupboard _cupboard;
};
