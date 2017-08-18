/*
 * The MIT License
 *
 * Copyright 2017 olivier.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   CTexture.cpp
 * Author: olivier
 * 
 * Created on August 13, 2017, 1:45 AM
 */

#include "Texture.hpp"

using namespace Cobra;

// Public methods of class CTexture

/* Constructor/destructor */

Texture::Texture(SDL_Renderer* renderer,
                   int width,
                   int height,
                   int access,
                   Uint32 format)
: m_format(format), m_access(access), m_width(width), m_height(height)
{
    m_renderer = renderer;
    m_texture  = SDL_CreateTexture(renderer, format, access, width, height);
}

Texture::Texture(const Texture& orig) 
{
}

Texture::~Texture() 
{
    free();
    
    m_renderer = nullptr;
}

/* get methods */

int Texture::getAccess() const
{
    return m_access;
}


Uint8 Texture::getAlphaMod() const
{
    Uint8 alpha = 0;
    
    SDL_GetTextureAlphaMod(m_texture, &alpha);
    
    return alpha;
}

SDL_BlendMode Texture::getBlendMode() const
{
    SDL_BlendMode blendMode;
    
    SDL_GetTextureBlendMode(m_texture, &blendMode);
    
    return blendMode;
}

Color Texture::getColorMod() const
{
    Color color;
    
    Uint8 r,g,b;
    
    int code = SDL_GetTextureColorMod(m_texture, &r, &g, &b);
    
    if (code == 0)
    {
        color.setBlue(b);
        color.setGreen(g);
        color.setRed(r);
    }
    
    return color;   
}

Uint32 Texture::getFormat() const
{
    return m_format;
}


int Texture::getHeight() const 
{
    return m_height;
}


int Texture::getWidth() const 
{
    return m_width;
}


/* set methods */

Texture& Texture::setAlphaMod(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(m_texture, alpha);
    return *this;
}

Texture& Texture::setBlendMode(SDL_BlendMode blendMode)
{
    SDL_SetTextureBlendMode(m_texture, blendMode);
    return *this;
}

Texture& Texture::setColorMod(const Color& color)
{
    SDL_SetTextureColorMod(m_texture,
                           color.getRed(),
                           color.getGreen(),
                           color.getBlue());
    return *this;
}

/* other methods */

bool Texture::copyToRender(const Rect& source, const Rect& destination)
{
    return SDL_RenderCopy(
                          m_renderer,
                          m_texture,
                          source.toSDL(),
                          destination.toSDL()
                         ) == 0 ? true:false;
}

/*
bool CTexture::copyToRenderEx(const CRect& src,
                              const CRect& dst,
                              const double angle,
                              const CPoint& center,
                              Cobra::RendererFlip flip) 
{
    return SDL_RenderCopyEx(m_renderer,
                            m_texture,
                            src.toSDL(),
                            dst.toSDL(),
                            angle,
                            center.toSDL(),
                            flip) == 0 ? true:false;
}*/


bool Texture::loadFromFile(std::string path, int hexaRGB)
{
    
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    
    if (loadedSurface == nullptr)
    {
        // exception
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
        
        m_texture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
        
        if (m_texture == nullptr)
        {
            //exception
        }
        else
        {
            m_width  = loadedSurface->w;
            m_height = loadedSurface->h;
        }
    }
    
    SDL_FreeSurface(loadedSurface);
    
    return m_texture != nullptr;
    
}

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
    
    m_width  = 0;
    m_height = 0;
}