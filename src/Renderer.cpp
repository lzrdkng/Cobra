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
 * File:   Renderer.cpp
 * Author: olivier
 * 
 * Created on August 12, 2017, 9:01 PM
 */

#include "Renderer.hpp"


using namespace SDL;


// constructors/destructor

Renderer::Renderer(Window& window, SDL::RendererFlags flags, int index) : Object(&window), m_renderer(nullptr)
{
    m_renderer = SDL_CreateRenderer(window.toSDL(), index, flags);

    if (m_renderer == nullptr)
        throw Error(SDL_GetError());
}

Renderer::~Renderer()
{
    if (m_renderer != nullptr)
        SDL_DestroyRenderer(m_renderer);

    m_renderer = nullptr;
}


// get methods

Rect Renderer::getClipRect() const
{
    SDL_Rect sdl_rect;

    SDL_RenderGetClipRect(m_renderer, &sdl_rect);

    return Rect::fromSDL(sdl_rect);
}

BlendModes Renderer::getDrawBlendMode() const
{
    SDL_BlendMode blendMode;

    if (SDL_GetRenderDrawBlendMode(m_renderer, &blendMode) == 0)
        return static_cast<SDL::BlendModes>(blendMode);

    throw SDL::Error(SDL_GetError());
}

Color Renderer::getDrawColor() const
{
    Uint8 r, g, b, a;

    if (SDL_GetRenderDrawColor(m_renderer, &r, &g, &b, &a) == 0)
        return Color::fromRGBA(r, g, b, a);

    throw SDL::Error(SDL_GetError());
}

bool Renderer::getInfo(SDL_RendererInfo& info) const
{
    return SDL_GetRendererInfo(m_renderer, &info) == 0 ? true:false;
}



#if SDL_VERSION_ATLEAST(2, 0, 5)
bool Renderer::getIntegerScale() const
{
    return SDL_RenderGetIntegerScale(m_renderer) == SDL_TRUE ? true:false;
}
#endif

#if SDL_VERSION_ATLEAST(2, 0, 0)
Pair<int> Renderer::getLogicalSize() const
{
    int w, h;

    SDL_RenderGetLogicalSize(m_renderer, &w, &h);

    Pair<int> size(w, h);

    return size;
}

Pair<int> Renderer::getOutputSize() const
{
    int w, h;

    if (SDL_GetRendererOutputSize(m_renderer, &w, &h) != 0)
        throw SDL::Error(SDL_GetError());

    Pair<int> size(w, h);

    return size;
}

Pair<float> Renderer::getScale() const
{
    float x, y;

    SDL_RenderGetScale(m_renderer, &x, &y);

    Pair<float> scale(x, y);

    return scale;
}
#endif

SDL_Texture* Renderer::getTarget() const
{
    return nullptr;
}

#if SDL_VERSION_ATLEAST(2, 0, 0)
Rect Renderer::getViewport() const
{
    SDL_Rect rect;
    
    SDL_RenderGetViewport(m_renderer, &rect);
    
    return Rect::fromSDL(rect); 
}
#endif


Renderer& Renderer::setClipRect(const Rect& rect)
{
    if (SDL_RenderSetClipRect(m_renderer, rect.toSDL()) == 0)
        return *this;
    throw SDL::Error(SDL_GetError());
}


#if SDL_VERSION_ATLEAST(2, 0, 5)
Renderer& Renderer::setIntegerScale(bool enable)
{
    SDL_bool e = SDL_FALSE;
    
    if (enable)
        e = SDL_TRUE;
    
    if (SDL_RenderSetIntegerScale(m_renderer, e) != 0)
        throw SDL::Error(SDL_GetError());
    
    return *this;
}
#endif

#if SDL_VERSION_ATLEAST(2, 0, 0)
Renderer& Renderer::setLogicalSize(int w, int h)
{
    if (SDL_RenderSetLogicalSize(m_renderer, w, h) == 0)
        return *this;

    throw SDL::Error(SDL_GetError());
}

Renderer& Renderer::setScale(float scaleX, float scaleY)
{
    if (SDL_RenderSetScale(m_renderer, scaleX, scaleY) == 0)
        return *this;

    throw SDL::Error(SDL_GetError());
}

Renderer& Renderer::setViewport(const Rect& rect)
{
    if (SDL_RenderSetViewport(m_renderer, rect.toSDL()) == 0)
        return *this;            

    throw SDL::Error(SDL_GetError());
}

Renderer& Renderer::setTarget(Texture &texture)
{
    return *this;
}
#endif

// other methods

#if SDL_VERSION_ATLEAST(2, 0, 0)
Renderer& Renderer::clear()
{
    if (SDL_RenderClear(m_renderer) == 0)
        return *this;

    throw SDL::Error(SDL_GetError());
}
#endif

#if SDL_VERSION_ATLEAST(2, 0, 4)
bool Renderer::isClipEnabled() const
{
    return SDL_RenderIsClipEnabled(m_renderer) == SDL_TRUE ? true:false;
}
#endif

Renderer& Renderer::present()
{
    SDL_RenderPresent(m_renderer); 

    return *this;
}

#if SDL_VERSION_ATLEAST(2, 0, 0)
bool Renderer::targetSupported() const
{
    return SDL_RenderTargetSupported(m_renderer) == SDL_TRUE;
}
#endif
