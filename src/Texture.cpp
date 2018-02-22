/*
 *  Cobra -- SDL2 C++ Wrapper
 * 
 *  Copyright (C) 2017 Olivier Dion <olivier-dion@hotmail.com>
 * 
 *  This software is provided 'as-is', without any express or implied
 *  warranty.  In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 * 
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 * 
 *  1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *  2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *  3. This notice may not be removed or altered from any source distribution.
 */

/* 
 * File:   Texture.cpp
 * Author: olivier
 * 
 * Created on August 13, 2017, 1:45 AM
 */

#include "Texture.hpp"
#include "Renderer.hpp"

namespace SO
{

  // Public methods of class CTexture

  /* Constructor/destructor */

  Texture::Texture(Renderer& renderer,
		   int width,
		   int height,
		   TextureAccess access,
		   PixelFormats format)

    : m_texture(nullptr)
  {
    m_texture = SDL_CreateTexture(renderer.toSDL(),
                                  static_cast<Uint32>(format),
                                  static_cast<Uint32>(access),
                                  width, height);

    if (m_texture == nullptr)
      throw Error(SDL_GetError());
  }
  
#ifdef _SDL_IMAGE_H
  Texture::Texture(Renderer& renderer,
		   const char* file,
		   const Color& colorKeying)
    : m_texture(nullptr)
  {
    this->loadFromFile(renderer, file, colorKeying);
  }
#endif

#ifdef _SDL_TTF_H
  Texture::Texture(Renderer& renderer,
		   const char* text,
		   const Color& textColor,
		   TTF_Font* font)
    : m_texture(nullptr)
  {
    this->loadFromRenderedText(renderer, text, textColor, font);
  }
#endif
  
  Texture::~Texture() 
  {
    free();
  }

  /* get methods */

  TextureAccess Texture::getAccess() const
  {
    int access;

    if (SDL_QueryTexture(m_texture, NULL, &access, NULL, NULL) != 0)
      throw Error(SDL_GetError());
    return static_cast<TextureAccess>(access);
  }


  Uint8 Texture::getAlphaMod() const
  {
    Uint8 alpha = 0;
    
    SDL_GetTextureAlphaMod(m_texture, &alpha);
    
    return alpha;
  }

  BlendModes Texture::getBlendMode() const
  {
    SDL_BlendMode blendMode = SDL_BLENDMODE_NONE;
    
    if (SDL_GetTextureBlendMode(m_texture, &blendMode) != 0)
      throw Error(SDL_GetError());

    return static_cast<BlendModes>(blendMode);
  }

  Color Texture::getColorMod() const
  { 
    Uint8 r,g,b;
    
    if (SDL_GetTextureColorMod(m_texture, &r, &g, &b) != 0)
      throw Error(SDL_GetError());
    
    return Color::fromRGB(r, g ,b);
  }


  PixelFormats Texture::getFormat() const
  {
    Uint32 format = 0;

    if (SDL_QueryTexture(m_texture, &format, NULL, NULL, NULL) != 0)
      throw Error(SDL_GetError());

    return static_cast<PixelFormats>(format);
  }


  int Texture::getHeight() const 
  {
    int height = 0;

    if (SDL_QueryTexture(m_texture, NULL, NULL, NULL, &height) != 0)
      throw Error(SDL_GetError());

    return height;
  }


  int Texture::getWidth() const 
  {
    int width = 0;

    if (SDL_QueryTexture(m_texture, NULL, NULL, &width, NULL) != 0)
      throw Error(SDL_GetError());

    return width;
  }


  /* set methods */

  Texture& Texture::setAlphaMod(Uint8 alpha)
  {
    SDL_SetTextureAlphaMod(m_texture, alpha);
    return *this;
  }

  Texture& Texture::setBlendMode(BlendModes blendMode)
  {
    SDL_SetTextureBlendMode(m_texture, static_cast<SDL_BlendMode>(blendMode));
    return *this;
  }

  Texture& Texture::setColorMod(const Color& color)
  {
    if (SDL_SetTextureColorMod(m_texture, color.getRed(), color.getGreen(), color.getBlue()) != 0)
      throw Error(SDL_GetError());

    return *this;
  }

  /* other methods */


#ifdef _SDL_IMAGE_H
  Texture& Texture::loadFromFile(Renderer& renderer,
				 const char* file,
				 const Color& colorKeying)
  {

    SDL_Surface* loadedSurface = IMG_Load(file);

    if (loadedSurface == nullptr)
    {
      throw Error(IMG_GetError());
    }
    else
    {
      this->free();

      if (colorKeying != Color {0, 0, 0, 0})
	SDL_SetColorKey(loadedSurface,
			SDL_TRUE,
			SDL_MapRGB(loadedSurface->format,
				   colorKeying.getRed(),
				   colorKeying.getGreen(), 
				   colorKeying.getBlue()));

      m_texture = SDL_CreateTextureFromSurface(renderer.toSDL(),
					       loadedSurface);
      SDL_FreeSurface(loadedSurface);

      if (m_texture == nullptr)
      {
	throw Error(SDL_GetError());
      }
    }

    return *this;
  }
#endif

#ifdef _SDL_TTF_H
  Texture& Texture::loadFromRenderedText(Renderer& render,
					 const char* text,
					 const Color& textColor,
					 TTF_Font* font)
  {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, *((SDL_Color*)&textColor));

    if (textSurface == nullptr)
    {
      throw Error(TTF_GetError());
    }
    else
    {
      this->free();

      m_texture = SDL_CreateTextureFromSurface(render.toSDL(), textSurface);
      
      SDL_FreeSurface(textSurface);

      if (m_texture == nullptr)
      {
	throw Error(SDL_GetError());
      }      
    }

    return *this;
  }
#endif

  const SDL_Texture* Texture::toSDL() const
  {
    return m_texture;
  }

  SDL_Texture* Texture::toSDL()
  {
    return m_texture;
  }

  // Private methods of class CTexture

  void Texture::free()
  {
    if (m_texture != nullptr)
    {
      SDL_DestroyTexture(m_texture);
      m_texture = nullptr;
    }
  }

}
