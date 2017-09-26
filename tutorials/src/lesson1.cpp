#include "SDL.hpp"
#include "Window.hpp"
#include "Renderer.hpp"


const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;

typedef bool (*FP)();

bool lesson_1()
{

    try
    {
        SDL::init(SDL::InitVideo);

        {
            SDL::Window window("SDL Tutorial", SDL::WindowPositionUndefined, SDL::WindowPositionUndefined, SCREEN_WIDTH, SCREEN_HEIGHT, SDL::WindowShown);
        }

        SDL::quit();

    }
    catch (SDL::Error& error)
    {
        error.what();
        return false;
    }

    return true;
}


void main()
{
    const FP array[1] = {lesson_1};

    for (auto& f : array)
    {
        if (!f())
        {

        }
    }

}
