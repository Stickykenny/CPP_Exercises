#pragma once

#include <string>
#include "Card.hpp"

enum class TrapType
{
    Normal,
    Continuous,
    Counter,
};

const std::string
to_string(TrapType type)
{
    switch (type)
    {

    case TrapType::Normal:
        return "Normal";
    case TrapType::Continuous:
        return "Continuous";
    case TrapType::Counter:
        return "Counter";
    default:
        return "";
    }
}

class Trap : public Card
{
public:
    Trap(std::string id, std::string name, TrapType type) : Card{id, CardType::Trap}, _type{type}
    {
        this->set_name(name);
        _symbol = u8"罠";
    }
    TrapType get_trap_type() const
    {
        return _type;
    }

private:
    const TrapType _type;
};