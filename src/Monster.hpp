#pragma once

#include <string>
#include <sstream>
#include "Card.hpp"
enum class Attribute
{
    Dark,
    Divine,
    Earth,
    Fire,
    Light,
    Water,
    Wind,
};

const std::string to_symbol(const Attribute attribute)
{
    switch (attribute)
    {
    case Attribute::Dark:
        return u8"闇";
    case Attribute::Divine:
        return u8"神";
    case Attribute::Earth:
        return u8"地";
    case Attribute::Fire:
        return u8"炎";
    case Attribute::Light:
        return u8"光";
    case Attribute::Water:
        return u8"水";
    case Attribute::Wind:
        return u8"風";
    default:
        return "";
    }
}

class Monster : public Card
{
public:
    Monster(std::string id, std::string name, Attribute attribute, std::string type, unsigned int atk, unsigned int def) : Card{id, CardType::Monster}, _attribute{attribute}, _type{type}, _atk{atk}, _def{def}
    {
        this->set_name(name);
        _symbol = to_symbol(_attribute);
    }
    Attribute get_attribute() const
    {
        return _attribute;
    }
    unsigned int get_atk() const
    {
        return _atk;
    }
    unsigned int get_def() const
    {
        return _def;
    }

    const std::string get_description() const
    {
        std::stringstream ss;
        ss << "[" << _type << "]\n"
           << Card::get_description() << "\nATK/" << _atk << " DEF/" << _def;
        return ss.str();
        //"[Magicien]\nMage suprême en terme d'attaque et de défense.\nATK/2500 DEF/2100");
    }

private:
    const Attribute _attribute;
    std::string _type;
    unsigned int _atk;
    unsigned int _def;
};