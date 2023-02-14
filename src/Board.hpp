#pragma once

#include <vector>
#include <memory>
#include "Card.hpp"

class Board
{

    // UNFINISHED
public:
    bool put(const Card &card)
    {
        board.emplace_back(std::move(&card));
        if (board.size() == size + 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    std::vector<std::unique_ptr<Card *>> board;
    unsigned int size = 0;
};