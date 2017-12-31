#include "Utils.hpp"
#include "Point.hpp"
#include "Color.hpp"


namespace SDLO
{
  void init(InitFlags flags)
  {
    static bool isInit = false;

    if (!isInit)
    {
      if (SDL_Init(static_cast<Uint32>(flags)) != 0)
      {
	throw Error(SDL_GetError());
      }

      isInit = true;
    }
    else
    {
      if (SDL_InitSubSystem(static_cast<Uint32>(flags)) != 0)
      {
	throw Error(SDL_GetError());
      }
    }
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
  void initImage(ImageInit flags)
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

}
