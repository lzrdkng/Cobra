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

namespace SDL
{    

class Point {   
public:
    
    static Point fromSDL(const SDL_Point& point)
    {
        Point newPoint(point.x, point.y);
        return newPoint;
    }

    static Point fromInt(int x, int y)
    {
      SDL::Point point(x, y);
      return point;
    }
    
    explicit Point(int x=0, int y=0);
    
    Point(const Point& orig);
    
    virtual ~Point();
    
    // get methods
    
    int getX() const;
    int getY() const;
    
    // set methods
    
    Point& setX(int x);
    Point& setY(int y);
    
    // other methods
    
    const SDL_Point* toSDL() const;
    
    // operator methods
    
    bool operator==(const Point& comp) const;
    
private:

    SDL_Point m_point;
    
};

}

#endif /* POINT_HPP */

