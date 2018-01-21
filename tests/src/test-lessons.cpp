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
#include "Event.hpp"

#define INTERACT 0

TEST_CASE("Init subsystems")
{
  SO::init(SO::Init::Everything);

  SO::setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

#ifdef  _SDL_IMAGE_H
  SO::initImage(SO::ImageInit::PNG | SO::ImageInit::JPG);
#endif
}

TEST_CASE("Creating a window", "[window, tutorial]")
{
  SO::Window window("Creating a window [1]");

  SO::WindowSurface screenSurface(window);

  screenSurface.fillRect(12000);

  window.update();
}

TEST_CASE("Getting an image on the screen", "[image, tutorial]")
{
  SO::Window window("Getting an image on the screen [2]");

  SO::WindowSurface screenSurface(window);

  SO::Surface imageSurface("media/hello_world.bmp", &screenSurface);

  imageSurface.blit(screenSurface);

  window.update();
}


TEST_CASE("Event driven programming", "[event, tutorial")
{
  SO::Window window("Event driven programming [3]");

  SO::WindowSurface windowSurface(window);

  SO::Surface imageSurface("media/x.bmp");

  SO::Event event;

  // Main loop
  do
  {
    SO::PollEvent(event);

    if (event.type == SDL_QUIT)
    {
      break;
    }
    else
    {
      imageSurface.blit(windowSurface);
      window.update();
    }
  } while (INTERACT & 4);
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



  SO::Window window("Key presses [4]");

  SO::WindowSurface windowSurface(window);

  std::vector<SO::Surface*> keyPressSurfaces = {new SO::Surface("media/press.bmp"),
						new SO::Surface("media/up.bmp"),
						new SO::Surface("media/down.bmp"),
						new SO::Surface("media/left.bmp"),
						new SO::Surface("media/right.bmp")};
  
  SO::Surface* currentSurface = keyPressSurfaces[KeyPressSurfaceDefault];

  SO::Event event;

  // Main Loop
  do
  {
    SO::PollEvent(event);

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

  } while (INTERACT & 8);

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
  SO::Window window("Optimized surface loading and soft stretching [5]");

  SO::WindowSurface windowSurface(window);

  SO::Surface stretchedSurface("media/stretch.bmp", &windowSurface);

  SO::Rect stretchRect(0, 0, 640, 480);

  stretchedSurface.blitScaled(windowSurface, stretchRect);

  window.update();

  SO::Event event;

  // Main Loop
  do
  {
    SO::PollEvent(event);

    if (event.type == SDL_QUIT)
    {
      break;
    }

  } while (INTERACT & 16);
}

#ifdef _SDL_IMAGE_H
TEST_CASE("Extension libraries and loading other image formats",
          "[SDL_image, lib, image, tutorial]")
{
  SO::Window window("Extension libraries and loading other image formats "
		    "[6]");

  SO::WindowSurface windowSurface(window);

  SO::Surface pngSurface("media/loaded.png", &windowSurface);

  pngSurface.blit(windowSurface);

  window.update();
}
#endif // _SDL_IMAGE_H

#ifdef _SDL_IMAGE_H
TEST_CASE("Texture Loading and Rendering", "[SDL_Texture, image, tutorial]")
{
  SO::Window window("Texture Loading and Rendering [7]");

  SO::Renderer render(window, SO::Renderer::Accelerated);
  render.setDrawColor(SO::Color {0, 0, 0});

  SO::Texture loadedTexture(render, "media/texture.png");

  SO::Event event;

  do
  {
    SO::PollEvent(event);

    if (event.type == SDL_QUIT)
    {
      break;
    }

    render.clear();
    loadedTexture.copy(render);
    render.present();

  } while (INTERACT & 64);
}
#endif // _SDL_IMAGE_H

TEST_CASE("Geometry Rendering", "[Rect, Point, Line]")
{
  SO::Window window("Geometry Rendering [8]", SO::Window::Resizable);

  SO::Pair<int> size = window.getSize();

  SO::Renderer render(window, SO::Renderer::Accelerated);

  SO::Event event;

  do
  {
    SO::PollEvent(event);

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

  } while (INTERACT & 128);
}

#ifdef _SDL_IMAGE_H
TEST_CASE("The Viewport", "[viewport]")
{
  SO::setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    
  SO::Window window("The Viewport [9]", SO::Window::Resizable);

  SO::Pair<int> size = window.getSize();

  SO::Renderer render(window, SO::Renderer::Accelerated);

  SO::Texture texture (render, "media/viewport.png");

  SO::Event event;

  do
  {
    SO::PollEvent(event);

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


  } while (INTERACT & 256);
}
#endif // _SDL_IMAGE_H

#ifdef _SDL_IMAGE_H
TEST_CASE("Color keying", "[Color]")
{
  SO::Window window("Color keying [10]");

  SO::Renderer render(window, SO::Renderer::Accelerated);

  SO::Texture foo(render, "media/foo.png", {0, 255, 255});

  SO::Texture background(render, "media/background.png", {0, 255, 255});

  SO::Event event;

  do
  {
    SO::PollEvent(event);

    if (event.type == SDL_QUIT)
      break;

    render.setDrawColor(UINT32_MAX);
    render.clear();

    background.copyToDst(render,
			 {0, 0, background.getWidth(), background.getHeight()});
    foo.copyToDst(render,
		  {240, 190, foo.getWidth(), foo.getHeight()});

    render.present();
	
  }  while (INTERACT & 512);
	
}
#endif // _SDL_IMAGE_H

#ifdef _SDL_IMAGE_H
TEST_CASE("Clip Rendering and Sprite Sheets", "[Sprite]")
{

  SO::Window window("Clip Rendering and Sprite Sheets [11]");

  SO::Pair<int> size = window.getSize();

  SO::Renderer render(window, SO::Renderer::Accelerated);

  SO::Texture spriteSheet(render, "media/dots.png");

  int width = spriteSheet.getWidth();
  int height = spriteSheet.getHeight();

  std::vector<SO::Rect> spriteClips ={{0, 0, 100, 100},
				      {100, 0, 100, 100},
				      {0, 100, 100, 100},
				      {100, 100, 100, 100}};

  SO::Event event;

  do
  {
    SO::PollEvent(event);

    if (event.type == SDL_QUIT)
      break;

    render.setDrawColor(UINT32_MAX);
    render.clear();

    spriteSheet.copyToRender(render,
			     {0, 0,width, height},
			     spriteClips[0]);
      
    spriteSheet.copyToRender(render,
			     {size.first - spriteClips[1].getWidth(), 0,width, height},
			     spriteClips[1]);
      
    spriteSheet.copyToRender(render,
			     {0, size.second - spriteClips[2].getHeight(), width, height},
			     spriteClips[2]);
      
    spriteSheet.copyToRender(render,
			     {size.first - spriteClips[3].getWidth(), size.second - spriteClips[3].getHeight(), width, height},
			     spriteClips[3]);
    render.present();
      
  } while (INTERACT & 1024);
    
  
}
#endif // _SDL_IMAGE_H




TEST_CASE("Quit all subsystem")
{
  SO::quit();
}
