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
 * File:   Application.hpp
 * Author: olivier
 *
 * Created on August 14, 2017, 1:40 AM
 */

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>
#include <SDL2/SDL.h>
#include "Object.hpp"

/* 
 * Singleton pattern class
 * https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
 */

namespace Cobra
{

class Application
{
private:
    std::vector<Object*> m_objects;
    
public:
    
    
    virtual ~Application()
    {
        SDL_Quit();
    }
    
    static Application* init(Uint32 flags)
    {
        static Application app(flags);
        
        return &app;
    }
    
    void bind(Object& object)
    {
        m_objects.push_back(&object);
    }
    
    void run()
    {
        static bool quit = false;
        static SDL_Event event;
        
        while (!quit)
            while (SDL_PollEvent(&event) != 0)
                if (event.type == SDL_QUIT)
                    quit = true;
                else
                {
                    for (Uint32 i=0; i<m_objects.size(); ++i)
                    {
                        m_objects[i]->eventHandler(event);
                    }
                }
    }
    
    
private:
    
    
    Application(Uint32 flags)
    {
        SDL_Init(flags);
    }
    
    Application(const Application&);
    void operator=(const Application& app);

};

}

#endif /* APPLICATION_HPP */

