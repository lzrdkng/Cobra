#ifndef WINDOWSURFACE_HPP
#define WINDOWSURFACE_HPP

#include "Surface.hpp"
#include "Window.hpp"

namespace SO
{

  class WindowSurface : public Surface
  {

  public:

    explicit WindowSurface(Window& window)
      : Surface(SDL_GetWindowSurface(window.toSDL())) {}

    virtual ~WindowSurface() { m_surface = nullptr; }


  };

}


#endif // WINDOWSURFACE_HPP
