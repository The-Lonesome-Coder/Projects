#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <iostream>
#include <vector>

#include "Entity.hpp"
#include "RenderWindow.hpp"



RenderWindow::RenderWindow(const char* title, int width, int height)
    : m_window { nullptr }, m_renderer { nullptr }
{
    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    // If create window failed
    if (m_window == nullptr)
    {
        std::cout << "Window failed to initialize. Error: " << SDL_GetError() << std::endl;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
}


SDL_Texture* RenderWindow::loadTexture(const char* filePath)
{
    SDL_Texture* texture { nullptr };

    texture = IMG_LoadTexture(m_renderer, filePath);

    if (texture == nullptr)
    {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }

    return texture;
}


int RenderWindow::getRefreshRate()
{
    int displayIndex { SDL_GetWindowDisplayIndex(m_window) };

    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}


void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(m_window);
}


void RenderWindow::clear()
{
    SDL_RenderClear(m_renderer);
}


void RenderWindow::render(Entity& entity)
{
    SDL_Rect source;
    source.x = entity.getCurrentFrame().x;
    source.y = entity.getCurrentFrame().y;
    source.w = entity.getCurrentFrame().w;
    source.h = entity.getCurrentFrame().h;

    SDL_Rect destination;
    destination.x = entity.getPosition().m_x * 4;
    destination.y = entity.getPosition().m_y * 4;
    destination.w = entity.getCurrentFrame().w * 4;
    destination.h = entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(m_renderer, entity.getTexture(), &source, &destination);
}


void RenderWindow::renderEverything(std::vector<Entity>& entities)
{
    for (auto& entity : entities)
    {
        this->render(entity);
    }
}


void RenderWindow::display()
{
    SDL_RenderPresent(m_renderer);
}