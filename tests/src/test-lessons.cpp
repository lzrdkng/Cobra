// std imports
#include <vector>
#include <iostream>

// catch import
#include "catch.hpp"
#include "config.hpp"

// lib imports
#include "SDL.hpp"
#include "Window.hpp"
#include "WindowSurface.hpp"
#include "Rect.hpp"
#include "Renderer.hpp"

extern const uint INTERACT; // Tutorials interactions MASK

TEST_CASE("Init subsystems")
{
  SDL::init(SDL::InitEverything);

#ifdef _SDL_IMAGE_H
  SDL::initImage(SDL::ImageInitPNG);
#endif
}

TEST_CASE("Creating a window", "[window, tutorial]")
{
  SDL::Window window("Creating a window [1]");

  SDL::WindowSurface screenSurface(window);

  screenSurface.fillRect(12000);

  window.update();
}

TEST_CASE("Getting an image on the screen", "[image, tutorial]")
{
  SDL::Window window("Getting an image on the screen [2]");

  SDL::WindowSurface screenSurface(window);

  SDL::Surface imageSurface("media/hello_world.bmp", &screenSurface);

  imageSurface.blit(screenSurface);

  window.update();
}

TEST_CASE("Event driven programming", "[event, tutorial")
{
  SDL::Window window("Event driven programming [3]");

  SDL::WindowSurface windowSurface(window);

  SDL::Surface imageSurface("media/x.bmp");

  SDL_Event event;

  // Main loop
  do
    {
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT)
        {
	  break;
        }
      else
        {
	  imageSurface.blit(windowSurface);
	  window.update();
        }
    } while (INTERACT & 1);
}

TEST_CASE("Key presses", "[key, tutorial")
{
  enum KeyPressSurfaces
  {
    KeyPressSurfaceDefault,
    KeyPressSurfaceUp,
    KeyPressSurfaceDown,
    KeyPressSurfaceLeft,
    KeyPressSurfaceRight,
    KeyPressSurfaceTotal
  };



  SDL::Window window("Key presses [4]");

  SDL::WindowSurface windowSurface(window);

  std::vector<SDL::Surface*> keyPressSurfaces =

    {
      new SDL::Surface("media/press.bmp"),
      new SDL::Surface("media/up.bmp"),
      new SDL::Surface("media/down.bmp"),
      new SDL::Surface("media/left.bmp"),
      new SDL::Surface("media/right.bmp")
    };

  SDL::Surface* currentSurface = keyPressSurfaces[KeyPressSurfaceDefault];

  SDL_Event event; 

  // Main Loop
  do
    {
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT)
        {
	  break;
        }
      else if (event.type == SDL_KEYDOWN) 
        {
	  switch (event.key.keysym.sym)
            {
	    case SDLK_UP:
	      currentSurface = keyPressSurfaces[KeyPressSurfaceUp];
	      break;
	    case SDLK_DOWN:
	      currentSurface = keyPressSurfaces[KeyPressSurfaceDown];
	      break;
	    case SDLK_LEFT:
	      currentSurface = keyPressSurfaces[KeyPressSurfaceLeft];
	      break;
	    case SDLK_RIGHT:
	      currentSurface = keyPressSurfaces[KeyPressSurfaceRight];
	      break;
	    default:
	      currentSurface = keyPressSurfaces[KeyPressSurfaceDefault];
            }
        }
      else
        {
	  currentSurface->blit(windowSurface);
	  window.update();
        }

    } while (INTERACT & 2);

  currentSurface = nullptr;

  for (auto it=keyPressSurfaces.begin(); it!=keyPressSurfaces.end(); ++it)
    {
      delete *it;
    }
  keyPressSurfaces.clear();
}

TEST_CASE("Optimized surface loading and soft stretching",
          "[surface, stretch, tutorial]")
{
  SDL::Window window("Optimized surface loading and soft stretching [5]");

  SDL::WindowSurface windowSurface(window);

  SDL::Surface stretchedSurface("media/stretch.bmp", &windowSurface);

  SDL::Rect stretchRect(0, 0, 640, 480);

  stretchedSurface.blitScaled(windowSurface, stretchRect);

  window.update();

  SDL_Event event;

  // Main Loop
  do
    {
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT)
        {
	  break;
        }

    }  while(INTERACT & 4);
}


