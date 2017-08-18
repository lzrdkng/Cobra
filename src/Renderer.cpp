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
 * File:   CRenderer.cpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 9:01 PM
 */

#include "Renderer.hpp"
#include "Point.hpp"

using namespace Cobra;

Renderer::Renderer(SDL_Window* window, Uint8 flags, int index) 
{
    m_renderer = SDL_CreateRenderer(window, index, flags);
}

Renderer::Renderer(const Renderer& orig)
{

}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
}


Renderer& Renderer::clear()
{
    SDL_RenderClear(m_renderer);
    
    return *this;
}
/*
CRenderer& CRenderer::drawLine(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
    
    return *this;
}


CRenderer& CRenderer::drawLines(const CPoint* points, int count) 
{
    SDL_Point sdl_points[count];
    
    for (int i=0; i<count; ++i)
        sdl_points[i] = (points[i].toSDL);
    
    SDL_RenderDrawLines(m_renderer, sdl_points, count);
    
    return *this;
}


CRenderer& CRenderer::drawPoint(int x, int y)
{
    SDL_RenderDrawPoint(m_renderer, x, y);
    
    return *this;
}


CRenderer& CRenderer::drawPoints(const CPoint* points, int count) 
{
    for (int i=0; i<count; ++i)
        drawPoint(points[i].x(), points[i].y());  
    return *this;
}

CRenderer& CRenderer::drawRect(const CRect& rect)
{
    SDL_RenderDrawRect(m_renderer, &(rect.toSDL()));
    
    return *this;
}

CRenderer& CRenderer::drawRects(const CRect* rects, int count)
{
    for (int i=0; i<count; ++i)
        drawRect(rects[i]);
    
    return *this;
}


CRenderer& CRenderer::fillRect(const CRect& rect) 
{
    SDL_RenderFillRect(m_renderer, &(rect.toSDL()));
    return *this;
}

CRenderer& CRenderer::fillRects(const CRect* rects, int count)
{
    for (int i=0; i<count; ++i)
        fillRect(rects[i]);
    
    return *this;
}
*/
void Renderer::getClipRect(SDL_Rect& rect) const
{
    SDL_RenderGetClipRect(m_renderer, &rect);
}

bool Renderer::getDrawBlendMode(SDL_BlendMode& blendMode) const
{
    return SDL_GetRenderDrawBlendMode(m_renderer, &blendMode) == 0 ? true:false;
}

bool Renderer::getDrawColor(Uint8& r, Uint8& g, Uint8& b, Uint8& a) const
{
    return SDL_GetRenderDrawColor(m_renderer, &r, &g, &b, &a) == 0 ? true:false;
}

bool Renderer::getInfo(SDL_RendererInfo& info) const
{
    return SDL_GetRendererInfo(m_renderer, &info) == 0 ? true:false;
}
/*
bool CRenderer::getIntegerScale() const
{
    return SDL_RenderGetIntegerScale(m_renderer) == SDL_TRUE ? true:false;
}*/

void Renderer::getLogicalSize(int& w, int& h) const
{
    SDL_RenderGetLogicalSize(m_renderer, &w, &h);
}

bool Renderer::getOutputSize(int& w, int& h) const
{
    return SDL_GetRendererOutputSize(m_renderer, &w, &h) == 0 ? true:false;
}

void Renderer::getScale(float& x, float& y) const
{
    SDL_RenderGetScale(m_renderer, &x, &y);  
}

Rect Renderer::getViewport() const
{
    SDL_Rect rect;
    
    SDL_RenderGetViewport(m_renderer, &rect);
    
    return Rect::fromSDL(rect);
    
}

bool Renderer::isClipEnabled() const
{
    return SDL_RenderIsClipEnabled(m_renderer) == SDL_TRUE ? true:false;
}

Renderer& Renderer::present()
{
    SDL_RenderPresent(m_renderer);
    
    return *this;
}

Renderer& Renderer::setClipRect(const SDL_Rect& rect)
{
    if (SDL_RenderSetClipRect(m_renderer, &rect) != 0)
        throw;
    
    return *this;
}
/*
CRenderer& CRenderer::setIntegerScale(bool enable)
{
    SDL_bool e = SDL_FALSE;
    
    if (enable)
        e = SDL_TRUE;
    
    if (SDL_RenderSetIntegerScale(m_renderer, e) != 0)
        throw;
    
    return *this;
}*/

Renderer& Renderer::setLogicalSize(int w, int h)
{
    if (SDL_RenderSetLogicalSize(m_renderer, w, h) != 0)
        throw;
    
    return *this;
}

Renderer& Renderer::setScale(float scaleX, float scaleY)
{
    if (SDL_RenderSetScale(m_renderer, scaleX, scaleY) != 0)
        throw;
    
    return *this;
}

Renderer& Renderer::setViewport(const SDL_Rect& rect)
{
    if (SDL_RenderSetViewport(m_renderer, &rect) != 0)
        throw;
    
    return *this;
}

bool Renderer::targetSupported() const
{
    return SDL_RenderTargetSupported(m_renderer) == SDL_TRUE ? true:false;
}