#pragma once

class Plush
{
public:
    Plush() {} // pas besoin y'a déjà
    Plush(unsigned int cost)

        : _cost{
              cost}
    {
    }

    unsigned int get_cost()
        const
    {
        return _cost;
    }
    void set_cost(int new_cost)
    {
        _cost = new_cost;
    }

private:
    unsigned int _cost = 10u;
};