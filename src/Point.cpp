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
 * File:   Point.cpp
 * Author: olivier
 * 
 * Created on August 13, 2017, 12:45 AM
 */

#include "Point.hpp"

namespace SDL
{

  // static methods

  Point Point::fromInt(int x, int y)
  {
    return Point {x, y};
  }

  Point Point::fromSDL(const SDL_Point& point)
  {
    return Point {point.x, point.y};
  }


  // operator methods

  Point& Point::operator =(const Point& copy)
  {
    setX(copy.getX());
    setY(copy.getY());

    return *this;
  }

  bool Point::operator ==(const Point& comp) const
  {
    return (getX() == comp.getX() && getY() == comp.getY());
  }

  bool Point::operator !=(const Point& comp) const
  {
    return !(*this == comp);
  }


  // constructors/destructor

  Point::Point()
    : m_point {0, 0}
{

}

  Point::Point(int x, int y)
    : m_point {x ,y}
{

}

  Point::Point(const Point& orig)
    : m_point {orig.getX(), orig.getY()}
{

}

  Point::~Point() 
  {

  }


  // get methods

  int Point::getX() const
  {
    return m_point.x;
  }

  int Point::getY() const
  {
    return m_point.y;
  }


  // set methods

  Point& Point::setValues(int x, int y)
  {
    return setX(x).setY(y);
  }

  Point& Point::setX(int x)
  {
    m_point.x = x;
    return *this;
  }

  Point& Point::setY(int y)
  {
    m_point.y = y;
    return *this;
  }


  // other methods

  const SDL_Point* Point::toSDL() const
  {
    return &m_point;
  }

  SDL_Point* Point::toSDL()
  {
    return &m_point;
  }

}
