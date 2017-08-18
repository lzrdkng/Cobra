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
 * File:   Color.hpp
 * Author: olivier
 *
 * Created on August 12, 2017, 10:12 PM
 */

#ifndef COLOR_HPP
#define COLOR_HPP

#include <SDL2/SDL_pixels.h>

namespace Cobra
{

class Color {
public:
    
    Color(Uint8 r=0,
           Uint8 g=0,
           Uint8 b=0,
           Uint8 a=1);
    
    Color(const Color& orig);
    
    virtual ~Color();
    
    Uint8   getAlpha() const;
    Uint8   getBlue()  const;
    Uint8   getGreen() const;
    Uint8   getRed()   const;
    
    Color& setAlpha(Uint8 alpha);
    Color& setBlue(Uint8 blue);
    Color& setGreen(Uint8 blue);
    Color& setRed(Uint8 blue);
    
    const SDL_Color* toSDL() const;
    
private:
    
    SDL_Color m_color;
};

}

#endif /* COLOR_HPP */

