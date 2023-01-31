#pragma once
#include <string>
#include <ostream>

class Kid
{
public:
    Kid(const std::string &name, int money) : _name{name},
                                              _money{money} {}
    int get_money()
        const
    {
        return _money;
    }
    const std::string &get_name()
        const
    {
        return _name;
    }
    friend std::ostream &operator<<(std::ostream &stream, const Kid &kid)
    {
        return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
    }
    void buy_plush(PlushStore store)
    {
    }

private:
    std::string _name;
    int _money;
};