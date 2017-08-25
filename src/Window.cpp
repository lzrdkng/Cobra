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
 *  1.The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *  2.Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *  3.This notice may not be removed or altered from any source distribution.
 */

/* 
 * File:   Window.cpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 8:51 PM
 */


#include <iostream>

#include "Window.hpp"

// Public interface

using namespace SDL;

Window::Window(const char* title,
               int x,
               int y,
               int width,
               int height,
               SDL::WindowFlags flags) : Object()
{
    m_window = SDL_CreateWindow(title,
                                x,
                                y,
                                width,
                                height,
                                flags);
        
    if (m_window == nullptr)
        throw std::runtime_error(SDL_GetError());
}


Window::Window(const Window& orig)
{

    Point     pos  = orig.getPosition();
    Pair<int> size = orig.getSize();

    WindowFlags flags = orig.getFlags();

    m_window = SDL_CreateWindow(orig.getTitle().c_str(),
                                pos.getX(),
                                pos.getY(),
                                size.getLeftValue(),
                                size.getRightValue(),
                                flags);

    if (m_window == nullptr)
        throw std::runtime_error(SDL_GetError());



}


Window::~Window()
{   
    if (m_window != nullptr)
        SDL_DestroyWindow(m_window);

    m_window   = nullptr;
}



WindowFlags Window::getFlags() const
{
    return static_cast<WindowFlags>(SDL_GetWindowFlags(m_window));
}

bool Window::getGrab() const
{
    return SDL_GetWindowGrab(m_window);
}


Uint32 Window::getID() const
{
    Uint32 ID = SDL_GetWindowID(m_window);
    
    if (ID == 0)
        throw std::runtime_error(SDL_GetError());
    
    return ID;
}

Pair<int> Window::getMaximumSize() const
{
    
    int w, h;
    
    SDL_GetWindowMaximumSize(m_window, &w, &h);
    
    Pair<int> maximumSize(w, h);
    
    return maximumSize;
}

Pair<int> Window::getMinimumSize() const
{
    int w, h;
    
    SDL_GetWindowMinimumSize(m_window, &w, &h);
    
    Pair<int> minimumSize(w, h);
    
    return minimumSize;
}
/* Current version of SDL2 on Ubuntu 16.04 doesn't support 
float CWindow::getOpacity() const
{
    float opacity;
    
    return SDL_GetWindowOpacity(m_window, &opacity) == 0 ? opacity : -1.0;
}*/

Point Window::getPosition() const
{
    int x, y;
    
    SDL_GetWindowPosition(m_window, &x, &y);
    
    Point windowPosition(x, y);
    
    return windowPosition;
}

SDL_Renderer* Window::getRenderer() const
{
    return SDL_GetRenderer(m_window);
}

Pair<int> Window::getSize() const
{
    int w, h;
    
    SDL_GetWindowSize(m_window, &w, &h);
    
    Pair<int> windowSize(w, h);
    
    return windowSize;
}

std::string Window::getTitle() const
{
    return SDL_GetWindowTitle(m_window);
}

/*
SDL_SysWMinfo Window::getWMInfo() const
{
    SDL_SysWMinfo info;
    
    if (SDL_GetWindowWMInfo(m_window, &info) == SDL_FALSE)
        throw std::runtime_error(SDL_GetError());
    
    return info;
}*/



Window& Window::setFullscreen(SDL::WindowFlags flags)
{
    if (SDL_SetWindowFullscreen(m_window, flags) == 0)
        return *this;
    throw std::runtime_error(SDL_GetError());
}

Window& Window::setGrab(bool grabbed)
{
    if (grabbed)
        SDL_SetWindowGrab(m_window, SDL_TRUE);
    else
        SDL_SetWindowGrab(m_window, SDL_FALSE);
    return *this;
}

Window& Window::setMaximumSize(int w, int h)
{
    SDL_SetWindowMaximumSize(m_window, w, h);
    return *this;
}

Window& Window::setMinimumSize(int w, int h)
{
    SDL_SetWindowMinimumSize(m_window, w, h);
    return *this;
}

/* Current version of SDL2 on Ubuntu 16.04 doesn't support 
Window& Window::setOpacity(float opacity)
{
    if (SDL_SetWindowOpacity(m_window, opacity) == 0)
        return *this;
 
   throw
}*/

Window& Window::setPosition(int x, int y)
{
    SDL_SetWindowPosition(m_window, x, y);
    return *this;
}
/* Current version of SDL2 on Ubuntu 16.04 doesn't support 
void CWindow::setResizable(bool resizable)
{
    if (resizable)
        SDL_SetWindowResizable(m_window, SDL_TRUE);
    else
        SDL_SetWindowResizable(m_window, SDL_FALSE);
} */

Window& Window::setSize(int w, int h)
{
    SDL_SetWindowSize(m_window, w, h);
    return *this;
}

Window& Window::setTitle(const char* title)
{
    SDL_SetWindowTitle(m_window, title);
    return *this;
}

// Other methods

Window& Window::hide()
{
    SDL_HideWindow(m_window);
    return *this;
}

Window& Window::maximize()
{
    SDL_MaximizeWindow(m_window);
    return *this;
}

Window& Window::minimize()
{
    SDL_MinimizeWindow(m_window);
    return *this;
}

Window& Window::show()
{
    SDL_ShowWindow(m_window);
    return *this;
}

SDL_Window* Window::toSDL() const
{
    return m_window;
}

Window& Window::warpMouse(int x, int y)
{
    SDL_WarpMouseInWindow(m_window, x, y);
    return *this;
}
