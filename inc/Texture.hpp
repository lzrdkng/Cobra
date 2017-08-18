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
 * File:   Texture.hpp
 * Author: olivier
 *
 * Created on August 13, 2017, 1:45 AM
 */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "Point.hpp"
#include "Color.hpp"
#include "Rect.hpp"

namespace Cobra
{

class Texture {
public:
    
    explicit Texture(SDL_Renderer* renderer,
                      int width,
                      int height,
                      int access=SDL_TEXTUREACCESS_TARGET,
                      Uint32 format=SDL_PIXELFORMAT_UNKNOWN);
    
    Texture(const Texture& orig);
    
    virtual ~Texture();
    
    int           getAccess()    const;
    Uint8         getAlphaMod()  const;
    SDL_BlendMode getBlendMode() const;
    Color         getColorMod()  const;
    Uint32        getFormat()    const;
    int           getHeight()    const;
    int           getWidth()     const;
    
    Texture& setAlphaMod(Uint8 alpha);
    Texture& setBlendMode(SDL_BlendMode blendMode);
    Texture& setColorMod(const Cobra::Color& color);
    
    bool copyToRender(const Rect& src, const Rect& dst);
    /*bool copyToRenderEx(const CRect& src,
                        const CRect& dst,
                        const double angle,
                        const CPoint& center,
                        Cobra::RendererFlip flip);*/
    bool loadFromFile(std::string path, int hexaRGB = -1);
    //bool lock(const CRectangle& rect, void** pixels, int* pitch);
    const SDL_Texture* toSDL() const;
    //bool unlock();
    
    
    
private:
    
    // Members
    
    SDL_Texture*  m_texture;
    SDL_Renderer* m_renderer;

    Uint32 m_format;
    int m_access;
    int m_width;
    int m_height;
    
    // Methods
    
    void free();
};

}

#endif /* TEXTURE_HPP */

