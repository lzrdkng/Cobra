#include <vector>

#include "catch.hpp"

#include "SDL.hpp"

enum
{
  T_3  = 0x1,
  T_4  = 0x2,
  T_5  = 0x4,
  T_7  = 0x8,
  T_8  = 0x10,
  T_9  = 0x20,
  T_10 = 0x40,
  T_11 = 0x80,
  T_12 = 0x100,
  T_13 = 0x200,
  T_14 = 0x400,
  T_15 = 0x800,
  T_16 = 0x1000,
  T_17 = 0x2000
};

const uint INTERACT = T_17;

// BEGIN T_17
const int BUTTON_WIDTH  = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

enum ButtonSprite
{
  MouseOut = 0,
  MouseOverMotion = 1,
  MouseDown = 2,
  MouseUp = 3,
  Total = 4
};

typedef struct Button
{
  SO::Point pos;
    
  ButtonSprite currentSprite;
    
} Button;

void Button_HandleEvent(Button& button, const SO::Event& event)
{
  if (event.type == SDL_MOUSEMOTION ||
      event.type == SDL_MOUSEBUTTONDOWN ||
      event.type == SDL_MOUSEBUTTONUP)
  {
    int x, y;
    SDL_GetMouseState(&x, &y);

    bool inside = true;

    if (x < button.pos.getX() ||
	x > button.pos.getX() + BUTTON_WIDTH ||
	y < button.pos.getY() ||
	y > button.pos.getY() + BUTTON_HEIGHT)
      inside = false;

    if (!inside)
      button.currentSprite = MouseOut;
    else
    {
      switch (event.type)
      {
	case SDL_MOUSEMOTION:
	  button.currentSprite = MouseOverMotion;
	  break;
	case SDL_MOUSEBUTTONDOWN:
	  button.currentSprite = MouseDown;
	  break;
	case SDL_MOUSEBUTTONUP:
	  button.currentSprite = MouseUp;
	  break;
      }
    }      
  }
}
// END T_17

TEST_CASE("Init subsystems")
{
  SO::init(SO::Init::Everything);

  SO::setHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

#ifdef  _SDL_IMAGE_H
  SO::initImage(SO::ImageInit::PNG | SO::ImageInit::JPG);
#endif
  
#ifdef _SDL_TTF_H
  SO::initTTF();
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
  } while (INTERACT & T_3);
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

  std::vector<SO::Surface*> keyPressSurfaces =
    {
      new SO::Surface("media/press.bmp"),
      new SO::Surface("media/up.bmp"),
      new SO::Surface("media/down.bmp"),
      new SO::Surface("media/left.bmp"),
      new SO::Surface("media/right.bmp")
    };
  
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

  } while (INTERACT & T_4);

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

  } while (INTERACT & T_5);
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
  render.setDrawColor(SO::Color::Black);

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
    render.copy(loadedTexture, NULL, NULL);
    render.present();

  } while (INTERACT & T_7);
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

    render.setDrawColor(SO::Color::Black);
    render.clear();

    render.setDrawColor({0xFF, 0, 0});
    render.fillRect(
    {
      size.first / 4, size.second / 4,
      size.first / 2, size.second / 2
    });

    render.setDrawColor({0, 0xFF, 0});
    render.drawRect(
    {
      size.first / 6, size.second / 6,
      2*size.first/3, 2*size.second/3
    });

    render.setDrawColor({0, 0, 0xFF});
    render.drawLine(
    {
      {0, size.second / 2},
      {size.first, size.second / 2}
    });
      
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

  } while (INTERACT & T_8);
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

    render.setDrawColor(SO::Color::White);
    render.clear();

    render.setViewport({0, 0, size.first / 2, size.second / 2});
    render.copy(texture, NULL, NULL);

    render.setViewport({size.first / 2, 0, size.first / 2, size.second / 2});
    render.copy(texture, NULL, NULL);

    render.setViewport({0, size.second/2, size.first, size.second/2});
    render.copy(texture, NULL, NULL);

    render.present();


  } while (INTERACT & T_9);
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

  SO::Rect backgroundDst {0, 0, background.getWidth(), background.getHeight()};

  SO::Rect fooDst {240, 190, foo.getWidth(), foo.getHeight()};
  
  do
  {
    SO::PollEvent(event);

    if (event.type == SDL_QUIT)
      break;

    render.setDrawColor(SO::Color::White);
    render.clear();

    render.copy(background,
		NULL,
		&backgroundDst);
    render.copy(foo,
		NULL,
		&fooDst);

    render.present();
	
  }  while (INTERACT & T_10);
	
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
  
  std::vector<SO::Rect> src = {{0, 0, width, height},
			       {size.first - spriteClips[1].getWidth(), 0, width, height},
			       {0, size.second - spriteClips[2].getHeight(), width, height},
			       {size.first - spriteClips[3].getWidth(),
				size.second - spriteClips[3].getHeight(), width, height}};

  SO::Event event;

  do
  {
    SO::PollEvent(event);

    if (event.type == SDL_QUIT)
      break;

    render.setDrawColor(SO::Color::White);
    render.clear();

    render.copy(spriteSheet,
		&src[0],
		&spriteClips[0]);
      
    render.copy(spriteSheet,
		&src[1],
		&spriteClips[1]);
      
    render.copy(spriteSheet,
		&src[2],
		&spriteClips[2]);
      
    render.copy(spriteSheet,
		&src[3],
		&spriteClips[3]);
    render.present();
      
  } while (INTERACT & T_11);
    
  
}
#endif // _SDL_IMAGE_H

