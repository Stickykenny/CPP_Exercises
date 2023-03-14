#pragma once
#include "../lib/Unit.hpp"

#include <vector>
class Kitchen
{
public:
    const Unit& register_unit(Unit u);
    const Unit* find_unit(const std::string& name) const;

private:
    std::vector<Unit> lst;
};
