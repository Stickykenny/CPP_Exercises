#pragma once

#include <string>
#include "Card.hpp"
enum class SpellType
{
    Normal,
    Equip,
    Continuous,
    QuickPlay,
    Field,
};

const std::string
to_string(SpellType type)
{
    switch (type)
    {

    case SpellType::Normal:
        return "Normal";
    case SpellType::Equip:
        return "Equip";
    case SpellType::Continuous:
        return "Continuous";
    case SpellType::QuickPlay:
        return "Quick-Play";
    case SpellType::Field:
        return "Field";
    default:
        return "";
    }
}

class Spell : public Card
{
public:
    Spell(std::string id, std::string name, SpellType type) : Card{id, CardType::Spell}, _type{type}
    {
        this->set_name(name);
        _symbol = u8"魔";
    }
    SpellType get_spell_type() const
    {
        return _type;
    }

private:
    const SpellType _type;
};