#ifdef _SDL_IMAGE_H
TEST_CASE("Color modulation", "")
{
  SO::Window window("Color modulation [12]");

  SO::Renderer render(window);

  SO::Texture modulatedTexture(render, "media/colors.png");

  SO::Event event;

  bool quit = false;

  Uint8 r = 255;
  Uint8 g = 255;
  Uint8 b = 255;

  do
  {
    while (SO::PollEvent(event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
	quit = true;
	break;
      }
      else if (event.type == SDL_KEYDOWN)
      {
	switch (event.key.keysym.sym)
	{
	  case SDLK_q:
	    r += 32;
	    break;
	  case SDLK_w:
	    g += 32;
	    break;
	  case SDLK_e:
	    b += 32;
	    break;
	  case SDLK_a:
	    r -= 32;
	    break;
	  case SDLK_s:
	    g -= 32;
	    break;
	  case SDLK_d:
	    b -=32;
	    break;
	  default:
	    break;
	}
      }
    } 

    render.setDrawColor(SO::Color::White);
    render.clear();

    modulatedTexture.setColorMod({r, g, b});
    render.copy(modulatedTexture, NULL, NULL);

    render.present();
  } while (!quit && INTERACT & T_12);
  
}
#endif // _SDL_IMAGE_H

#ifdef _SDL_IMAGE_H
TEST_CASE("Alpha blending")
{
  SO::Window window("Alpha blending [13]");

  SO::Renderer render(window, SO::Renderer::Accelerated);

  SO::Texture fadeOut(render, "media/fadeout.png", {0, 0xFF, 0xFF});

  SO::Texture fadeIn(render, "media/fadein.png", {0, 0xFF, 0xFF});

  SO::Event event;

  bool quit = false;

  Uint8 a = 255;

  do
  {
    while (SO::PollEvent(event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
	quit = true;
	break;
      }
      else if (event.type == SDL_KEYDOWN)
      {
	switch (event.key.keysym.sym)
	{
	  case SDLK_w:
	    if (a + 32 > 255)
	      a = 255;
	    else
	      a += 32;
	    break;
	  case SDLK_s:
	    if (a - 32 < 0)
	      a = 0;
	    else
	      a -= 32;
	    break;
	  default:
	    break;
	}
      }
    }

    render.setDrawColor(SO::Color::White);
    render.clear();

    render.copy(fadeIn, NULL, NULL);

    fadeOut.setAlphaMod(a);
    render.copy(fadeOut, NULL, NULL);

    render.present();
  } while (!quit && INTERACT & T_13);
}
#endif

