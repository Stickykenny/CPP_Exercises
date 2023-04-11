#pragma once

#include "../lib/concatenate.hpp"

#include <list>
#include <string>
#include <utility>

void pairwise_concatenate(std::list<std::list<int>>& l1, const std::list<std::list<int>>& l2);
void pairwise_concatenate(std::list<std::list<int>>&  l1,
                          std::list<std::list<int>>&& l2); // fais en ce que tu veux je m'en fous
