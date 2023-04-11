#pragma once
#include <array>

template <typename P, int max>
std::array<P, max> fibonacci()
{
    /*std::array<P> arr;
    for (unsigned int i = 0; i < max; ++i)
    {
        arr
    }*/

    if (i < 2)
        return 1;
    else
        return fibonacci_runtime(i - 1) + fibonacci_runtime(i - 2);
}