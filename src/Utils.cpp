#include "Utils.hpp"
#include "Point.hpp"
#include "Color.hpp"


namespace SO
{
  void init(Init flags)
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
#ifdef _SDL_IMAGE_H
    quitImage();
#endif

    SDL_QuitSubSystem(SDL_WasInit(0));
    SDL_Quit();
  }

#ifdef _SDL_IMAGE_H
  void initImage(ImageInit flags)
  {

    int i_flags = static_cast<int>(flags);
    
    if ((IMG_Init(i_flags) & i_flags) != i_flags)
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
