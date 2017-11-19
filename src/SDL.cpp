#include "SDL.hpp"
#include "Point.hpp"
#include "Color.hpp"


namespace SDL
{

  void init(InitFlags flags)
  {
    static bool isInit = false;

    if (!isInit)
      {
        if (SDL_Init(flags) != 0)
	  {
            throw Error(SDL_GetError());
	  }

        isInit = true;
      }
    else
      {
        if (SDL_InitSubSystem(flags) != 0)
	  {
            throw Error(SDL_GetError());
	  }
      }
  }

  Uint32 wasInit(InitFlags flags)
  {
    return SDL_WasInit(static_cast<Uint32>(flags));
  }

  void quit()
  {
#ifdef _SDL_IMAGE_H
    quitImage();
#endif

    SDL_QuitSubSystem(SDL_WasInit(0));
    SDL_Quit();
  }

#ifdef _SDL_IMAGE_H
  void initImage(ImageInitFlags flags)
  {
    if ((IMG_Init(static_cast<int>(flags)) & flags) != flags)
      {
        throw Error(IMG_GetError());
      }
  }

  void quitImage()
  {
    IMG_Quit();
  }
#endif

  void delay(Uint32 ms)
  {
    SDL_Delay(ms);
  }

  bool setHint(const char* name, const char* value)
  {
    return static_cast<bool>(SDL_SetHint(name, value));
  }

  Color getRGB(Uint32 color, SDL_PixelFormat* format)
  {
    Uint8 r = 0, g = 0, b = 0;

    SDL_GetRGB(color, format, &r, &g, &b);

    return Color {r, g, b};
  }

  // scale ratio : cartesian/screen

  Coord screenToCartesian(const Point& screenCoord,
			  uint width,
			  uint height,
			  double scale,
			  const Coord& offset)
  {
    Coord cartesianCoord(screenCoord.getX() - width/2, height/2 - screenCoord.getY());

    cartesianCoord *= scale;

    cartesianCoord += offset;

    return cartesianCoord;
  }

  // scale ratio : screen/cartesian

  Point cartesianToScreen(const Coord& cartesianCoord,
			  uint width,
			  uint height,
			  const Coord& offset,
			  double scale)
  {

    Point screenCoord(static_cast<int>(std::round(std::real(cartesianCoord) * scale + width/2)),
		      static_cast<int>(std::round(-std::imag(cartesianCoord) * scale + height/2)));

    //screenCoord -= offset;

    //screenCoord *= scale;

    //screenCoord += Coord {width/2, height/2};

    return screenCoord;
  }

}
