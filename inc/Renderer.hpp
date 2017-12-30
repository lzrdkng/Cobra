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

#include <vector>
#include <utility>

#include "Utils.hpp"
#include "Error.hpp"

#include "Rect.hpp"
#include "Color.hpp"
#include "Texture.hpp"
#include "Window.hpp"


namespace SDLO
{

  /**
   * @brief Wrapper class for **SDL_Renderer**.
   *
   * **SDL 2.0.0**
   */

  class Renderer
  {
  public:
    

    // constructors/destructor

    /**
     * @brief Explicit constructor for Class SDLO::Renderer.
     *
     * Create a 2D rendering context for a SDLO::Window.
     *
     * @param window the window where rendering is displayed
     * @param flags SDLO::RendererFlags
     * @param index the index of the rendering driver to initiliaze,
     * or -1 to initialize the first one supporting the requested flags
     * @throw SDLO::Error if there was an error
     * @sa SDLO::Renderer:~Renderer
     */
    explicit Renderer(Window& window,
                      RendererFlags flags = RendererNull,
                      int index = -1);


    // rules of five
    Renderer(const Renderer& orig)             = delete;
    Renderer(Renderer&& orig)                  = delete;
    Renderer& operator =(const Renderer& orig) = delete;
    Renderer& operator =(Renderer&& orig)      = delete;


    /**
     * @brief Destructor of class SDLO::Renderer
     * Will call **SDL_DestroyRenderer**
     *
     * @sa SDLO::Renderer::Renderer
     */
    virtual ~Renderer();
    

    // get methods
    
    /**
     * @brief Return a clip rectangle of the renderer.
     * @return SDLO::Rect
     * @sa SDLO::Renderer::setClipRect
     * @sa SDLO::Renderer::isClipEnabled
     */
    Rect getClipRect() const;


    /**
     * @brief Return the current blend mode of the renderer
     * @return SDLO::BlendModes
     * @throw SDLO::Error on failure
     * @sa SDLO::Renderer::setDrawBlendMode
     */
    BlendModes getDrawBlendMode() const;


    /**
     * @brief Return the color used for drawing operations (Rect, Line and Clear).
     * @return SDLO::Color
     * @throw SDLO::Error on failure
     * @sa SDLO::Renderer::setDrawColor
     */
    Color getDrawColor() const;


    /**
     * @brief Return informations about the renderer.
     * @return SDLO::RendererInfo
     * @throw SDLO::Error on failure
     */
    bool getInfo(SDL_RendererInfo& info) const;


#if SDL_VERSION_ATLEAST(2, 0, 5)
    /**
     * @brief Return wheter integer scales are forced for resolution-independent rendering.
     * @return bool
     * @version **SDL2.0.5**
     * @sa SDLO::Renderer::setIntegerScale
     */
    bool getIntegerScale() const;
#endif


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Return the device independent resolution for rendering.
     * @return std::pair<int, int>
     * @remark If called on Renderer who never had its logical size set by
     * Renderer::setLogicalSize(),
     * the std::pair<int, int> returned will be **0, 0**.
     * @version **SDL2.0.0**
     */
    Pair<int> getLogicalSize() const;


    /**
     * @brief Return the output size in pixels of the renderer.
     * @return std::pair<int, int>
     * @throw sdl::runtime_error on failure
     * @version **SDL2.0.0**
     * @sa SDLO::Window::getRenderer
     */
    Pair<int> getOutputSize() const;


    /**
     * @brief Return the renderer's drawing scale.
     * @return SDLO::Pair<float>
     * @version **SDL2.0.0**
     * @sa SDLO::Renderer::setScale
     */
    Pair<float> getScale() const;
#endif

    /**
     * @brief Return the current renderer's target.
     * @return SDL_Texture*
     * @note Return NULL for the default renderer's target
     * @warning Use with caution.
     */
    SDL_Texture* getTarget() const;


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Return the renderer's drawing area.
     * @return SDLO::Rect
     * @version **SDL2.0.0**
     * @sa SDLO::Renderer::setViewport
     */
    Rect getViewport() const;
#endif


    /**
     * @brief Set the clip rectangle for the renderer's target.
     * @param rect The clip area
     * @return SDLO::Renderer&
     * @throw SDLO::Error on falure
     * @sa SDLO::Renderer::getClipRect
     * @sa SDLO::Renderer::isClipEnabled
     */
    Renderer& setClipRect(const Rect& rect);


    /**
     * @brief Set the color for drawing operation.
     * @param c the color
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure.
     */
    Renderer& setDrawColor(Color color);


#if SDL_VERSION_ATLEAST(2, 0, 5)
    /**
     * @brief Set wheter to force integer scale for resolution-independent rendering.
     * @param enable
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure
     * @note This method restrict the logical viewport to integer values -
     * that is, when a resolution is between two multiples of a logical size,
     * the viewport size is rounded down to the lower multiple.
     * @version **SDL2.0.5**
     * @sa SDLO::Renderer::getIntegerScale
     * @sa SDLO::Renderer::setLogicalSize
     */
    Renderer& setIntegerScale(bool enable);
#endif


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Set the renderer resolution.
     * @param w
     * @param h
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure
     * @version **SDL2.0.0**
     * @sa SDLO::Renderer::getLogicalSize
     */
    Renderer& setLogicalSize(int w, int h);


