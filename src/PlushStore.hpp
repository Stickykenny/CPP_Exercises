#pragma once
#include <string>
#include <algorithm>

class PlushStore
{
public:
    PlushStore() {}
    PlushStore(std::string name)
        : _name{name} {}

    std::string get_name() const
    {
        return _name;
    }
    int get_wealth_amount() const
    {
        return _wealth;
    }
    int get_stock_size() const
    {
        return _stock_size;
    }
    unsigned int get_debt_amount()
    {
        return _debt;
    }
    void loan(unsigned int loan_amount)
    {
        _wealth += loan_amount;
        _debt += loan_amount + loan_amount * 0.1;
    }

    int make_plush(int price)
    {
        if (_wealth == 0)
        {
            return 0;
        }
        _stock_size += 1;
        _experience += 1;
        if (price > _wealth)
        {
            _wealth = 0;
            int invested_value = price - _wealth;
            return invested_value + std::max(invested_value * _experience / 100, _experience);
        }
        else
        {
            _wealth -= price;
            int invested_value = price;
            return invested_value + std::max(invested_value * _experience / 100, _experience);
        }
        // valeur finale <- valeur investie + max(exp, exp * valeur investie / 100)
    }
    int get_experience()
        const
    {
        return _experience;
    }
    std::optional<Plush> buy(int price)
    {
        _wealth += price;
        _stock_size -= 1;
        }

private:
    std::string _name;
    int _wealth = 0;
    int _stock_size = 0;
    unsigned int _debt = 0u;
    unsigned int _experience = 0u;
};