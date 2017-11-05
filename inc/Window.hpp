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
 * File:   Window.hpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 8:51 PM
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

// std imports
#include <string>
// C SDL imports
#include <SDL2/SDL_syswm.h>
// lib imports
#include "SDL.hpp"
#include "Pair.hpp"
#include "Point.hpp"

namespace SDL
{

/**
 * @brief Wrapper class for **SDL_Window**.
 *
 * **SDL 2.0.0**
 */

class Window
{
public:

    /**
     * @brief Explicit constructor for Class SDL::Window.
     *
     * Create a new window with the specified
     * title, position, dimensions, and flags.
     *
     * @param title the title of the window, in UTF-8 encoding
     * @param x the x position of the window
     * @param y the y position of the window
     * @param w the width of the window, in screen coordinates
     * @param h the height of the window, in screen coordinates
     * @param flags SDL::WindowFlags
     *
     *
     * @throw SDL::Error
     *
     * If SDL failed to create the window.
     *
     */
    explicit Window(const char* title,
                    int width = 640,
                    int height = 480,
                    SDL::WindowFlags flags = SDL::WindowShown,
                    int x = SDL::WindowPositionUndefined,
                    int y = SDL::WindowPositionUndefined);



    /**
     * @brief Copy constructor of Class SDL::Window.
     *
     * Create a new window with the same attribute as the original.
     *
     * @note However, the **renderer** linked to the orignal window
     * **is not copied**, this mean that you need to create a new
     * Renderer object with the new window.
     *
     */
    Window(const Window& orig);


    /**
     * Class destructor, will call **SDL_DestroyWindow**
     */
    virtual ~Window();
    
    
    
    /** Return a mask of the SDL::WindowFlags.
     * @return SDL::WindowFlags
     */
    WindowFlags getFlags() const;

    /** Return state of window's grabbed.
     * @return bool
     */
    bool getGrab() const;

    /*
     * Return the window's ID.
     * @return Uint32
     * @throw SDL::Error on failure
     */
    Uint32 getID() const;

    /** Return the window's maximum size.
     *  @return SDL::Pair<int>
     *  @sa SDL::Pair
     */
    Pair<int> getMaximumSize() const;

    /** Return the window's minimum size.
     *  @return SDL::Pair<int>
     *  @sa SDL::Pair
     */
    Pair<int> getMinimumSize() const;


#if SDL_VERSION_ATLEAST(2, 0, 5)
    /**
     * @brief Return the window' opacity
     * @return float
     * @throw SDL::Error on failure
     */
    float getOpacity() const;
#endif

    /** Return the window's position.
     *  @return SDL::Point
     */
    Point getPosition() const;


    /** Return the window's rendering context on **success**
     * or **NULL** on **failure**.
     * @return SDL_Renderer*
     * @warning Use with caution
     * @sa @link https://wiki.libsdl.org/SDL_Renderer
     */
    SDL_Renderer* getRenderer() const;


    /** Return the window's size.
     *  @return Pair<int>
     *  @sa Pair
     */
    Pair<int> getSize() const;

    /** Return the window's title.
     *  @return std::string
     */
    std::string getTitle() const;

#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Get the driver specific information about the window.
     * @return SDL_SysWMInfo structure
     * @throw SDL::Error if information could not be retrieved.
     */
    SDL_SysWMinfo getWMInfo() const;
#endif
    
    /** Set the window's fullscreen state.
     * @param Uint32 flags
     * @return SDL::Window&
     * @throw SDL::Error on failure.
     */
    Window& setFullscreen(SDL::WindowFlags flags);

    /** Set the window's input grab mode.
     * @param bool grabbed
     * @return SDL::Window&
     */
    Window& setGrab(bool grabbed);

    /** Set the window's maximum size.
     * @param int width
     * @param int height
     * @return SDL::Window&
     * @note Values **under** 0 or **overflow** of **int size**
     * will result in value 0.
     */
    Window& setMaximumSize(int w, int h);

    /** Set the window's minimum size
     * @param int width
     * @param int height
     * @return SDL::Window&
     * @note Values **under** 0 or **overflow** of **int size**
     * wil result in value 0.
     */
    Window& setMinimumSize(int w, int h);

#if SDL_VERSION_ATLEAST(2, 0, 5)
    /**
     * @brief Set the opacity of the window.
     * @param opacity the opacity value [0, 1] == [transparent -> opaque]
     * @return SDL::Window&
     * @throw SDL::Error on failure
     * @remark The parameter **opacity** will be clamped internally between
     * 0.0f (transparent) and 1.0f (opaque). This function also returns -1 if
     * setting the opacity isn't supported.
     * This function is only supported on DirectFB, X11, Cocoa (Apple Mac OS X)
     * and Microsoft Windows.
     * @sa SDL::Window::getOpacity
     */
    Window& setOpacity(float opacity);
#endif

    /** Set the window's position.
     * @param int x
     * @param int y
     * @return Window&
     * @note Values **under** 0 or **overflow** of **int size** wil
     * result in value 0.
     */
    Window& setPosition(int x, int y);

#if SDL_VERSION_ATLEAST(2, 0, 5)
    /**
     * @brief Set the user-resizable state of the window.
     * @param resizable
     * @return SDL::Window&
     * @remark This will ad or remove the window's SDL::WindowResizable flags
     * and allow/disallow user resizing of the window. This is a no-op if the
     * window's resizable state already matches the requested state.
     * @note You can't change the resizable state of a fullscreen window.
     * @sa SDL::Window::getFlags
     */
    Window& setResizable(bool resizable);
#endif
    /** Set the window's size.
     * @param int width
     * @param int height
     * @return Winow&
     * @note Values must be **between** the **minimum** and **maximum** size.
     */
    Window& setSize(int w, int h);


    /** Set the window's title.
     * @param const char* title
     * @return Window&
     */
    Window& setTitle(const char* title);
    
    

    /** Hide the window.
     * @return Window&
     */
    Window& hide();

    /** Make the window as large as possible.
     * @return Window&
     */
    Window& maximize();

    /** Make the window minimize to an iconic representation.
     * @return Window&
     */
    Window& minimize();

    /** Show the window.
     * @return Window&
     */
    Window& show();

    /** Return the C pointer of the wrapped object.
     * @return SDL_Window*
     * @warning Use with caution.
     */
    SDL_Window* toSDL() const;


    /** Move the mouse to the given position relative to the window.
     * @param int x
     * @param int y
     * @return Window&
     */
    Window& warpMouse(int x, int y);
    
    /**
     * @brief Use this method to copy the window surface to the screen.
     * @return SDL::Window&
     * @throw SDL::Error on failure.
     */
    Window& update();

private:
    
    SDL_Window*   m_window;  // wrapped object

};

}

#endif /* WINDOW_HPP */

