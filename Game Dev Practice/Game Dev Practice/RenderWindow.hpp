#pragma once

#ifndef _RENDERWINDOW_HPP_
#define _RENDERWINDOW_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>

#include "Entity.hpp"


class RenderWindow
{
    public:
        RenderWindow(const char* title, int width, int height);

        SDL_Texture* loadTexture(const char* filePath);

        int getRefreshRate();

        void cleanUp();

        void clear();
        void render(Entity& entity);
        void renderEverything(std::vector<Entity>& entites);
        void display();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
};

#endif