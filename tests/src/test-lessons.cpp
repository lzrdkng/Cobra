// std imports
#include <vector>

// catch import
#include "catch.hpp"

// lib imports
#include "SDL.hpp"
#include "Window.hpp"
#include "WindowSurface.hpp"
#include "Rect.hpp"

#define INTERACT 1 // Flip this bit if you want to interact with each tutorial


/******************************************************************************
 * TODO list
 *
 * [2] : Implement wrapper around SDL_Event structure/union
 * [3] : Keys constants : https://wiki.libsdl.org/SDL_Keycode
 ******************************************************************************
 */

TEST_CASE("Init subsystems")
{
    SDL::init(SDL::InitEverything);

#ifdef _SDL_IMAGE_H
    SDL::initImage(SDL::ImageInitPNG);
#endif
}

TEST_CASE("Creating a window", "[window, tutorial]")
{
    SDL::Window window("Creating a window [1]");

    SDL::WindowSurface screenSurface(window);

    screenSurface.fillRect(12000);

    window.update();
}

TEST_CASE("Getting an image on the screen", "[image, tutorial]")
{
    SDL::Window window("Getting an image on the screen [2]");

    SDL::WindowSurface screenSurface(window);

    SDL::Surface imageSurface("media/hello_world.bmp", &screenSurface);

    imageSurface.blit(screenSurface);

    window.update();
}

TEST_CASE("Event driven programming", "[event, tutorial")
{
    SDL::Window window("Event driven programming [3]");

    SDL::WindowSurface windowSurface(window);

    SDL::Surface imageSurface("media/x.bmp");

    SDL_Event event; // [2]

    // Main loop
    do
    {
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            break;
        }
        else
        {
            imageSurface.blit(windowSurface);
            window.update();
        }
    } while (INTERACT);
}

TEST_CASE("Key presses", "[key, tutorial")
{
    enum KeyPressSurfaces
    {
        KeyPressSurfaceDefault,
        KeyPressSurfaceUp,
        KeyPressSurfaceDown,
        KeyPressSurfaceLeft,
        KeyPressSurfaceRight,
        KeyPressSurfaceTotal
    };



    SDL::Window window("Key presses [4]");

    SDL::WindowSurface windowSurface(window);

    std::vector<SDL::Surface*> keyPressSurfaces =

                                        {
                                         new SDL::Surface("media/press.bmp"),
                                         new SDL::Surface("media/up.bmp"),
                                         new SDL::Surface("media/down.bmp"),
                                         new SDL::Surface("media/left.bmp"),
                                         new SDL::Surface("media/right.bmp")
                                        };

    SDL::Surface* currentSurface = keyPressSurfaces[KeyPressSurfaceDefault];

    SDL_Event event; // [2]

    // Main Loop
    do
    {
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            break;
        }
        else if (event.type == SDL_KEYDOWN) // [3]
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_UP:
                    currentSurface = keyPressSurfaces[KeyPressSurfaceUp];
                    break;
                case SDLK_DOWN:
                    currentSurface = keyPressSurfaces[KeyPressSurfaceDown];
                    break;
                case SDLK_LEFT:
                    currentSurface = keyPressSurfaces[KeyPressSurfaceLeft];
                    break;
                case SDLK_RIGHT:
                    currentSurface = keyPressSurfaces[KeyPressSurfaceRight];
                    break;
                default:
                    currentSurface = keyPressSurfaces[KeyPressSurfaceDefault];
            }
        }
        else
        {
            currentSurface->blit(windowSurface);
            window.update();
        }

    } while (INTERACT);

    currentSurface = nullptr;

    for (std::vector<SDL::Surface*>::iterator it = keyPressSurfaces.begin();
         it != keyPressSurfaces.end(); ++it)
    {
        delete *it;
    }
    keyPressSurfaces.clear();
}

TEST_CASE("Optimized surface loading and soft stretching",
          "[surface, stretch, tutorial]")
{
    SDL::Window window("Optimized surface loading and soft stretching [5]");

    SDL::WindowSurface windowSurface(window);

    SDL::Surface stretchedSurface("media/stretch.bmp", &windowSurface);

    SDL::Rect stretchRect(0, 0, 640, 480);

    stretchedSurface.blitScaled(windowSurface, stretchRect);

    window.update();

    SDL_Event event; // [2]

    // Main Loop
    do
    {
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            break;
        }

    }  while(INTERACT);
}


#ifdef _SDL_IMAGE_H
TEST_CASE("Extension libraries and loading other image formats"
          "[SDL_image, lib, image, tutorial]")
{
    SDL::Window window("Extension libraries and loading other image formats "
                       "[6]");

    SDL::WindowSurface windowSurface(window);

    SDL::Surface pngSurface("media/loaded.png", &windowSurface);

    pngSurface.blit(windowSurface);

    window.update();
}
#endif

#ifdef _SDL_IMAGE_H
#endif

TEST_CASE("Quit all subsystem")
{
    SDL::quit();
}
