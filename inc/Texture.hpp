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
 * File:   Texture.hpp
 * Author: olivier
 *
 * Created on August 13, 2017, 1:45 AM
 */

#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "SDL.hpp"

#include <string>
#include "Point.hpp"
#include "Color.hpp"
#include "Rect.hpp"

namespace SDL
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
    Texture& setColorMod(const SDL::Color& color);
    
    bool copyToRender(const Rect& src, const Rect& dst);
    /*bool copyToRenderEx(const CRect& src,
                        const CRect& dst,
                        const double angle,
                        const CPoint& center,
                        SDL::RendererFlip flip);*/

#ifdef _SDL_IMAGE_H
    bool loadFromFile(std::string path, int hexaRGB = -1);
#endif

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

