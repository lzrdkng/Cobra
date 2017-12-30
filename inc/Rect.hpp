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

namespace SDLO
{

  /**
   * @brief Wrapper class for **SDL_Rect**
   */

  class Rect : private SDL_Rect
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
    constexpr static Rect fromInt(Sint16 x, Sint16 y, Uint16 w, Uint16 h) {
      return {x, y, w, h};
    }
      

    /**
     * @brief Rect factory. Create a Rect object from two SDL::Point instances.
     * @param a Top-left point
     * @param b Bottom-right point
     * @return SDL::Rect
     */
    constexpr static Rect fromPoints(const Point& a, const Point& b) {
      return {a, b};
    }
    
    /**
     * @brief Rect factory. Create a Rect object from a SDL_Rect structure.
     * @param sdl_rect The SDL_Rect structure.
     * @return SDL::Rect
     */
    constexpr static Rect fromSDL(const SDL_Rect& rect) {
      return rect;
    }


    // operator methods

    /**
     * @brief Assignation operator. Copy the original Rect into a new one.
     * @param orig The original Rect
     * @return SDL::Rect
     */
    constexpr Rect& operator =(const Rect& orig) {
      this->x = orig.x;
      this->y = orig.y;
      this->w = orig.w;
      this->h = orig.h;
      return *this;
    }
      

    /**
     * @Brief Equality operator. Determine if two Rect are equivalent.
     * @param comp The Rect to compare
     * @return bool
     */
    constexpr bool operator ==(const Rect& comp) const {
      return (x == comp.x &&
	      y == comp.y &&
	      w == comp.w &&
	      h == comp.h);
    }

    /**
     * @brief Inequality operator. Determine if two Rect are not equivalent.
     * @param comp The Rect to compare
     * @return bool
     */
    constexpr bool operator !=(const Rect& comp) const {
      return !(*this == comp);
    }


    // constructors/destructor

    /**
     * @brief Default constructor. SDL_Rect struct intialize to {0, 0, 0, 0}.
     */
    constexpr Rect() : SDL_Rect {0, 0, 0, 0} {}

    /**
     * @brief Copy constructor.
     * @param orig Rect to copy
     */
    constexpr Rect(const Rect& orig)
      : SDL_Rect {orig.x, orig.y, orig.w, orig.h} {}

    /**
     * @brief Constructor from 4 integers.
     * @param x Top-left x value
     * @param y Top-left y value
     * @param w Width
     * @param h Height
     */
    constexpr Rect(Sint16 x, Sint16 y, Uint16 w, Uint16 h)
      : SDL_Rect {x, y, w ,h} {}

    /**
     * @brief Constructor from two SDL::Point instances.
     * @param a Top-left point
     * @param b Bottom-right point
     * @return SDL::Rect
     */
    constexpr Rect(const Point& a, const Point& b)
      : SDL_Rect {a.getX(), a.getY(), 0, 0} {
      w = b.getX() - x;
      h = b.getY() - y;
    }

    /**
     * @brief Create a Rect object from a SDL_Rect structure.
     * @param sdl_rect The SDL_Rect structure.
     */
    constexpr Rect(const SDL_Rect& rect)
      : SDL_Rect {rect.x, rect.y, rect.w, rect.h} {}
    

    // get methods

    /**
     * @brief Return rect's height.
     * @return Uint16
     */
    constexpr Uint16 getHeight() const { return h; }

    /**
     * @brief Return rect's width.
     * @return Uint16
     */
    constexpr Uint16 getWidth() const { return w; }

    /**
     * @brief Return rect's x value.
     * @return Sint16
     */
    constexpr Sint16 getX() const { return x; }

    /**
     * @brief Return rect's y value.
     * @return Sint16
     */
    constexpr Sint16 getY() const { return y; }


    // set methods

    /**
     * @brief Set rect's height.
     * @param h Height
     * @return SDL::Rect&
     */
    Rect& setHeight(Uint16 H) {
      h = H;
      return *this;
    }

    /**
     * @brief Set all rect's values.
     * @param x Top-left x value
     * @param y Top-left y value
     * @param w Width
     * @param h Height
     * @return SDL::Rect&
     */
    Rect& setValues(Sint16 X, Sint16 Y, Uint16 W, Uint16 H) {
      x = X;
      y = Y;
      w = W;
      h = H;
      return *this;
    }

    /**
     * @brief Set rect's width.
     * @param w Width
     * @return SDL::Rect&
     */
    Rect& setWidth(Uint16 W) {
      w = W;
      return *this;
    }

    /**
     * @brief Set rect's x value.
     * @param x Top-left x value
     * @return SDL::Rect&
     */
    Rect& setX(Sint16 X) {
      x = X;
      return *this;
    }

    /**
     * @brief Set rect's y value.
     * @param y Top-left y value
     * @return SDL::Rect&
     */
    Rect& setY(Sint16 Y) {
      y = Y;
      return *this;
    }
    
  };

}

#endif /* RECTANGLE_HPP */

