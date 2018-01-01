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

namespace SO
{

  // constructors/destructor

  Renderer::Renderer(Window& window, Render flags, int index)
    : m_renderer(nullptr)
  {
    m_renderer = SDL_CreateRenderer(window.toSDL(), index, (Uint32)flags);

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
    SDL_Rect rect;

    SDL_RenderGetClipRect(m_renderer, &rect);

    return rect;
  }

  BlendModes Renderer::getDrawBlendMode() const
  {
    SDL_BlendMode blendMode;

    if (SDL_GetRenderDrawBlendMode(m_renderer, &blendMode) == 0)
      throw Error(SDL_GetError());
    
    return static_cast<BlendModes>(blendMode);
  }

  Color Renderer::getDrawColor() const
  {
    Uint8 r, g, b, a;

    if (SDL_GetRenderDrawColor(m_renderer, &r, &g, &b, &a) != 0)
      throw Error(SDL_GetError());

    return {r, g, b, a};
  }

  bool Renderer::getInfo(SDL_RendererInfo& info) const
  {
    return SDL_GetRendererInfo(m_renderer, &info) == 0;
  }


#if SDL_VERSION_ATLEAST(2, 0, 5)
  bool Renderer::getIntegerScale() const
  {
    return static_cast<bool>(SDL_RenderGetIntegerScale(m_renderer));
  }
#endif
#if SDL_VERSION_ATLEAST(2, 0, 0)
  Pair<int> Renderer::getLogicalSize() const
  {
    int w, h;

    SDL_RenderGetLogicalSize(m_renderer, &w, &h);

    return {w, h};
  }

  Pair<int> Renderer::getOutputSize() const
  {
    int w, h;

    if (SDL_GetRendererOutputSize(m_renderer, &w, &h) != 0)
      throw SO::Error(SDL_GetError());

    return {w, h};
  }

  Pair<float> Renderer::getScale() const
  {
    float x, y;

    SDL_RenderGetScale(m_renderer, &x, &y);

    return {x , y};
  }
#endif

  SDL_Texture* Renderer::getTarget() const
  {
    return SDL_GetRenderTarget(m_renderer);
  }

#if SDL_VERSION_ATLEAST(2, 0, 0)
  Rect Renderer::getViewport() const
  {
    SDL_Rect rect;
    
    SDL_RenderGetViewport(m_renderer, &rect);
    
    return {rect};
  }
#endif

  Renderer& Renderer::setClipRect(const Rect& rect)
  {
    if (SDL_RenderSetClipRect(m_renderer, (const SDL_Rect*)&rect) != 0)
      throw Error(SDL_GetError());

    return *this;
  }

  Renderer& Renderer::setDrawColor(Color color)
  {
    if (SDL_SetRenderDrawColor(m_renderer,
                               color.getRed(),
                               color.getGreen(),
                               color.getBlue(),
                               color.getAlpha()) != 0) throw Error(SDL_GetError());
    return *this;
  }


#if SDL_VERSION_ATLEAST(2, 0, 5)
  Renderer& Renderer::setIntegerScale(bool enable)
  {
    if (SDL_RenderSetIntegerScale(m_renderer, static_cast<SDL_bool>(enable)) != 0)
      throw Error(SDL_GetError());
    
    return *this;
  }
#endif

#if SDL_VERSION_ATLEAST(2, 0, 0)
  Renderer& Renderer::setLogicalSize(int w, int h)
  {
    if (SDL_RenderSetLogicalSize(m_renderer, w, h) != 0)
      throw Error(SDL_GetError());

    return *this;
  }

  Renderer& Renderer::setScale(float scaleX, float scaleY)
  {
    if (SDL_RenderSetScale(m_renderer, scaleX, scaleY) != 0)
      throw Error(SDL_GetError());

    return *this;
  }

  Renderer& Renderer::setViewport(const Rect& rect)
  {
    if (SDL_RenderSetViewport(m_renderer, (const SDL_Rect*)&rect) != 0)
      throw Error(SDL_GetError());

    return *this;
  }

  bool Renderer::setTarget(Texture& texture)
  {
    SDL_RendererInfo info;

    if (this->getInfo(info) == 0)
    {
      if (info.flags & (Uint32)Render::TargetTexture)
	if (SDL_SetRenderTarget(m_renderer, texture.toSDL()) != 0)
	  throw Error(SDL_GetError());
      return true;
    }

    return false;
  }
#endif


// other methods

#if SDL_VERSION_ATLEAST(2, 0, 0)
  Renderer& Renderer::clear()
  {
    if (SDL_RenderClear(m_renderer) != 0)
      throw Error(SDL_GetError());

    return *this;
  }
#endif

#if SDL_VERSION_ATLEAST(2, 0, 4)
  bool Renderer::isClipEnabled() const
  {
    return static_cast<bool>(SDL_RenderIsClipEnabled(m_renderer));
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
    return static_cast<bool>(SDL_RenderTargetSupported(m_renderer));
  }
#endif

