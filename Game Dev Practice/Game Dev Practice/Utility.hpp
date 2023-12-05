#pragma once

#ifndef _UTILITY_HPP
#define _UTILITY_HPP


#include <SDL/SDL.h>

namespace utility
{
    float tickPerSecond()
    {
        float tick = SDL_GetTicks();
        tick *= 0.001f;

        return tick;
    }
}


#endif // !_UTILITY_HPP
