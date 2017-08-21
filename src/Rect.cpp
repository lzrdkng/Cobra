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

using namespace SDL;

// Constructor/destructor

Rect::Rect(Sint16 x, Sint16 y, Uint16 w, Uint16 h)
: m_rect {x, y, w ,h}
{
}

Rect::Rect(const Rect& orig) 
{
    m_rect.x = orig.x();
    m_rect.y = orig.y();
    m_rect.w = orig.width();
    m_rect.h = orig.height();
}

Rect::Rect(const SDL_Rect& orig)
{
    m_rect.x = orig.x;
    m_rect.y = orig.y;
    m_rect.w = orig.w;
    m_rect.h = orig.h;
}

Rect::~Rect()
{
}

Uint16 Rect::height() const
{
    return m_rect.h;
}

Uint16 Rect::width() const
{
    return m_rect.w;
}

Sint16 Rect::x() const
{
    return m_rect.x;
}

Sint16 Rect::y() const
{
    return m_rect.y;
}

Rect& Rect::setHeight(Uint16 h)
{
    m_rect.h = h;
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

const SDL_Rect* Rect::toSDL() const
{
    return &m_rect;
}
