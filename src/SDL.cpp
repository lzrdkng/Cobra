#include "SDL.hpp"
#include "Color.hpp"

SDL::Color SDL::getRGB(Uint32 color, SDL_PixelFormat* format)
{
  Uint8 r = 0, g = 0, b = 0;

  SDL_GetRGB(color, format, &r, &g, &b);

  return SDL::Color::fromRGB(r, g, b);
}
