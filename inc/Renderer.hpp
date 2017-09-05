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
 * File:   Renderer.hpp
 * Author: olivier
 *
 * Created on August 12, 2017, 9:01 PM
 */

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "SDL.hpp"
#include "Error.hpp"

#include "Rect.hpp"
#include "Color.hpp"
#include "Object.hpp"
#include "Pair.hpp"
#include "Window.hpp"
#include "Texture.hpp"


namespace SDL
{

/**
 * @brief Wrapper class for **SDL_Renderer**.
 *
 * **SDL 2.0.0**
 */

class Renderer : public Object
{
public:
    

    // constructors/destructor

    /**
     * @brief Explicit constructor for Class SDL::Renderer.
     *
     * Create a 2D rendering context for a SDL::Window.
     *
     * @param window the window where rendering is displayed
     * @param flags SDL::RendererFlags
     * @param index the index of the rendering driver to initiliaze,
     * or -1 to initialize the first one supporting the requested flags
     * @throw SDL::Error if there was an error
     * @sa SDL::Renderer:~Renderer
     */
    explicit Renderer(Window& window,
                      SDL::RendererFlags flags = SDL::RendererNull,
                      int index = -1);


    // rules of five
    Renderer(const Renderer& orig)             = delete;
    Renderer(Renderer&& orig)                  = delete;
    Renderer& operator =(const Renderer& orig) = delete;
    Renderer& operator =(Renderer&& orig)      = delete;


    /**
     * @brief Destructor of class SDL::Renderer
     * Will call **SDL_DestroyRenderer**
     *
     * @sa SDL::Renderer::Renderer
     */
    virtual ~Renderer();
    

    // get methods
    
    /**
     * @brief Return a clip rectangle of the renderer.
     * @return SDL::Rect
     * @sa SDL::Renderer::setClipRect
     * @sa SDL::Renderer::isClipEnabled
     */
    Rect getClipRect() const;


    /**
     * @brief Return the current blend mode of the renderer
     * @return SDL::BlendModes
     * @throw SDL::Error on failure
     * @sa SDL::Renderer::setDrawBlendMode
     */
    BlendModes getDrawBlendMode() const;


    /**
     * @brief Return the color used for drawing operations (Rect, Line and Clear).
     * @return SDL::Color
     * @throw SDL::Error on failure
     * @sa SDL::Renderer::setDrawColor
     */
    Color getDrawColor() const;


    /**
     * @brief Return informations about the renderer.
     * @return SDL::RendererInfo
     * @throw SDL::Error on failure
     */
    bool getInfo(SDL_RendererInfo& info) const;


#if SDL_VERSION_ATLEAST(2, 0, 5)
    /**
     * @brief Return wheter integer scales are forced for resolution-independent rendering.
     * @return bool
     * @version **SDL2.0.5**
     * @sa SDL::Renderer::setIntegerScale
     */
    bool getIntegerScale() const;
#endif


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Return the device independent resolution for rendering.
     * @return SDL::Pair<int>
     * @remark If called on Renderer who never had its logical size set by
     * Renderer::setLogicalSize(),
     * the SDL::Pair<int> returned will be **0, 0**.
     * @version **SDL2.0.0**
     */
    Pair<int> getLogicalSize() const;


    /**
     * @brief Return the output size in pixels of the renderer.
     * @return SDL::Pair<int>
     * @throw sdl::runtime_error on failure
     * @version **SDL2.0.0**
     * @sa SDL::Window::getRenderer
     */
    Pair<int> getOutputSize() const;


    /**
      * @brief Return the renderer's drawing scale.
      * @return SDL::Pair<float>
      * @version **SDL2.0.0**
      * @sa SDL::Renderer::setScale
      */
    Pair<float> getScale() const;
#endif

    /**
     * @brief Return the current renderer's target.
     * @return SDL_Texture*
     * @note Return NULL for the default renderer's target
     * @warning Use with caution
     */
    SDL_Texture* getTarget() const;


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Return the renderer's drawing area.
     * @return SDL::Rect
     * @version **SDL2.0.0**
     * @sa SDL::Renderer::setViewport
     */
    Rect getViewport() const;
#endif
    
    
    /**
     * @brief Set the clip rectangle for the renderer's target.
     * @param rect The clip area
     * @return SDL::Renderer&
     * @throw SDL::Error on failure
     * @sa SDL::Renderer::getClipRect
     * @sa SDL::Renderer::isClipEnabled
     */
    Renderer& setClipRect(const Rect& rect);

#if SDL_VERSION_ATLEAST(2, 0, 5)
    /**
     * @brief Set wheter to force integer scale for resolution-independent rendering.
     * @param enable
     * @return SDL::Renderer&
     * @throw SDL::Error on failure
     * @note This method restrict the logical viewport to integer values -
     * that is, when a resolution is between two multiples of a logical size,
     * the viewport size is rounded down to the lower multiple.
     * @version **SDL2.0.5**
     * @sa SDL::Renderer::getIntegerScale
     * @sa SDL::Renderer::setLogicalSize
     */
    Renderer& setIntegerScale(bool enable);
#endif


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Set the renderer resolution.
     * @param w
     * @param h
     * @return SDL::Renderer&
     * @throw SDL::Error on failure
     * @version **SDL2.0.0**
     * @sa SDL::Renderer::getLogicalSize
     */
    Renderer& setLogicalSize(int w, int h);


