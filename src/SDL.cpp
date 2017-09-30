#include "SDL.hpp"
#include "Color.hpp"

using namespace SDL;

Color getRGB(Uint32 pixel, PixelFormat& format)
{
  Uint8 r, g, b = 0, 0, 0;

  SDL_GetRGB(pixel, format.toSDL(), &r, &g, &b);

  return Color::fromRGB(r, g, b);
}
