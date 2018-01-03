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

namespace SO
{

  /**
   * @brief Wrapper class for **SDL_Color**
   */

  class Color : SDL_Color
  {
  public:

    static Color getRGB(Uint32 color, SDL_PixelFormat* format)
    {
      Uint8 r = 0, g = 0, b = 0;

      SDL_GetRGB(color, format, &r, &g, &b);

      return {r, g, b};
    }


    static const Color White;
    static const Color Black;
    static const Color Gray;


    // static methods

    /**
     * @brief static method to create Color object from rgb.
     * @param r Red component in range 0-255.
     * @param g Green component in range 0-255.
     * @param b Blue component in range 0-255.
     * @return SDL::Color
     */
    constexpr static Color fromRGB(Uint8 r, Uint8 g, Uint8 b)
    {
      return {r, g, b};
    }
      
  

    constexpr static Color fromHexa(uint code)
    {
      return {code};
    }

    /**
     * @brief static method to create Color object from rgba.
     * @param r Red component in range 0-255.
     * @param g Green component in range 0-255.
     * @param b Blue component in range 0-255.
     * @param a Alpha component in range 0-255.
     * @return Color
     */
    constexpr static Color fromRGBA(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
      return {r, g, b, a};
    }

    // operator methods

    /**
     * @brief Assign Color operator.
     * @param orig The Color assign.
     */
    constexpr Color&  operator =(const Color& orig)
    {
      r = orig.r;
      g = orig.g;
      b = orig.g;
      a = orig.a;
      return *this;
    }

    /**
     * @brief operator ==
     * @param comp
     * @return bool
     */
    constexpr bool operator ==(const Color& comp) const
    {
      return (r == comp.r) && (g == comp.g) && (b == comp.b) && (a == comp.a);
    }

    /**
     * @brief operator !=
     * @param comp
     * @return bool
     */
    constexpr bool operator !=(const Color& comp) const {return !(*this==comp);}


    // constructors/destructor

    constexpr Color() : SDL_Color {0, 0, 0, 0xFF} {}

    constexpr Color(uint x)
    : SDL_Color
    {static_cast<Uint8>(x >> 24),
	static_cast<Uint8>(x >> 16 & 255),
	static_cast<Uint8>(x >> 8 & 255),
	static_cast<Uint8>(x & 255)} {}

    constexpr Color(Uint8 R, Uint8 G, Uint8 B) : SDL_Color {R, G, B, 0xFF} {}

    /**
     * @brief Explicit constructor of class Color.
     * @param r Red component in range 0-255.
     * @param g Green component in range 0-255.
     * @param b Blue component in range 0-255.
     * @param a Alpha component in range 0-255.
     * @note The compiler will truncate value over 255.
     */
    constexpr Color(Uint8 R, Uint8 G, Uint8 B, Uint8 A)
    : SDL_Color {R, G, B, A} {}

    /**
     * @brief Copy constructor of class Color.
     * @param orig The orignal color.
     */
    constexpr Color(const Color& orig)
    : SDL_Color {orig.r, orig.g, orig.b, orig.a} {}

    // get methods

    /**
     * @brief Return the Color's alpha component.
     * @return Uint8
     */
    constexpr Uint8 getAlpha() const { return a; }

    /**
     * @brief Return the Color's blue component.
     * @return Uint8
     */
    constexpr Uint8 getBlue() const { return b; }


    /**
     * @brief Return the Color's green component.
     * @return Uint8
     */
    constexpr Uint8 getGreen() const { return g; }

    /**
     * @brief Return the Color's red component.
     * @return Uint8
     */
    constexpr Uint8 getRed() const { return r; }
    

    // set methods

    /**
     * @brief Set the Color's alpha component.
     * @param alpha The alpha component in range 0-255.
     * @return SDL::Color&
     */
    Color& setAlpha(Uint8 alpha)
    {
      a = alpha;
      return *this;
    }

    /**
     * @brief Set the Color's blue component.
     * @param blue The blue component in range 0-255.
     * @return SDL::Color&
     */
    Color& setBlue(Uint8 blue)
    {
      b = blue;
      return *this;
    }

    /**
     * @brief Set the Color's green component.
     * @param red The green component in range 0-255.
     * @return SDL::Color&
     */
    Color& setGreen(Uint8 green)
    {
      g = green;
      return *this;
    }

    /**
     * @brief Set the Color's red component.
     * @param red The red component in range 0-255.
     * @return SDL::Color&
     */
    Color& setRed(Uint8 red)
    {
      r = red;
      return *this;
    }
    
    /**
     * @brief Set the Color's red, green, blue components.
     * @param r
     * @param g
     * @param b
     * @return SDL::Color&
     */
    Color& setRGB(Uint8 R, Uint8 G, Uint8 B)
    {
      r = R;
      g = G;
      b = B;
      return *this;
    }

    /**
     * @brief Set the Color's red, green, blue, alpha components.
     * @param r
     * @param g
     * @param b
     * @param a
     * @return SDL::Color&
     */
    Color& setRGBA(Uint8 R, Uint8 G, Uint8 B, Uint8 A)
    {
      r = R;
      g = G;
      b = B;
      a = A;
      return *this;
    }

    /**
     * @brief Set the Color's red, green, blue, alpha components.
     * @param value
     * @return SDL::Color&
     */
    Color& setRGBA(uint value)
    {
      r = static_cast<Uint8>(value >> 24);
      g = static_cast<Uint8>(value >> 16 & 255);
      b = static_cast<Uint8>(value >> 8 & 255);
      a = static_cast<Uint8>(value & 255);
      return *this;
    }
    
  };
}

#endif /* COLOR_HPP */