  Renderer& Renderer::drawCircle(int x0, int y0, int r)
  {
    // Midpoint circle
    // see : https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
    
    int x = r - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int e = dx - (r << 1);

    while (x >= y)
    {
      this->drawPoint(x0 + x, y0 + y);
      this->drawPoint(x0 - x, y0 + y);
      this->drawPoint(x0 + y, y0 + x);
      this->drawPoint(x0 - y, y0 + x);
      this->drawPoint(x0 - x, y0 - y);
      this->drawPoint(x0 + x, y0 - y);
      this->drawPoint(x0 - y, y0 - x);
      this->drawPoint(x0 + y, y0 - x);

      if (e <= 0)
      {
	y++;
	e += dy;
	dy += 2;
      }

      if (e > 0)
      {
	x--;
	dx += 2;
	e += (-r << 1) + dx;
      }
    }

    return *this;
  }
  
  Renderer& Renderer::fillCircle(int x0, int y0, int r)
  {
    int x  = r - 1;
    int y  = 0;
    int dx = 1;
    int dy = 1;
    int e  = dx - (r << 1);

    while (x >= y)
    {
      this->drawLine(x0 + x, y0 + y, x0 - x, y0 + y);
      this->drawLine(x0 + y, y0 + x, x0 - y, y0 + x);
      this->drawLine(x0 - x, y0 - y, x0 + x, y0 - y);
      this->drawLine(x0 - y, y0 - x, x0 + y, y0 - x);

      if (e <= 0)
      {
	y++;
	e += dy;
	dy += 2;
      }

      if (e >0)
      {
	x--;
	dx += 2;
	e += (-r << 1) + dx;
      }
    }

    return *this;
  }

  Renderer& Renderer::drawLine(int x1, int y1, int x2, int y2)
  {
    if (SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2) != 0)
      throw SO::Error(SDL_GetError());

    return *this;
  }

  Renderer& Renderer::drawLine(const Point& p, const Point& q)
  {
    return this->drawLine(p.getX(), p.getY(), q.getX(), q.getY());
  }

  Renderer& Renderer::drawLine(const Pair<Point>& points)
  {
    return this->drawLine(points.first, points.second);
  }

  Renderer& Renderer::drawLines(const std::vector<Point>& points)
  {

    if (SDL_RenderDrawLines(m_renderer, (const SDL_Point*)&points[0], points.size()) != 0)
      throw Error(SDL_GetError());
      
    return *this;
  }

  Renderer& Renderer::drawPoint(int x, int y)
  {
    if (SDL_RenderDrawPoint(m_renderer, x, y) != 0)
      throw SO::Error(SDL_GetError());

    return *this;
  }

  Renderer& Renderer::drawPoint(const Point& p)
  {
    return this->drawPoint(p.getX(), p.getY());
  }

  Renderer& Renderer::drawPoints(const std::vector<Point>& points)
  {

    if (SDL_RenderDrawPoints(m_renderer,
			     (const SDL_Point*)&points[0],
			     points.size()) != 0)
      throw Error(SDL_GetError());
    
    return *this;
  }

  Renderer& Renderer::drawRect(const Rect& rect)
  {
    if (SDL_RenderDrawRect(m_renderer, (const SDL_Rect*)&rect) != 0)
      throw SO::Error(SDL_GetError());

    return *this;
  }

  Renderer& Renderer::drawRects(const std::vector<Rect>& rects)
  {
    if (SDL_RenderDrawRects(m_renderer,
			    (const SDL_Rect*)&rects[0],
			    rects.size()) != 0)
      throw Error(SDL_GetError());
    
    return *this;
  }

  Renderer& Renderer::fillRect(const Rect& rect)
  {
    if (SDL_RenderFillRect(m_renderer, (const SDL_Rect*)&rect) != 0)
      throw SO::Error(SDL_GetError());

    return *this;
  }

  Renderer& Renderer::fillRects(const std::vector<Rect>& rects)
  {
    if (SDL_RenderFillRects(m_renderer,
			    (const SDL_Rect*)&rects[0],
			    rects.size()) != 0)
      throw Error(SDL_GetError());
    
    return *this;
  }

  Renderer& Renderer::readPixels(const Rect& rect, PixelFormats format, void* pixels, int pitch)
  {
    if (SDL_RenderReadPixels(m_renderer,
			     (const SDL_Rect*)&rect,
			     (Uint32)format,
			     pixels, pitch) != 0)
      throw SO::Error(SDL_GetError());

    return *this;
  }

  const SDL_Renderer* Renderer::toSDL() const
  {
    return m_renderer;
  }

  SDL_Renderer* Renderer::toSDL()
  {
    return m_renderer;
  }

}
