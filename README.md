#  Cobra

### A **C++** wrapper around [SDL](https://www.libsdl.org/) cross-platform development library.


## Dependencies
**Cobra** is intend to work with all **SDL** major version. Which means that wether you
work with version 1.0.0 or the latest 2.0.5, it should works.
Other libraries such as [SDL_image](https://www.libsdl.org/projects/SDL_image/) work too.

## Build library
To **build** the shared library, simply type **make** in the project directory.

## Testings
 **Cobra** uses [Catch](https://github.com/philsquared/Catch) for its testing.

To **run** tests, simply type **make tests** in the project directory.

To **create** tests, you simply have to create a file named **test-*.cpp** under the directory **tests/src**. 
It's very important that your file start with **test-**. If you don't, the makefile won't include
your test in the dependencies.


## Documentation

**Cobra** uses [Doxygen](http://www.stack.nl/~dimitri/doxygen/) to generate documentation.

To make **Cobra** easier to use, every class wrapper use the (almost) same 
documentation provided by the SDL's [wiki](https://wiki.libsdl.org/).

Every other none wrapper class offered by **Cobra** follow the exact same documentation style.

## Namespace and constants

Every **class** and **enum** are in **SDL** namespace. This ensure there's
no name collision. 

Talking about name, **Cobra** uses the same name defined by  **SDL**.

*For examples:*

 **SDL_Window** -> **SDL::Window**
 
**SDL_GetWindowPosition** -> **SDL::Window::getPosition**

**SDL_Renderer** -> **SDL::Renderer**

**SDL_RenderSetScale** -> **SDL::Renderer::setScale**

Constants have also been re-written in **enum**.

*For examples:*

**SDL_INIT_VIDEO** -> **SDL::InitFlags::InitVideo**

**SDL_WINDOW_FULLSCREEN** -> **SDL::WindowFlags::WindowFullScreen**


## Parent tree

Every class, wrapper or not, derived from based class **Object**. 

Every **Object** instance :

- As zero or one parent
- As zero or more child
- Can not be its own parent
- Can not be parent of one of its ancestor
- Destroy its children when destroyed



## Usage

~~~C++

#include <Cobra/SDL.hpp>
#include <Cobra/Application.hpp>
#include <Cobra/Window.hpp>
#include <Cobra/Renderer.hpp>

int main()
{
  // Call to SDL_Init with flag SDL_INIT_VIDEO
  SDL::Application::init(SDL::InitVideo);
  
  // Create a resizable window at position (0,0) of size (250, 250)
  SDL::Window root("Usage testing", 0, 0, 250, 250, SDL::WindowResizable);

  // Create a hardware accelerated renderer. Renderer as now root as parent.
  SDL::Renderer* renderer = new SDL::Renderer(root, SDL::RenderAccelerated);

  // Main application loop
  SDL::Application::run(root);

  return 0;

} // Out of scope. Destruction of root result in destruction of its child renderer.

~~~

