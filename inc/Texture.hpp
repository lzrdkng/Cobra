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

#include <string>
#include "SDL.hpp"

#include "Pair.hpp"
#include "Point.hpp"
#include "Color.hpp"
#include "Rect.hpp"

namespace SDL
{

class Renderer;

class Texture {
public:
    
    explicit Texture(Renderer& renderer,
                     int width,
                     int height,
                     TextureAccess access=TextureAccessTarget,
                     PixelFormats format=PixelFormatUnknown);
    
    Texture(const Texture& orig)             = delete;
    Texture(Texture&& orig)                  = delete;
    Texture& operator =(const Texture& orig) = delete;
    Texture& operator =(Texture&& orig)      = delete;
    
    virtual ~Texture();
    
    TextureAccess getAccess() const;

    Uint8 getAlphaMod() const;

    BlendModes getBlendMode() const;

    Color getColorMod() const;

    PixelFormats getFormat() const;

    int getHeight() const;

    int getWidth() const;
    
    Texture& setAlphaMod(Uint8 alpha);

    /**
     * @brief Set the blend mode of the texture.
     * @param blendMode
     * @return SDL::Texture&
     * @throw SDL::Error on failure.
     */
    Texture& setBlendMode(BlendModes blendMode);


    Texture& setColorMod(const Color& color);

    bool copyToRender(const Renderer& renderer, const Rect& src, const Rect& dst);
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
    
    // Methods
    
    void free();
};

}

#endif /* TEXTURE_HPP */

