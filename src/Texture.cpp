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

namespace SDL
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
    m_texture = SDL_CreateTexture(renderer.toSDL(), format, access, width, height);

    if (m_texture == nullptr)
        throw Error(SDL_GetError());
}

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

bool Texture::copyToRender(Renderer& renderer, const Rect& source, const Rect& destination)
{
    return SDL_RenderCopy(
                          renderer.toSDL(),
                          m_texture,
                          source.toSDL(),
                          destination.toSDL()
                         ) == 0;
}

/*
bool CTexture::copyToRenderEx(const CRect& src,
                              const CRect& dst,
                              const double angle,
                              const CPoint& center,
                              SDL::RendererFlip flip) 
{
    return SDL_RenderCopyEx(m_renderer,
                            m_texture,
                            src.toSDL(),
                            dst.toSDL(),
                            angle,
                            center.toSDL(),
                            flip) == 0 ? true:false;
}*/


#ifdef _SDL_IMAGE_H
bool Texture::loadFromFile(std::string path, Renderer& renderer, int hexaRGB)
{
    
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    
    if (loadedSurface == nullptr)
    {
        throw Error(IMG_GetError());
    }
    else
    {
        this->free();
        
        if (hexaRGB > 0)
            SDL_SetColorKey(
                            loadedSurface,
                            SDL_TRUE,
                            SDL_MapRGB(
                                       loadedSurface->format,
                                       (hexaRGB >> 16)&255,
                                       (hexaRGB >>  8)&255,
                                       (hexaRGB      )&255
                                      )
                            );
        
        m_texture = SDL_CreateTextureFromSurface(renderer.toSDL(), loadedSurface);
        
        if (m_texture == nullptr)
        {
            throw Error(SDL_GetError());
        }
    }
    
    SDL_FreeSurface(loadedSurface);
    
    return m_texture != nullptr;
    
}
#endif

const SDL_Texture* Texture::toSDL() const
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
