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
 * File:   Rectangle.cpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 10:24 PM
 */

#include "Rect.hpp"

namespace SDL
{

// static methods

Rect Rect::fromInt(Sint16 x, Sint16 y, Uint16 w, Uint16 h)
{
    return Rect {x, y, w, h};
}

Rect Rect::fromPoints(const Point& a, const Point& b)
{
    return Rect {a, b};
}

Rect Rect::fromSDL(const SDL_Rect& sdl_rect)
{
    return Rect {sdl_rect};
}


// operator methods

Rect& Rect::operator =(const Rect& orig)
{
    setValues(orig.getX(), orig.getY(), orig.getWidth(), orig.getHeight());
    return *this;
}

bool Rect::operator ==(const Rect& comp) const
{
    return ( m_rect.x == comp.getX()     &&
             m_rect.y == comp.getY()     &&
             m_rect.w == comp.getWidth() &&
             m_rect.h == comp.getHeight()
            );
}

bool Rect::operator !=(const Rect& comp) const
{
    return !(*this == comp);
}


// Constructors/destructor

Rect::Rect()
: m_rect {0, 0, 0, 0}
{

}

Rect::Rect(const Rect& orig)
: m_rect {orig.getX(), orig.getY(), orig.getWidth(), orig.getHeight()}
{

}

Rect::Rect(const Point& a, const Point& b)
: m_rect {a.getX(), a.getY(), b.getX() - a.getX(), b.getY() - a.getY()}
{

}

Rect::Rect(const SDL_Rect& sdl_rect)
    : m_rect (sdl_rect)
{

}

Rect::~Rect()
{

}


// get methods

Uint16 Rect::getHeight() const
{
    return m_rect.h;
}

Uint16 Rect::getWidth() const
{
    return m_rect.w;
}

Sint16 Rect::getX() const
{
    return m_rect.x;
}

Sint16 Rect::getY() const
{
    return m_rect.y;
}


// set methods

Rect& Rect::setHeight(Uint16 h)
{
    m_rect.h = h;
    return *this;
}

Rect& Rect::setValues(Sint16 x, Sint16 y, Uint16 w, Uint16 h)
{
    setX(x).setY(y).setWidth(w).setHeight(h);
    return *this;
}

Rect& Rect::setWidth(Uint16 w)
{
    m_rect.w = w;
    return *this;
}

Rect& Rect::setX(Sint16 x)
{
    m_rect.x = x;
    return *this;
}

Rect& Rect::setY(Sint16 y)
{
    m_rect.y = y;
    return *this;
}


// other methods

const SDL_Rect* Rect::toSDL() const
{
    return &m_rect;
}

SDL_Rect* Rect::toSDL()
{
    return &m_rect;
}

}
