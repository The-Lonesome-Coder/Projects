#pragma once

#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "Math.hpp"


class Entity
{
    public:
        Entity(Vector2f position, SDL_Texture* texture);

        Vector2f getPosition() const;
        SDL_Rect getCurrentFrame() const;
        SDL_Texture* getTexture() const;


    private:
        Vector2f m_position;
        SDL_Rect m_currentFrame;
        SDL_Texture* m_texture;
};


#endif