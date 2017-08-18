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
 * File:   CWindow.cpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 8:51 PM
 */

#include "Window.hpp"

// Public interface

using namespace Cobra;

Window::Window(Uint32 flags,
               const std::string& title,
               int x,
               int y,
               int width,
               int height)         
{
    m_renderer = nullptr;
    
    m_window = SDL_CreateWindow(title.c_str(),
                                x,
                                y,
                                width,
                                height,
                                flags);
        
    if (m_window == nullptr)
        throw std::runtime_error(SDL_GetError());
}


Window::~Window()
{
    delete m_renderer;
    m_renderer = nullptr;
    
    SDL_DestroyWindow(m_window);
    m_window   = nullptr;
    
    SDL_Quit();
}



Uint32 Window::getFlags() const
{
    return SDL_GetWindowFlags(m_window);
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

Pair<int> Window::getPosition() const
{
    int x, y;
    
    SDL_GetWindowPosition(m_window, &x, &y);
    
    Pair<int> windowPosition(x, y);
    
    return windowPosition;
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




Window& Window::setFullscreen(Uint32 flags)
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
bool CWindow::setOpacity(float opacity)
{
    return SDL_SetWindowOpacity(m_window, opacity) == 0 ? true : false;
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

bool Window::setSize(int w, int h)
{
    if (w < 0 || h < 0)
        return false;
    
    SDL_SetWindowSize(m_window, w, h);
    
    return true;
}

void Window::setTitle(const std::string& title)
{
    SDL_SetWindowTitle(m_window, title.c_str()); 
}


Window& Window::hideWindow()
{
    SDL_HideWindow(m_window);
    return *this;
}

Window& Window::maximizeWindow()
{
    SDL_MaximizeWindow(m_window);
    return *this;
}

Window& Window::minimizeWindow()
{
    SDL_MinimizeWindow(m_window);
    return *this;
}

void Window::showWindow()
{
    SDL_ShowWindow(m_window);
}

SDL_Window* Window::toSDL() const
{
    return m_window;
}

void Window::warpMouseInWindow(int x, int y) const
{
    SDL_WarpMouseInWindow(m_window, x, y);
}


void Window::assignRenderer(Renderer& renderer)
{
    m_renderer = &renderer;
}