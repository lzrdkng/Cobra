#include "SDL.hpp"
#include "Point.hpp"
#include "Color.hpp"


namespace SDLO
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
#ifdef SDL_IMAGE_H_
    quitImage();
#endif

    SDL_QuitSubSystem(SDL_WasInit(0));
    SDL_Quit();
  }

#ifdef SDL_IMAGE_H_
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

}
