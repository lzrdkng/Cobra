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
 * File:   Color.hpp
 * Author: olivier
 *
 * Created on August 12, 2017, 10:12 PM
 */

#ifndef COLOR_HPP
#define COLOR_HPP

#include <SDL2/SDL_pixels.h>

namespace SDL
{

/**
 * @brief Wrapper class for **SDL_Color**
 */

class Color {
public:
    
    /**
     * @brief static method to create Color object from rgba.
     * @param r Red component in range 0-255.
     * @param g Green component in range 0-255.
     * @param b Blue component in range 0-255.
     * @param a Alpha component in range 0-255.
     * @return Color
     */
    static Color fromRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        Color color(r, g, b, a);
        return color;
    }


    /**
     * @brief static method to create Color object from rgb.
     * @param r Red component in range 0-255.
     * @param g Green component in range 0-255.
     * @param b Blue component in range 0-255.
     * @return Color
     */
    static Color fromRGB(Uint8 r, Uint8 g, Uint8 b)
    {
        return Color::fromRGBA(r, g, b, 255);
    }


    /**
     * @brief Assign Color operator.
     * @param orig The Color assign.
     */
    void operator =(const Color& orig)
    {
        this->setRed(orig.getRed());
        this->setGreen(orig.getGreen());
        this->setBlue(orig.getBlue());
        this->setAlpha(orig.getAlpha());
    }


    bool operator ==(const Color& comp)
    {
        return ( this->getRed()   == comp.getRed()   &&
                 this->getGreen() == comp.getGreen() &&
                 this->getBlue()  == comp.getBlue()  &&
                 this->getAlpha() == comp.getAlpha()
               );
    }

    bool operator !=(const Color& comp)
    {
        return !(*this == comp);
    }

    /**
     * @brief Explicit constructor of class Color.
     * @param r Red component in range 0-255.
     * @param g Green component in range 0-255.
     * @param b Blue component in range 0-255.
     * @param a Alpha component in range 0-255.
     * @note The compiler will truncate value over 255.
     */
    explicit Color(Uint8 r=0,
                   Uint8 g=0,
                   Uint8 b=0,
                   Uint8 a=255) : m_color {r, g, b, a} {}


    /**
     * @brief Copy constructor of class Color.
     * @param orig The orignal color.
     */
    Color(const Color& orig)
    {
        this->setRed(orig.getRed());
        this->setGreen(orig.getGreen());
        this->setBlue(orig.getBlue());
        this->setAlpha(orig.getAlpha());
    }
    

    /**
     * @brief Destructor of class Color.
     */
    virtual ~Color() {}
    

    /**
     * @brief Return the Color's alpha component.
     * @return Uint8
     */
    Uint8 getAlpha() const { return m_color.a; }

    /**
     * @brief Return the Color's blue component.
     * @return Uint8
     */
    Uint8 getBlue()  const { return m_color.b; }


    /**
     * @brief Return the Color's green component.
     * @return Uint8
     */
    Uint8 getGreen() const { return m_color.g; }


    /**
     * @brief Return the Color's red component.
     * @return Uint8
     */
    Uint8 getRed()   const { return m_color.r; }
    

    /**
     * @brief Set the Color's alpha component.
     * @param alpha The alpha component in range 0-255.
     * @return SDL::Color&
     */
    Color& setAlpha(Uint8 alpha) { m_color.a = alpha; return *this; }


    /**
     * @brief Set the Color's blue component.
     * @param blue The blue component in range 0-255.
     * @return SDL::Color&
     */
    Color& setBlue(Uint8 blue) { m_color.b = blue; return *this; }


    /**
     * @brief Set the Color's green component.
     * @param red The green component in range 0-255.
     * @return SDL::Color&
     */
    Color& setGreen(Uint8 green) { m_color.g = green; return *this; }


    /**
     * @brief Set the Color's red component.
     * @param red The red component in range 0-255.
     * @return SDL::Color&
     */
    Color& setRed(Uint8 red) { m_color.r = red; return *this; }
    

    /**
     * @brief Return the wrapped object.
     * @return const SDL_Color*
     * @warning Use with caution
     */
    const SDL_Color* toSDL() const;
    
private:
    
    SDL_Color m_color;
};

}

#endif /* COLOR_HPP */
