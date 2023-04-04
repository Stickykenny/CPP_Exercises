#pragma once

#include "../lib/lib.hpp"

#include <stdint.h>

struct RGBA
{
    uint8_t r, g, b, a;
};
struct RGB
{
    uint8_t r, g, b;
};
struct Luma
{
    uint8_t gray;
};