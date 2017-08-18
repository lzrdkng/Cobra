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
 * File:   CRectangle.cpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 10:24 PM
 */

#include "Rect.hpp"

using namespace Cobra;

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