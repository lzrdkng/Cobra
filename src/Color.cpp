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
 * File:   CColor.cpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 10:12 PM
 */

#include "Color.hpp"

using namespace Cobra;

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) 
: m_color {r, g, b, a}
{
}

Color::Color(const Color& orig) 
{
    setAlpha(orig.getAlpha());
    setBlue(orig.getBlue());
    setGreen(orig.getGreen());
    setRed(orig.getRed());
}

Color::~Color() 
{
}

Uint8 Color::getAlpha() const
{
    return m_color.a;
}

Uint8 Color::getBlue() const
{
    return m_color.b;
}

Uint8 Color::getGreen() const
{
    return m_color.g;
}

Uint8 Color::getRed() const
{
    return m_color.r;
}


Color& Color::setAlpha(Uint8 alpha) 
{
    m_color.a = alpha;
    return *this;
}

Color& Color::setBlue(Uint8 blue) 
{
    m_color.b = blue;
    return *this;
}

Color& Color::setGreen(Uint8 green) 
{
    m_color.g = green;
    return *this;
}

Color& Color::setRed(Uint8 red) 
{
    m_color.r = red;
    return *this;
}


const SDL_Color* Color::toSDL() const
{
    return &m_color;
}
