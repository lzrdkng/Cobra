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
 * File:   Point.hpp
 * Author: olivier
 *
 * Created on August 13, 2017, 12:45 AM
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <SDL2/SDL_rect.h>

namespace SDLO
{

  /**
   * @brief Wrapper class for **SDL_Point**
   */

  class Point : private SDL_Point
  {
  public:


    // static methods

    /**
     * @brief static method returning a SDL::Point instance
     * created from two integers.
     * @param x
     * @param y
     * @return SDL::Point
     */
    constexpr static Point fromInt(int x, int y) { return {x, y}; }

    /**
     * @brief static method returning a SDL::Point instance
     * created from a SDL_Point.
     * @param point
     * @return SDL::Point
     */
    constexpr static Point fromSDL(const SDL_Point& point) { return point; }


    // operator methods

    /**
     * @brief operator =
     * @param copy
     */
    constexpr Point& operator =(const Point& copy) { this->x = copy.getX(); this->y = copy.getY(); return *this; } 

    /**
     * @brief operator ==
     * @param comp
     * @return bool
     */
    constexpr bool operator ==(const Point& comp) const { return (x == comp.getX() && y == comp.getY() ); }

    /**
     * @brief operator !=
     * @param comp
     * @return bool
     */
    constexpr bool operator !=(const Point& comp) const { return !(*this == comp); }


    // constructors/destructor

    constexpr  Point() : SDL_Point {0, 0} {}

    /**
     * @brief Explicit SDL::Point constructor.
     * @param x
     * @param y
     */
    constexpr Point(int x, int y) : SDL_Point {x, y} {}


    /**
     * @brief Copy SDL::Point constructor.
     * @param orig
     */
    constexpr Point(const Point& orig) : SDL_Point {orig.getX(), orig.getY()} {}


    constexpr Point(const SDL_Point& point) : SDL_Point {point.x, point.y} {}
      
    // get methods
    
    /**
     * @brief Return x value.
     * @return int
     */
    constexpr int getX() const { return x; }

    /**
     * @brief Return y value.
     * @return int
     */
    constexpr int getY() const { return y; }
    
    /**
     * @brief Set x, y values.
     * @param x
     * @param y
     * @return SDL::Point
     */
    Point& setValues(int X, int Y) {
      x = X;
      y = Y;
      return *this;
    }

    // set methods
    
    /**
     * @brief Set x value.
     * @param x
     * @return SDL::Point
     */
    Point& setX(int X) {
      x = X;
      return *this;
    }

    /**
     * @brief Set y value.
     * @param y
     * @return SDL::Point
     */
    Point& setY(int Y) {
      y = Y;
      return *this;
    }
        
  };
}

#endif /* POINT_HPP */

