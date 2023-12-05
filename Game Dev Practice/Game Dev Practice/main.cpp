#define SDL_MAIN_HANDLED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include <vector>
#include <iostream>

#include "Entity.hpp"
#include "RenderWindow.hpp"
#include "Utility.hpp"


int main()
{
    // Initialize SDL2
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_INIT HAS FAILED. SDL ERROR: " << SDL_GetError() << std::endl;
    }

    // Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
    }

    // Create the window
    RenderWindow window { "Game v1.0", 1280, 720 };

    std::cout << window.getRefreshRate() << std::endl;

    SDL_Texture* eggTexture { window.loadTexture("res/gfx/Egg.png") };

    std::vector<Entity> entities {
                                    Entity(Vector2f { 100, 50 }, eggTexture),
                                    Entity(Vector2f { 56, 30 }, eggTexture),
                                    Entity(Vector2f { 0, 30 }, eggTexture)
                                 };

    // Flat for checking game is running
    bool gameRunning = true;

    SDL_Event event;

    const float timeStep { 0.01f };
    float accumulator = 0.0f;
    float currentTime = utility::tickPerSecond();

    // Game loop
    while (gameRunning)
    {
        int startTick = SDL_GetTicks();

        float newTime = utility::tickPerSecond();
        float frameTime = newTime- currentTime;

        if (frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }
            }

            accumulator -= timeStep;
        }

        const float alpha { accumulator / timeStep };

        window.clear();
        window.renderEverything(entities);
        window.display();

        int frameTicks = SDL_GetTicks() - startTick;

        if (int rate { window.getRefreshRate() }; frameTicks < 1000 / rate)
        {
            SDL_Delay(1000 / rate - frameTicks);
        }

    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}