#include "catch.hpp"

#include "SDL.hpp"
#include "Application.hpp"
#include "Window.hpp"
#include "WindowSurface.hpp"
#include "Rect.hpp"

#define INTERACT 0 // Flip this bit if you want to interect with each tutorial

/*********************************************************
 * TODO list
 *
 *[2] : Implement wrapper around SDL_Event structure/union
 *[3] : Keys constants
 ***********************************************************/


TEST_CASE("Creating a window", "[window, tutorial")
{
    SDL::Application::init(SDL::InitVideo);

    SDL::Window window("SDL Tutorial");

    SDL::WindowSurface screenSurface(window);

    screenSurface.fillRect(12000);

    window.update();

    SDL::Application::delay(200);
}

TEST_CASE("Getting an image on the screen", "[image, tutorial]")
{
    SDL::Application::init(SDL::InitVideo);

    SDL::Window window("SDL Tutorial");

    SDL::WindowSurface screenSurface(window);

    SDL::Surface imageSurface("media/hello_world.bmp");

    imageSurface.blit(screenSurface);

    window.update();

    SDL::Application::delay(200);
}

TEST_CASE("Event driven programming", "[event, tutorial")
{
    SDL::Application::init(SDL::InitVideo);

    SDL::Window window("SDL Tutorial");

    SDL::WindowSurface windowSurface(window);

    SDL::Surface imageSurface("media/x.bmp");

    SDL_Event event; // [2]

    bool quit = false;

    do
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        imageSurface.blit(windowSurface);
        window.update();

        SDL::Application::delay(200);

    }  while (!quit && INTERACT);
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

    SDL::Application::init(SDL::InitVideo);

    SDL::Window window("SDL Tutorial");

    SDL::WindowSurface windowSurface(window);

    SDL::Surface* keyPressSurfaces[KeyPressSurfaceTotal] = {new SDL::Surface("media/press.bmp"),
                                                            new SDL::Surface("media/up.bmp"),
                                                            new SDL::Surface("media/down.bmp"),
                                                            new SDL::Surface("media/left.bmp"),
                                                            new SDL::Surface("media/right.bmp")
                                                           };

    SDL::Surface* currentSurface = keyPressSurfaces[KeyPressSurfaceDefault];

    SDL_Event event; // [2]

    bool quit = false;

    do
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
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
        }

        currentSurface->blit(windowSurface);
        window.update();

        SDL::Application::delay(200);

    }  while (!quit && INTERACT);

    currentSurface = nullptr;

    for (int i=0; i<KeyPressSurfaceTotal; ++i)
    {
        delete keyPressSurfaces[i];
    }
}

TEST_CASE("Optimized surface loading and soft stretching", "[surface, stretch, tutorial]")
{
    SDL::Application::init(SDL::InitVideo);

    SDL::Window window("SDL Tutorial");

    SDL::WindowSurface windowSurface(window);

    SDL::Surface stretchedSurface("media/stretch.bmp", &windowSurface);


    SDL_Event event; // [2]

    bool quit = false;

    do
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL::Rect stretchRect(0, 0, 640, 480);

        stretchedSurface.blitScaled(windowSurface, stretchRect);
        window.update();

        SDL::Application::delay(200);

    } while (!quit && INTERACT);

}


#ifdef _SDL_IMAGE_H
TEST_CASE("Extension libraries and loading other image formats", "[SDL_image, lib, image, tutorial]")
{
    SDL::Application::init(SDL::InitVideo);

    SDL::Window window("SDL Tutorial");


}
#endif
