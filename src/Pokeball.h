#pragma once

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const;
    void store();

private:
    bool _empty = true;
};
