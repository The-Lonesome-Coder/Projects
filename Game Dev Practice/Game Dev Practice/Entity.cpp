#include "Entity.hpp"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


Entity::Entity(Vector2f position, SDL_Texture* texture)
    : m_position { position }, m_texture {texture}
{
    m_currentFrame.x = 0;
    m_currentFrame.y = 0;
    m_currentFrame.w = 32;
    m_currentFrame.h = 32;
}


Vector2f Entity::getPosition() const
{
    return m_position;
}


SDL_Rect Entity::getCurrentFrame() const
{
    return m_currentFrame;
}


SDL_Texture* Entity::getTexture() const
{
    return m_texture;
}