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
 * File:   Color.cpp
 * Author: olivier
 *
 * Created on August 28, 2017, 10:05 AM
 */

#include "Color.hpp"

using namespace SDL;


// static methods

Color Color::fromRGB(Uint8 r, Uint8 g, Uint8 b)
{
    return Color::fromRGBA(r, g, b, 255);
}

Color Color::fromRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    Color color(r, g, b, a);
    return color;
}


// operator methods

void Color::operator =(const Color& orig)
{
    setRed(orig.getRed());
    setGreen(orig.getGreen());
    setBlue(orig.getBlue());
    setAlpha(orig.getAlpha());
}

bool Color::operator ==(const Color& comp) const
{
    return ( getRed()   == comp.getRed()   &&
             getGreen() == comp.getGreen() &&
             getBlue()  == comp.getBlue()  &&
             getAlpha() == comp.getAlpha()
           );
}

bool Color::operator !=(const Color& comp) const
{
    return !(*this == comp);
}


// constructors/destructor

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) : m_color {r, g, b, a}
{

}

Color::Color(const Color &orig)
{
    setRed(orig.getRed());
    setGreen(orig.getGreen());
    setBlue(orig.getBlue());
    setAlpha(orig.getAlpha());
}

Color::~Color()
{

}


// get methods

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


// set methods

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

Color& Color::setRGB(Uint8 r, Uint8 g, Uint8 b)
{
    setRGBA(r, g, b, 255);
    return *this;
}

Color& Color::setRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    setRed(r).setGreen(g).setBlue(b).setAlpha(a);
    return *this;
}


// other methods

const SDL_Color* Color::toSDL() const
{
    return &m_color;
}


