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
 * File:   Rect.hpp
 * Author: olivier
 *
 * Created on August 12, 2017, 10:24 PM
 */

#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL_rect.h>

namespace Cobra
{

class Rect {
    
    
public:
    
    static Rect fromSDL(const SDL_Rect& rect)
    {
        Rect newRect(rect.x, rect.y, rect.w, rect.h);
        return newRect;
    }
    
    Rect(Sint16 x=0,
               Sint16 y=0,
               Uint16 w=252,
               Uint16 h=252);
    
    Rect(const Rect& orig);
    
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

