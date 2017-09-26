#include "catch.hpp"

#include "SDL.hpp"
#include "Application.hpp"
#include "Window.hpp"
#include "WindowSurface.hpp"

TEST_CASE("Creating a window", "[window, tutorial")
{
    SDL::Application::init(SDL::InitVideo);

    SDL::Window window("SDL Tutorial", 250, 250, 480, 360, SDL::WindowResizable);

    SDL::WindowSurface screenSurface(window);

    screenSurface.fillRect(12000);

    window.update();

    SDL::Application::delay(2000);
}
