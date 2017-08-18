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
 * File:   Point.hpp
 * Author: olivier
 *
 * Created on August 13, 2017, 12:45 AM
 */

#ifndef POINT_HPP
#define POINT_HPP

#include <SDL2/SDL_rect.h>

namespace Cobra
{    

class Point {   
public:
    
    static Point fromSDL(const SDL_Point& point)
    {
        Point newPoint(point.x, point.y);
        return newPoint;
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

