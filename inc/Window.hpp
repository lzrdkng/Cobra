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
 * File:   Window.hpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 8:51 PM
 */

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

#include <stdexcept>
#include <string>
#include <iostream>

#include "Object.hpp"
#include "Renderer.hpp"
#include "Pair.hpp"

namespace Cobra
{

class Window : public Object
{
public:
    
    explicit Window(Uint32 flags,
                    const std::string& title = "GIVE ME A TITLE",
                    int x = 0,
                    int y = 0, 
                    int width = 252, 
                    int height = 252);
    ~Window();
    
    //Assign a new renderer to the object. The previous renderer is not destroy.
    void           assignRenderer(Renderer& renderer);
    void           clearRender();                         
    
    Uint32          getFlags()                       const;
    bool            getGrab()                        const;
    Uint32          getID()                          const;
    Pair<int>       getMaximumSize()                 const;
    Pair<int>       getMinimumSize()                 const;
    //float         getOpacity()                     const;
    Pair<int>       getPosition()                    const;
    Pair<int>       getSize()                        const;
    std::string     getTitle()                       const;
    //SDL_SysWMinfo getWMInfo()                      const;
    
    
    Window&       setFullscreen(Uint32 flags);
    Window&       setGrab(bool grabbed);
    Window&       setMaximumSize(int w, int h);
    Window&       setMinimumSize(int w, int h);
    //bool           setOpacity(float opacity);
    Window&       setPosition(int x, int y);
    //void           setWindowResizable(bool resizable);
    bool           setSize(int w, int h);
    void           setTitle(const std::string& title);
    
    
    
    Window&        hideWindow();
    Window&        maximizeWindow();
    Window&        minimizeWindow();
    void           showWindow();
    SDL_Window* toSDL() const;
    void           warpMouseInWindow(int x, int y)      const;
    
    virtual void eventHandler(const SDL_Event& event)
    { 
        if (event.type == SDL_TEXTINPUT)
            std::cout << "INPUT" << std::endl;
    }
    
private:
    
    SDL_Window* m_window;
    Renderer*  m_renderer;  
};

}

#endif /* WINDOW_HPP */

