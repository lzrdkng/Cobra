#include <complex>
#include <iostream>
#include <iomanip>

#include "Mandelbrot.hpp"

#include "SDL.hpp"
#include "Application.hpp"
#include "Window.hpp"

typedef std::complex<long double> Complex;

const Complex origin(0.3007597002215182, 0.0201501598261257);

int main()
{

    SDL::Application::init(SDL::InitVideo);

    SDL::Window root("Mandelbrot");

    Mandelbrot mandelbrot(root, origin, 2, 1000);

    mandelbrot.renderImage();

    SDL_Event event;

    bool quit = false;

    std::cout << std::setprecision(17);

    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
                break;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_DOWN:
                    break;
                case SDLK_UP:
                    break;
                case SDLK_LEFT:
                    break;
                case SDLK_RIGHT:
                    break;
                case SDLK_SPACE:
                    mandelbrot.zoomIn(2);
                    break;
                case SDLK_LSHIFT:
                    mandelbrot.zoomIn(0.5);
                    break;
                default:
                    break;
                }

                SDL_FlushEvent(SDL_KEYDOWN);

                std::cout << "Center: " << mandelbrot.getCenter() << "\nZoom: " << mandelbrot.getZoom() << "\nEpsilon: " << mandelbrot.getEpsilon() << "\n----------------------" << std::endl;

                mandelbrot.renderImage();
            }
        }
    }

    return 0;
}
