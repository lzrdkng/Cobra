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
 * File:   Rect.hpp
 * Author: olivier
 *
 * Created on August 12, 2017, 10:24 PM
 */

#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL_rect.h>

namespace SDL
{

class Rect {
    
    
public:

    static Rect fromSDL(const SDL_Rect& sdl_rect)
    {
        Rect rect(sdl_rect);

        return rect;
    }
    
    explicit Rect(Sint16 x=0,
                  Sint16 y=0,
                  Uint16 w=252,
                  Uint16 h=252);

    
    Rect(const Rect& orig);

    Rect(const SDL_Rect& orig);
    
    virtual ~Rect();
    
    Uint16 height() const;
    Uint16 width()  const;
    Sint16 x()      const;
    Sint16 y()      const;
    Rect& setHeight(Uint16 h);
    Rect& setWidth(Uint16 w);
    Rect& setX(Sint16 x);
    Rect& setY(Sint16 y);
    const SDL_Rect* toSDL() const;
    
    
private:
    
    SDL_Rect m_rect;

};

}

#endif /* RECTANGLE_HPP */

