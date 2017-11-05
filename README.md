#  Cobra

### A **C++** wrapper around [SDL](https://www.libsdl.org/) cross-platform development library.

## Dependencies
**Cobra** is intend to work with all **SDL2** major version.
Other libraries such as [SDL_image](https://www.libsdl.org/projects/SDL_image/),
[SDL_ttf] (https://www.libsdl.org/projects/SDL_ttf/) work too.

## Build library
To **build** the shared library, use **make**.

## To install
Use **sudo make install**.

There's no configure file yet. If you don't want to use **SDL_image**
1. In **SDL.hpp**, remove the **#include <SDL2/SDL_image.h>** macro.
2. In **Makefile**, remove **lSDL2_image** of **LIBS**.

## Testings
 **Cobra** uses [Catch](https://github.com/philsquared/Catch) for its testing.

To **run** tests, use **make tests**.

To **create** tests, you simply have to create a **.cpp** file under the directory **tests/src**. 

## Documentation

**Cobra** uses [Doxygen](http://www.stack.nl/~dimitri/doxygen/) to generate documentation.

To **generate** documentaion, use **make doc**.

To make **Cobra** easier to use, every class wrapper use the (almost) same 
documentation provided by the SDL's [wiki](https://wiki.libsdl.org/).

Every other none wrapper class offered by **Cobra** follow the exact same documentation style.

## Namespace and constants

Every **class** and **enum** are in **SDL** namespace. This ensure there's
no name collision. 

Talking about name, **Cobra** uses the same name defined by  **SDL**.

*For examples*

 **SDL_Window** -> **SDL::Window**
 
**SDL_GetWindowPosition** -> **SDL::Window::getPosition**

**SDL_Renderer** -> **SDL::Renderer**

**SDL_RenderSetScale** -> **SDL::Renderer::setScale**

Constants have also been re-written in **enum**.

*For examples*

**SDL_INIT_VIDEO** -> **SDL::InitFlags::InitVideo**

**SDL_WINDOW_FULLSCREEN** -> **SDL::WindowFlags::WindowFullScreen**


## Usage

~~~ C++

#include <Cobra/SDL.hpp>
#include <Cobra/Application.hpp>
#include <Cobra/Window.hpp>
#include <Cobra/Renderer.hpp>

int main()
{
  // Call to SDL_Init with flag SDL_INIT_VIDEO
  SDL::init(SDL::InitVideo);
  
  // Create a resizable window at position (0,0) of size (250, 250)
  SDL::Window root("Minimal app", 0, 0, SDL::WindowResizable, 250, 250);

  // Create a hardware accelerated renderer. Renderer as now root as parent.
  SDL::Renderer renderer(root, SDL::RenderAccelerated);
  
  SDL_Event event;

  do
  {
    SDL_PollEvent(&event);
  
    if (event.type == SDL_QUIT)
    {
       break;
    }
   
    // do stuff here
    
  } while(true);

  // Quit all subsystems
  SDL::quit();

  return 0;
}

~~~

## Others examples

