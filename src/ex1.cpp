#include "ex1.hpp"

void pairwise_concatenate(std::list<std::list<int>>& l1, const std::list<std::list<int>>& l2)
{

    auto it2 = l2.begin();
    for (auto it = l1.begin(); it != l1.end(); ++it)
    {
        concatenate(*it, *it2);
        ++it2;
    }
}
void pairwise_concatenate(std::list<std::list<int>>& l1, std::list<std::list<int>>&& l2)
{
    for (unsigned i = l1.size(); i < l2.size(); ++i)
        l1.emplace_back();
    // this here don't work anymore due to std::move
    // auto it2 = l2.begin();
    // for (auto it = l1.begin(); it != l1.end(); ++it)
    // {
    //     concatenate(*it, std::move(*it2));
    //     ++it2;
    // }

    auto it = l1.begin();
    for (auto it2 = l2.begin(); it2 != l2.end(); ++it2)
    {
        concatenate(*it, std::move(*it2));
        ++it;
    }
}