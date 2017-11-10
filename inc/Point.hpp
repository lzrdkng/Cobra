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

/**
 * @brief Wrapper class for **SDL_Point**
 */

class Point
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
    static Point fromInt(int x, int y);

    /**
     * @brief static method returning a SDL::Point instance
     * created from a SDL_Point.
     * @param point
     * @return SDL::Point
     */
    static Point fromSDL(const SDL_Point& point);


    // operator methods

    /**
     * @brief operator =
     * @param copy
     */
    Point& operator =(const Point& copy);

    /**
     * @brief operator ==
     * @param comp
     * @return bool
     */
    bool operator ==(const Point& comp) const;

    /**
     * @brief operator !=
     * @param comp
     * @return bool
     */
    bool operator !=(const Point& comp) const;


    // constructors/destructor

    Point();

    /**
     * @brief Explicit SDL::Point constructor.
     * @param x
     * @param y
     */
    Point(int x, int y);


    /**
     * @brief Copy SDL::Point constructor.
     * @param orig
     */
    Point(const Point& orig);

    /**
     * @brief SDL::Point destructor
     */
    virtual ~Point();


    // get methods
    
    /**
     * @brief Return x value.
     * @return int
     */
    int getX() const;

    /**
     * @brief Return y value.
     * @return int
     */
    int getY() const;
    
    /**
     * @brief Set x, y values.
     * @param x
     * @param y
     * @return SDL::Point
     */
    Point& setValues(int x, int y);

    // set methods
    
    /**
     * @brief Set x value.
     * @param x
     * @return SDL::Point
     */
    Point& setX(int x);

    /**
     * @brief Set y value.
     * @param y
     * @return SDL::Point
     */
    Point& setY(int y);
    

    // other methods
    
    /**
     * @brief Return constant wrapped object.
     * @return const SDL_Point*
     * @warning Use with caution.
     */
    const SDL_Point* toSDL() const;

    /**
     * @brief Return wrapped object.
     * @return SDL_Point*
     * @warning Use with **extreme** caution.
     */
    SDL_Point* toSDL();

    
private:

    SDL_Point m_point; // wrapped object
    
};

}

#endif /* POINT_HPP */

