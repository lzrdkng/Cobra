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

#include "Point.hpp"

namespace SDL
{

  /**
   * @brief Wrapper class for **SDL_Rect**
   */

  class Rect
  {
  public:


    // static methods

    /**
     * @brief Rect factory. Create a Rect object from 4 integers.
     * @param x Top-left x value
     * @param y Top-left y value
     * @param w Width
     * @param h Height
     * @return SDL::Rect
     */
    static Rect fromInt(Sint16 x, Sint16 y, Uint16 w, Uint16 h);

    /**
     * @brief Rect factory. Create a Rect object from two SDL::Point instances.
     * @param a Top-left point
     * @param b Bottom-right point
     * @return SDL::Rect
     */
    static Rect fromPoints(const Point& a, const Point& b);

    /**
     * @brief Rect factory. Create a Rect object from a SDL_Rect structure.
     * @param sdl_rect The SDL_Rect structure.
     * @return SDL::Rect
     */
    static Rect fromSDL(const SDL_Rect& sdl_rect);


    // operator methods

    /**
     * @brief Assignation operator. Copy the original Rect into a new one.
     * @param orig The original Rect
     * @return SDL::Rect
     */
    Rect& operator =(const Rect& orig);

    /**
     * @brief Equality operator. Determine if two Rect are equivalent.
     * @param comp The Rect to compare
     * @return bool
     */
    bool operator ==(const Rect& comp) const;

    /**
     * @brief Inequality operator. Determine if two Rect are not equivalent.
     * @param comp The Rect to compare
     * @return bool
     */
    bool operator !=(const Rect& comp) const;


    // constructors/destructor

    /**
     * @brief Default constructor. SDL_Rect struct intialize to {0, 0, 0, 0}.
     */
    Rect();

    /**
     * @brief Copy constructor.
     * @param orig Rect to copy
     */
    Rect(const Rect& orig);

    /**
     * @brief Constructor from 4 integers.
     * @param x Top-left x value
     * @param y Top-left y value
     * @param w Width
     * @param h Height
     */
    constexpr Rect(Sint16 x,
                   Sint16 y,
                   Uint16 w,
                   Uint16 h) : m_rect {x, y, w ,h} {}

    /**
     * @brief Constructor from two SDL::Point instances.
     * @param a Top-left point
     * @param b Bottom-right point
     * @return SDL::Rect
     */
    Rect(const Point& a, const Point& b);

    /**
     * @brief Create a Rect object from a SDL_Rect structure.
     * @param sdl_rect The SDL_Rect structure.
     */
    Rect(const SDL_Rect& sdl_rect);
    
    /**
     * @brief Destructor
     */
    virtual ~Rect();
    

    // get methods

    /**
     * @brief Return rect's height.
     * @return Uint16
     */
    Uint16 getHeight() const;

    /**
     * @brief Return rect's width.
     * @return Uint16
     */
    Uint16 getWidth() const;

    /**
     * @brief Return rect's x value.
     * @return Sint16
     */
    Sint16 getX() const;

    /**
     * @brief Return rect's y value.
     * @return Sint16
     */
    Sint16 getY() const;


    // set methods

    /**
     * @brief Set rect's height.
     * @param h Height
     * @return SDL::Rect&
     */
    Rect& setHeight(Uint16 h);

    /**
     * @brief Set all rect's values.
     * @param x Top-left x value
     * @param y Top-left y value
     * @param w Width
     * @param h Height
     * @return SDL::Rect&
     */
    Rect& setValues(Sint16 x,
                    Sint16 y,
                    Uint16 w,
                    Uint16 h);

    /**
     * @brief Set rect's width.
     * @param w Width
     * @return SDL::Rect&
     */
    Rect& setWidth(Uint16 w);

    /**
     * @brief Set rect's x value.
     * @param x Top-left x value
     * @return SDL::Rect&
     */
    Rect& setX(Sint16 x);

    /**
     * @brief Set rect's y value.
     * @param y Top-left y value
     * @return SDL::Rect&
     */
    Rect& setY(Sint16 y);


    // other methods

    /**
     * @brief Return constante wrapped structure.
     * @return SDL_Rect*
     * @warning Use with caution.
     */
    const SDL_Rect* toSDL() const;

    /**
     * @brief Return wrapped structure.
     * @return SDL_Rect*
     * @warning Use with **extreme** caution.
     */
    SDL_Rect* toSDL();
    
    
  private:
    
    SDL_Rect m_rect; // wrapped structure

  };

}

#endif /* RECTANGLE_HPP */

