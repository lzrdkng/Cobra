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
 * File:   Application.hpp
 * Author: olivier
 *
 * Created on August 14, 2017, 1:40 AM
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "SDL.hpp"
#include "Object.hpp"
#include "Window.hpp"

/* 
 * Singleton pattern class
 * https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 */

namespace SDL
{

class Application : public Object
{

    
public:
    
    
    virtual ~Application()
    {
        SDL_Quit();
    }
    
    static void init(Uint32 flags)
    {
        static Application app(flags);
    }
    
    
    static void run(Window& window)
    {
        static bool quit = false;
        static SDL_Event event;
        
        while (!quit)
        {

            while (SDL_PollEvent(&event) != 0)
            {
                if (event.type == SDL_QUIT)
                    quit = true;
            }

            window.paintEvent();
        }
    }

    static void initSubSystem(SDL::InitFlags flags)
    {
        if (SDL_InitSubSystem(flags) != 0)
            throw;
    }
    
    
private:
    
    
    Application(Uint32 flags) : Object()
    {
        SDL_Init(flags);
    }
    
    Application(const Application&);
    void operator=(const Application& app);

public:

    virtual void paintEvent() {}

};

}

#endif /* APPLICATION_HPP */