    /**
     * @brief Set the renderer's drawing scale.
     * @param scaleX
     * @param scaleY
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure
     * @note The drawing coordinates are scaled by the x/y scaling factors before they are
     * used by the renderer. This allows resolution independent drawing with a single
     *  coordinate system. <br> If this results in scaling or subpixel drawing by the
     *  rendering backend, it will be handled using the appropriate quality hints. For best
     *  results use integer scaling factors.
     * @version **SDL2.0.0**
     * @sa SDLO::Renderer::getScale
     * @sa SDLO::Renderer::setLogicalSize
     */
    Renderer& setScale(float scaleX, float scaleY);


    /**
     * @brief Set a texture as the current rendering target.
     * @param texture the targeted texture, which must be created with the SDLO::TextureAccessTarget
     * flag, or NULL for the default render target
     * @return bool
     * @throw SDLO::Error on failure
     * @version **SDL2.0.0**
     */
    bool setTarget(Texture& texture);
#endif

    /**
     * @brief Set the renderer's drawing area.
     * @param rect
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure
     * @note When the window is resized, the current viewport is automatically centered
     * within the new window size.
     * @sa SDLO::Renderer::getViewport
     */
    Renderer& setViewport(const Rect& rect);
    
    
    // other methods


    Renderer& drawCircle(int x0, int y0, int r);

    Renderer& fillCircle(int x0, int y0, int r);
 
    /**
     * @brief Draw a line on the renderer.
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure
     */
    Renderer& drawLine(int x1, int y1, int x2, int y2);

    Renderer& drawLine(const Point& p, const Point& q);

    Renderer& drawLine(const Pair<Point>& points);

    Renderer& drawLines(const std::vector<Point>& points);

    Renderer& drawPoint(int x, int y);

    Renderer& drawPoint(const Point& p);

    Renderer& drawPoints(const std::vector<Point>& points);

    Renderer& drawRect(const Rect& rect);

    Renderer& drawRects(const std::vector<Rect>& rects);

    Renderer& fillRect(const Rect& rect);

    Renderer& fillRects(const std::vector<Rect>& rects);


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Clear the renderer with its drawing color.
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure
     * @note This method clears the entire renderer, ignoring the viewport
     * and the clip rectangle.
     * @version **SDL2.0.0**
     * @sa SDLO::Renderer::setDrawColor
     */
    Renderer& clear();
#endif

#if SDL_VERSION_ATLEAST(2, 0, 4)
    /**
     * @brief Return wheter clipping is enable on the renderer.
     * @return bool
     * @version **SDL2.0.4**
     * @sa SDLO::Renderer::getClipRect
     * @sa SDLO::Renderer::setClipRect
     */
    bool isClipEnabled() const;
#endif


    /**
     * @brief Update the renderer with any rendering perfomed since the previous call.
     * @return SDLO::Renderer&
     * @note SDL's rendering functions operate on a backbuffer; that is,
     * calling a rendering method such as SDLO::Renderer::drawLine() does not
     * directly put a line on the screen, but rather updates the backbuffer.
     * As such, you compose your entire scene and present the composed
     * backbuffer to the screen as a complete picture. <br> Therefore, when
     * using SDL's rendering API, one does all drawing intended for the frame,
     * and then calls this function once per frame to present the final drawing
     * to the user. <br> The backbuffer should be considered invalidated after
     * each present; do not assume that previous contents will exist between
     * frames. You are strongly encouraged to call SDLO::Render::clear() to
     * initialize the backbuffer before starting each new frame's drawing,
     * even if you plan to overwrite every pixel.
     * @sa SDLO::Renderer::clear
     * @sa SDLO::Renderer::drawLine
     * @sa SDLO::Renderer::drawLines
     * @sa SDLO::Renderer::drawPoint
     * @sa SDLO::Renderer::drawPoints
     * @sa SDLO::Renderer::drawRect
     * @sa SDLO::Renderer::drawRects
     * @sa SDLO::Renderer::fillRect
     * @sa SDLO::Renderer::fillRects
     * @sa SDLO::Renderer::setDrawBlendMode
     * @sa SDLO::Renderer::setDrawColor
     */
    Renderer& present();

    /**
     * @brief Read pixels from the renderer.
     * @param rect the area to read
     * @param format the desired format of the pixel data
     * @param pixels pointer filled with the pixel data
     * @param pitch the pitch of the pixels parameter
     * @return SDLO::Renderer&
     * @throw SDLO::Error on failure
     * @remark This is a very slow operation, and should not be used frequently.
     */
    Renderer& readPixels(const Rect& rect, PixelFormats format, void* pixels, int pitch); // Need to be change in the future


#if SDL_VERSION_ATLEAST(2, 0, 0)
    /**
     * @brief Return wheter the renderer supports the use of render targets.
     * @return bool
     * @version **SDL2.0.0**
     * @sa SDLO::Renderer::setTarget
     */
    bool targetSupported() const;
#endif
    
    /**
     * @brief Return the constant wrapped SDL_Renderer.
     * @return const SDL_Renderer*
     * @warning Uses with caution.
     */
    const SDL_Renderer* toSDL() const;


    /**
     * @brief Return the wrapped SDL_Renderer.
     * @return SDL_Renderer*
     * @warning Uses with **extreme** caution.
     */
    SDL_Renderer* toSDL();

  private:

    SDL_Renderer* m_renderer; // wrapped object

  };

}

#endif /* RENDERER_HPP */