    /**
     * @brief Set the renderer's drawing scale.
     * @param scaleX
     * @param scaleY
     * @return SDL::Renderer&
     * @throw SDL::Error on failure
     * @note The drawing coordinates are scaled by the x/y scaling factors before they are
     * used by the renderer. This allows resolution independent drawing with a single
     *  coordinate system. <br> If this results in scaling or subpixel drawing by the
     *  rendering backend, it will be handled using the appropriate quality hints. For best
     *  results use integer scaling factors.
     * @version **SDL2.0.0**
     * @sa SDL::Renderer::getScale
     * @sa SDL::Renderer::setLogicalSize
     */
    Renderer& setScale(float scaleX, float scaleY);


    /**
     * @brief Set
     * @param texture
     * @return
     * @version **SDL2.0.0**
     */
    Renderer& setTarget(Texture& texture);
#endif

    /**
     * @brief Set the renderer's drawing area.
     * @param rect
     * @return SDL::Renderer&
     * @throw SDL::Error on failure
     * @note When the window is resized, the current viewport is automatically centered
     * within the new window size.
     * @sa SDL::Renderer::getViewport
     */
    Renderer& setViewport(const Rect& rect);
    
    
    // other methods
    
    /**
     * @brief Draw a line on the renderer.
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return SDL::Renderer&
     * @throw SDL::Error on failure
     */
    Renderer& drawLine(int x1, int y1, int x2, int y2);

//    Renderer& drawLines(const CPoint* points, int count);

    Renderer& drawPoint(int x, int y);

  //  Renderer& drawPoints(const CPoint* points, int count);

    Renderer& drawRect(const CRect& rect);

   // Renderer& drawRects(const CRect* rects, int count);

    Renderer& fillRect(const CRect& rect);

    //Renderer& fillRects(const CRect* rects, int count);


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Clear the renderer with its drawing color.
     * @return SDL::Renderer&
     * @throw SDL::Error on failure
     * @note This method clears the entire renderer, ignoring the viewport
     * and the clip rectangle.
     * @version **SDL2.0.0**
     * @sa SDL::Renderer::setDrawColor
     */
    Renderer& clear();
#endif

#if SDL_VERSION_ATLEAST(2, 0, 4)
    /**
     * @brief Return wheter clipping is enable on the renderer.
     * @return bool
     * @version **SDL2.0.4**
     * @sa SDL::Renderer::getClipRect
     * @sa SDL::Renderer::setClipRect
     */
    bool isClipEnabled() const;
#endif


    /**
     * @brief Update the renderer with any rendering perfomed since the previous call.
     * @return SDL::Renderer&
     * @note SDL's rendering functions operate on a backbuffer; that is,
     * calling a rendering method such as SDL::Renderer::drawLine() does not
     * directly put a line on the screen, but rather updates the backbuffer.
     * As such, you compose your entire scene and present the composed
     * backbuffer to the screen as a complete picture. <br> Therefore, when
     * using SDL's rendering API, one does all drawing intended for the frame,
     * and then calls this function once per frame to present the final drawing
     * to the user. <br> The backbuffer should be considered invalidated after
     * each present; do not assume that previous contents will exist between
     * frames. You are strongly encouraged to call SDL::Render::clear() to
     * initialize the backbuffer before starting each new frame's drawing,
     * even if you plan to overwrite every pixel.
     * @sa SDL::Renderer::clear
     * @sa SDL::Renderer::drawLine
     * @sa SDL::Renderer::drawLines
     * @sa SDL::Renderer::drawPoint
     * @sa SDL::Renderer::drawPoints
     * @sa SDL::Renderer::drawRect
     * @sa SDL::Renderer::drawRects
     * @sa SDL::Renderer::fillRect
     * @sa SDL::Renderer::fillRects
     * @sa SDL::Renderer::setDrawBlendMode
     * @sa SDL::Renderer::setDrawColor
     */
    Renderer& present();


  //bool      readPixels(const SDL_Rect& rect, Uint32 format)


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Return wheter the renderer supports the use of render targets.
     * @return bool
     * @version **SDL2.0.0**
     * @sa SDL::Renderer::setTarget
     */
    bool      targetSupported() const;
#endif
    

    virtual void paintEvent()
    {
        this->clear();
        this->present();
    }

private:

    SDL_Renderer* m_renderer; // wrapped object

};

}

#endif /* RENDERER_HPP */