#ifdef _SDL_IMAGE_H
TEST_CASE("Extension libraries and loading other image formats",
          "[SDL_image, lib, image, tutorial]")
{
  SDL::Window window("Extension libraries and loading other image formats "
		     "[6]");

  SDL::WindowSurface windowSurface(window);

  SDL::Surface pngSurface("media/loaded.png", &windowSurface);

  pngSurface.blit(windowSurface);

  window.update();
}

TEST_CASE("Texture Loading and Rendering", "[SDL_Texture, image, tutorial]")
{
  SDL::Window window("Texture Loading and Rendering [7]");

  SDL::Renderer render(window, SDL::RendererAccelerated);
  render.setDrawColor(SDL::Color {0, 0, 0});

  SDL::Texture loadedTexture(render, "media/texture.png");

  SDL_Event event;

  do
    {
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT)
        {
	  break;
        }


      render.clear();
      loadedTexture.copyToRender(render);
      render.present();

    } while (INTERACT & 8);
}
#endif

TEST_CASE("Geometry Rendering", "[Rect, Point, Line]")
{
  SDL::Window window("Geometry Rendering [8]");
  window.setResizable(true);

  SDL::Pair<int> size = window.getSize();

  SDL::Renderer render(window, SDL::RendererAccelerated);

  SDL_Event event;

  do
    {
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT)
        {
	  break;
        }
      else if (event.type == SDL_WINDOWEVENT)
	{
	  switch (event.window.event)
	    {
	    case SDL_WINDOWEVENT_RESIZED:
	    case SDL_WINDOWEVENT_SIZE_CHANGED:
	      size = window.getSize();
	      break;
	    default:
	      break;
	    }
	}

      render.setDrawColor(0);
      render.clear();

      render.setDrawColor({0xFF, 0, 0});
      render.fillRect({size.first / 4, size.second / 4,
	    size.first / 2, size.second / 2});

      render.setDrawColor({0, 0xFF, 0});
      render.drawRect({size.first / 6, size.second / 6,
	    2*size.first/3, 2*size.second/3 });

      render.setDrawColor({0, 0, 0xFF});
      render.drawLine({{0, size.second / 2},
	    {size.first, size.second / 2}});

      render.setDrawColor({0, 0xFF, 0xFF});
      render.drawCircle(size.first/2, size.second/2, 150);

      render.setDrawColor({0xFF, 0, 0xFF});
      render.fillCircle(size.first/2, size.second/2, 75);

      render.setDrawColor({0xFF, 0xFF, 0});
      for (auto i=0; i<size.first; i += 4)
        {
	  render.drawPoint({size.first/2, i});
        }

      render.present();

    } while(INTERACT & 16);
}

#ifdef _SDL_IMAGE_H
TEST_CASE("The Viewport", "[viewport]")
{
    SDL::setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    SDL::Window window("The Viewport [9]");
    window.setResizable(true);

    SDL::Pair<int> size = window.getSize();

    SDL::Renderer render(window, SDL::RendererAccelerated);

    SDL::Texture texture (render, "media/viewport.png");

    SDL_Event event;

    do
    {
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
	{
	  break;
        }

	size = window.getSize();

	render.setDrawColor(UINT32_MAX);
	render.clear();

	render.setViewport({0, 0, size.first / 2, size.second / 2});
	texture.copyToRender(render);

	render.setViewport({size.first / 2, 0, size.first / 2, size.second / 2});
	texture.copyToRender(render);

	render.setViewport({0, size.second/2, size.first, size.second/2});
	texture.copyToRender(render);

	render.present();


    } while (INTERACT & 32);
}
#endif

#ifdef _SDL_IMAGE_H
TEST_CASE("Color keying", "[Color]")
{
    SDL::setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    SDL::Window window("Color keying [10]");

    SDL::Renderer render(window, SDL::RenderAccelerated);

    SDL::Texture foo(render, "media/foo.png");

    SDL::Texture background(render, "media/background.png");

    SDL_Event event;

    do
    {
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
	    break;

	render.setDrawColor(UINT32_MAX);
	render.clear();

	background.copyToDist(render, {0, 0, background.getWidth(), background.getHeight()});
	foo.copyToDist(render, {240, 190, background.getWidth(), background.getHeight()});

	render.present();
	
    }  while (INTERACT & 64);
	
}
#endif


TEST_CASE("Quit all subsystem")
{
  SDL::quit();
}