#ifdef _SDL_IMAGE_H
TEST_CASE("Animated sprites and vsync")
{
  const int WALKING_ANIMATION_FRAMES = 6;
  const int WALKING_SHOOTING_ANIMATION_FRAMES = 6;

  SO::Window window("Animated sprites and vsync [14]");

  SO::Pair<int> size = window.getSize();

  SO::Renderer render(window, SO::Renderer::Accelerated|SO::Renderer::PresentVSync);

  SO::Texture* walkingSprites[WALKING_ANIMATION_FRAMES] =
    {
      new SO::Texture(render, "media/urban/6.png"),
      new SO::Texture(render, "media/urban/1.png"),
      new SO::Texture(render, "media/urban/2.png"),
      new SO::Texture(render, "media/urban/3.png"),
      new SO::Texture(render, "media/urban/4.png"),
      new SO::Texture(render, "media/urban/5.png")
    };
  
  SO::Texture* walkingShootingSprites[WALKING_SHOOTING_ANIMATION_FRAMES] =
    {
      new SO::Texture(render, "media/urban/6s.png"),
      new SO::Texture(render, "media/urban/1s.png"),
      new SO::Texture(render, "media/urban/2s.png"),
      new SO::Texture(render, "media/urban/3s.png"),
      new SO::Texture(render, "media/urban/4s.png"),
      new SO::Texture(render, "media/urban/5s.png")
    };
  
  SO::Event event;

  bool quit = false;

  int frame = 0;

  bool shooted = false;

  do
  {
    while (SO::PollEvent(event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
	quit = true;
	break;
      }
      else if (event.type == SDL_KEYDOWN)
      {
	switch (event.key.keysym.sym)
	{
	  case SDLK_SPACE:
	    shooted = true;
	    break;
	  default:
	    break;
	}
      }
    }

    render.setDrawColor(SO::Color::Black);
    render.clear();

    SO::Texture* currentFrame = nullptr;

    if (shooted)
      currentFrame = walkingShootingSprites[(frame + WALKING_SHOOTING_ANIMATION_FRAMES - 1) % 6];
    else
      currentFrame = walkingSprites[frame];

    ++frame;

    int width = currentFrame->getWidth();
    int height = currentFrame->getHeight();

    SO::Rect dst {(size.first - width) / 2, (size.second - height) / 2, width, height};

    render.copy(*currentFrame, NULL, &dst);
    
    render.present();

    frame %= WALKING_ANIMATION_FRAMES;

    shooted = false;

    SO::delay(120);
    
  } while (!quit && INTERACT & T_14);

  for (int i = 0; i < WALKING_ANIMATION_FRAMES; ++i) {
    delete walkingSprites[i];
  }
  
  for (int i = 0; i < WALKING_SHOOTING_ANIMATION_FRAMES; ++i) {
    delete walkingShootingSprites[i];
  }

}
#endif // _SDL_IMAGE_H

