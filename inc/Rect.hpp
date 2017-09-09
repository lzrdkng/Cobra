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
     * @brief Return a Rect instance created from integers.
     * @param x
     * @param y
     * @param w
     * @param h
     * @return Rect
     */
    static Rect fromInt(Sint16 x, Sint16 y, Uint16 w, Uint16 h);

    /**
     * @brief Return a Rect instanced created from SDL_Rect.
     * @param sdl_rect
     * @return
     */
    static Rect fromSDL(const SDL_Rect& sdl_rect);
    

    // operator methods

    void operator =(const Rect& orig);

    bool operator ==(const Rect& comp) const;

    bool operator !=(const Rect& comp) const;


    // constructors/destructor

    /**
     * @brief Explicit constructor of class SDL::Rect
     * @param x
     * @param y
     * @param w
     * @param h
     */
    explicit Rect(Sint16 x=0,
                  Sint16 y=0,
                  Uint16 w=0,
                  Uint16 h=0);

    /**
     * @brief Copy constructor of class SDL::Rect.
     * @param orig
     */
    Rect(const Rect& orig);

    /**
     * @brief Implicit constructor of class SDL::Rect.
     * @param orig
     */
    Rect(const SDL_Rect& orig);
    
    /**
     * @brief Destructor of class SDL::Rect
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
     * @param h
     * @return SDL::Rect&
     */
    Rect& setHeight(Uint16 h);

    /**
     * @brief Set all rect's values.
     * @param x
     * @param y
     * @param w
     * @param h
     * @return SDL::Rect&
     */
    Rect& setValues(Sint16 x,
                    Sint16 y,
                    Uint16 w,
                    Uint16 h);

    /**
     * @brief Set rect's width.
     * @param w
     * @return SDL::Rect&
     */
    Rect& setWidth(Uint16 w);

    /**
     * @brief Set rect's x value.
     * @param x
     * @return SDL::Rect&
     */
    Rect& setX(Sint16 x);

    /**
     * @brief Set rect's y value.
     * @param y
     * @return SDL::Rect&
     */
    Rect& setY(Sint16 y);


    // other methods

    /**
     * @brief Return wrapped object.
     * @return SDL_Rect*
     * @warning Use with caution.
     */
    const SDL_Rect* toSDL() const;
    
    
private:
    
    SDL_Rect m_rect; // wrapped object

};

}

#endif /* RECTANGLE_HPP */

