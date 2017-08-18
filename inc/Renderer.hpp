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
 * File:   Renderer.hpp
 * Author: olivier
 *
 * Created on August 12, 2017, 9:01 PM
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL_render.h>
#include "Point.hpp"
#include "Rect.hpp"

namespace Cobra
{

class Renderer {
public:
    
    explicit Renderer(SDL_Window* window,
                       Uint8 flags,
                       int index=-1);
    
    Renderer(const Renderer& orig);
    
    virtual ~Renderer();
    
    
    //CRenderer& drawLine(int x1, int y1, int x2, int y2);
    //CRenderer& drawLines(const CPoint* points, int count);
    //CRenderer& drawPoint(int x, int y);
    //CRenderer& drawPoints(const CPoint* points, int count);
    //CRenderer& drawRect(const CRect& rect);
    //CRenderer& drawRects(const CRect* rects, int count);
    //CRenderer& fillRect(const CRect& rect);
    //CRenderer& fillRects(const CRect* rects, int count);
    
    // get methods
    
    void           getClipRect(SDL_Rect& rect)                          const;
    bool           getDrawBlendMode(SDL_BlendMode& blendMode)           const;
    bool           getDrawColor(Uint8& r, Uint8& g, Uint8& b, Uint8& a) const;
    SDL_Texture*   getTarget()                                          const;
    bool           getInfo(SDL_RendererInfo& info)                      const;
    //bool getIntegerScale() const;
    void           getLogicalSize(int& w, int& h)                       const;
    bool           getOutputSize(int& w, int& h)                        const;
    void           getScale(float& x, float& y)                         const;
    Rect          getViewport()                                        const;
    
    // set methods
    
    Renderer& setClipRect(const SDL_Rect& rect);
    //CRenderer& setIntegerScale(bool enable);
    Renderer& setLogicalSize(int w, int h);
    Renderer& setScale(float scaleX, float scaleY);
    Renderer& setViewport(const SDL_Rect& rect);
    
    // other methods
    
    
    Renderer& clear();
    bool isClipEnabled() const;
    Renderer& present();
    //bool readPixels(const SDL_Rect& rect, Uint32 format)
    bool targetSupported() const;
    
private:

    SDL_Renderer* m_renderer;
};

}

#endif /* RENDERER_HPP */