#ifdef _SDL_IMAGE_H
TEST_CASE("Rotation and Flipping")
{
  SO::Window window("Rotation and Flipping [15]");

  SO::Pair<int> size = window.getSize();

  SO::Renderer render(window);

  SO::Texture arrow(render, "media/arrow.png");

  bool quit = false;

  double degree = 0.0;

  SO::Event event;

  SO::Flip flip = SO::Flip::Null;

  SO::Rect dst {(size.first - arrow.getWidth()) / 2,
		(size.second - arrow.getHeight()) / 2,
		arrow.getWidth(), arrow.getHeight()};


  do
  {
    while (SO::PollEvent(event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
	quit = true;
	break;
      }
      else if (event.type == SDL_KEYDOWN)
      {
	switch (event.key.keysym.sym)
	{
	  case SDLK_a:
	    degree -=60;
	    break;
	  case SDLK_d:
	    degree += 60;
	    break;
	  case SDLK_q:
	    flip = SO::Flip::Horizontal;
	    break;
	  case SDLK_w:
	    flip = SO::Flip::Null;
	    break;
	  case SDLK_e:
	    flip = SO::Flip::Vertical;
	    break;
	}
      }
    }
  

    render.setDrawColor(SO::Color::White);
    render.clear();

    render.copyEx(arrow,
		  NULL,
		  &dst,
		  degree,
		  NULL,
		  flip);

    render.present();
  } while  (!quit && INTERACT & T_15);
}
#endif // _SDL_IMAGE_H

#ifdef _SDL_TTF_H
TEST_CASE("True type fonts", "[fonts]")
{
  SO::Window window("True type fonts [16]");

  SO::Pair<int> size = window.getSize();

  SO::Renderer render(window);

  TTF_Font* font = TTF_OpenFont("fonts/lazy.ttf", 28);

  SO::Texture textTexture(render, "The quick brown fox jumps over the lazy dog",
			  SO::Color::Black, font);
  bool quit = false;

  SO::Event event;

  SO::Rect dst {(size.first - textTexture.getWidth()) / 2,
		(size.second - textTexture.getHeight())/ 2,
		textTexture.getWidth(), textTexture.getHeight()};

  do
  {
    while (SO::PollEvent(event) != 0)
      if (event.type == SDL_QUIT)
      {
	quit = true;
	break;
      }

    render.setDrawColor(SO::Color::White);
    render.clear();

    render.copy(textTexture, NULL, &dst);

    render.present();
    
  } while (!quit && INTERACT & T_16);

  TTF_CloseFont(font);
  font = NULL;
}
#endif // _SDL_TTF_H

TEST_CASE("Mouse events", "[Mouse]")
{  
  SO::Window window("Mouse events [17]");

  SO::Pair<int> size = window.getSize();

  SO::Renderer render(window);

  SO::Texture buttonSpriteSheetTexture(render, "media/button.png", SO::Color::White);

  SO::Rect spriteClips[Total] = {{0, 0,   BUTTON_WIDTH, BUTTON_HEIGHT},
				 {0, 200, BUTTON_WIDTH, BUTTON_HEIGHT},
				 {0, 400, BUTTON_WIDTH, BUTTON_HEIGHT},
				 {0, 600, BUTTON_WIDTH, BUTTON_HEIGHT}};

  Button buttons[TOTAL_BUTTONS] = {{{0, 0},
				    MouseOut},
				   {{size.first - BUTTON_WIDTH, 0},
				    MouseOut},
				   {{0, size.second - BUTTON_HEIGHT},
				    MouseOut},
				   {{size.first - BUTTON_WIDTH, size.second - BUTTON_HEIGHT},
				    MouseOut}};

  bool quit = false;

  SO::Event event;

  SO::Rect dst;

  do
  {
    while (SO::PollEvent(event) != 0)
    {
      if (event.type == SDL_QUIT)
      {
	quit = true;
	break;
      }

      for (auto i = 0; i < TOTAL_BUTTONS; ++i)
      {
	Button_HandleEvent(buttons[i], event);
      }

    }

    render.setDrawColor(SO::Color::White);
    render.clear();

    for (auto i = 0; i < TOTAL_BUTTONS; ++i)
    {
      dst = spriteClips[buttons[i].currentSprite];
      dst.setX(buttons[i].pos.getX());
      dst.setY(buttons[i].pos.getY());
      
      render.copyEx(buttonSpriteSheetTexture, &spriteClips[buttons[i].currentSprite], &dst);
    }

    render.present();
    
  } while (!quit && INTERACT & T_17);	      		 
}

TEST_CASE("Quit all subsystem")
{
  SO::quit();
}
