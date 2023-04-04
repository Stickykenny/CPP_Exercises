#pragma once

#include "../lib/lib.hpp"
#include "pixels.hpp"

#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <stdint.h>
#include <string>

template <typename P, size_t W, size_t H>
// const Image<char, 1, 1> img(6); => remplace P par char, etc..
// typename P est en quelque sorte un générique

class Image
{
public:
    // Image(typename P, size_t W, size_t H) {}
    Image(const P& pix)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                _tableau[j][i] = pix;
            }
        }
    };
    Image() = default;

    P&       operator()(const size_t i, const size_t j) { return _tableau[j][i]; };
    const P& operator()(const size_t i, const size_t j) const { return _tableau[j][i]; };
    Image<P, W, H>(const std::function<P(const size_t i, const size_t j)>& functor)
    {
        for (size_t j = 0; j < H; ++j)
        {
            for (size_t i = 0; i < W; ++i)
            {
                (*this)(i, j) = functor(i, j);
            }
        }
    }

private:
    std::array<std::array<P, W>, H> _tableau;
};