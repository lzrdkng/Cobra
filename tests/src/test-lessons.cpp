// std imports
#include <vector>
#include <iostream>

// catch import
#include "catch.hpp"

// lib imports
#include "SDL.hpp"
#include "Window.hpp"
#include "WindowSurface.hpp"
#include "Rect.hpp"
#include "Renderer.hpp"

#define INTERACT 1024

TEST_CASE("Init subsystems")
{
  SDLO::init(SDLO::InitEverything);

  SDLO::setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

#ifdef  SDL_IMAGE_H_
  SDLO::initImage(SDLO::ImageInitPNG);
#endif
}

#if INTERACT & 1
TEST_CASE("Creating a window", "[window, tutorial]")
{
  SDLO::Window window("Creating a window [1]");

  SDLO::WindowSurface screenSurface(window);

  screenSurface.fillRect(12000);

  window.update();
}
#endif

#if INTERACT & 2
TEST_CASE("Getting an image on the screen", "[image, tutorial]")
{
  SDLO::Window window("Getting an image on the screen [2]");

  SDLO::WindowSurface screenSurface(window);

  SDLO::Surface imageSurface("media/hello_world.bmp", &screenSurface);

  imageSurface.blit(screenSurface);

  window.update();
}
#endif

#if INTERACT & 4
TEST_CASE("Event driven programming", "[event, tutorial")
{
  SDLO::Window window("Event driven programming [3]");

  SDLO::WindowSurface windowSurface(window);

  SDLO::Surface imageSurface("media/x.bmp");

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
    } while (true);
}
#endif

#if INTERACT & 8
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



  SDLO::Window window("Key presses [4]");

  SDLO::WindowSurface windowSurface(window);

  std::vector<SDLO::Surface*> keyPressSurfaces =

    {
      new SDLO::Surface("media/press.bmp"),
      new SDLO::Surface("media/up.bmp"),
      new SDLO::Surface("media/down.bmp"),
      new SDLO::Surface("media/left.bmp"),
      new SDLO::Surface("media/right.bmp")
    };

  SDLO::Surface* currentSurface = keyPressSurfaces[KeyPressSurfaceDefault];

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

    } while (true);

  currentSurface = nullptr;

  for (auto it=keyPressSurfaces.begin(); it!=keyPressSurfaces.end(); ++it)
    {
      delete *it;
    }
  keyPressSurfaces.clear();
}
#endif

#if INTERACT & 16
TEST_CASE("Optimized surface loading and soft stretching",
          "[surface, stretch, tutorial]")
{
  SDLO::Window window("Optimized surface loading and soft stretching [5]");

  SDLO::WindowSurface windowSurface(window);

  SDLO::Surface stretchedSurface("media/stretch.bmp", &windowSurface);

  SDLO::Rect stretchRect(0, 0, 640, 480);

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

    } while (true);
}
#endif

#ifdef SDL_IMAGE_H_
#if INTERACT & 32 
TEST_CASE("Extension libraries and loading other image formats",
          "[SDL_image, lib, image, tutorial]")
{
  SDLO::Window window("Extension libraries and loading other image formats "
		     "[6]");

  SDLO::WindowSurface windowSurface(window);

  SDLO::Surface pngSurface("media/loaded.png", &windowSurface);

  pngSurface.blit(windowSurface);

  window.update();
}
#endif
#endif

#ifdef SDL_IMAGE_H_
#if INTERACT & 64
TEST_CASE("Texture Loading and Rendering", "[SDL_Texture, image, tutorial]")
{
  SDLO::Window window("Texture Loading and Rendering [7]");

  SDLO::Renderer render(window, SDLO::RendererAccelerated);
  render.setDrawColor(SDLO::Color {0, 0, 0});

  SDLO::Texture loadedTexture(render, "media/texture.png");

  SDL_Event event;

  do
    {
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT)
        {
	  break;
        }


      render.clear();
      loadedTexture.copy(render);
      render.present();

    } while (true);
}
#endif
#endif

#if INTERACT & 128
TEST_CASE("Geometry Rendering", "[Rect, Point, Line]")
{
  SDLO::Window window("Geometry Rendering [8]");
  window.setResizable(true);

  SDLO::Pair<int> size = window.getSize();

  SDLO::Renderer render(window, SDLO::RendererAccelerated);

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

    } while (true);
}y
#endif

#ifdef SDL_IMAGE_H_
#if INTERACT & 256
TEST_CASE("The Viewport", "[viewport]")
{
    SDLO::setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
    SDLO::Window window("The Viewport [9]");
    window.setResizable(true);

    SDLO::Pair<int> size = window.getSize();

    SDLO::Renderer render(window, SDLO::RendererAccelerated);

    SDLO::Texture texture (render, "media/viewport.png");

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
	texture.copy(render);

	render.setViewport({size.first / 2, 0, size.first / 2, size.second / 2});
	texture.copy(render);

	render.setViewport({0, size.second/2, size.first, size.second/2});
	texture.copy(render);

	render.present();


    } while (true);
}
#endif
#endif

#ifdef SDL_IMAGE_H_
#if INTERACT & 512
TEST_CASE("Color keying", "[Color]")
{
    SDLO::Window window("Color keying [10]");

    SDLO::Renderer render(window, SDLO::RendererAccelerated);

    SDLO::Texture foo(render, "media/foo.png", {0, 255, 255});

    SDLO::Texture background(render, "media/background.png", {0, 255, 255});

    SDL_Event event;

    do
    {
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
	    break;

	render.setDrawColor(UINT32_MAX);
	render.clear();

	background.copyToDst(render, {0, 0, background.getWidth(), background.getHeight()});
	foo.copyToDst(render, {240, 190, foo.getWidth(), foo.getHeight()});

	render.present();
	
    }  while (true);
	
}
#endif
#endif

#ifdef SDL_IMAGE_H_
#if INTERACT & 1024 
TEST_CASE("Clip Rendering and Sprite Sheets", "[Sprite]")
{

  SDLO::Window window("Clip Rendering and Sprite Sheets [11]");

  SDLO::Pair<int> size = window.getSize();

  SDLO::Renderer render(window, SDLO::RendererAccelerated);

  SDLO::Texture spriteSheet(render, "media/dots.png");

  int width = spriteSheet.getWidth();
  int height = spriteSheet.getHeight();

  std::vector<SDLO::Rect> spriteClips =
    {
      {0, 0, 100, 100},
      {100, 0, 100, 100},
      {0, 100, 100, 100},
      {100, 100, 100, 100}
    };

  SDL_Event event;

  do
    {
      SDL_PollEvent(&event);

      if (event.type == SDL_QUIT)
	break;

      render.setDrawColor(UINT32_MAX);
      render.clear();

      spriteSheet.copyToRender(render, {0, 0, width, height}, spriteClips[0]);
      spriteSheet.copyToRender(render, {size.first - spriteClips[1].getWidth(), 0, width, height}, spriteClips[1]);
      spriteSheet.copyToRender(render, {0, size.second - spriteClips[2].getHeight(), width, height}, spriteClips[2]);
      spriteSheet.copyToRender(render, {size.first - spriteClips[3].getWidth(), size.second - spriteClips[3].getHeight(), width, height}, spriteClips[3]);
      render.present();
      
    } while (true);
    
  
}
#endif
#endif


TEST_CASE("Quit all subsystem")
{
  SDLO::quit();
}
