#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "Utils.hpp"
#include "Rect.hpp"
#include "Error.hpp"

#include <utility>

namespace SDLO
{

  class Surface
  {
  public:


    Surface& operator =(const Surface& orig) = delete;
    Surface& operator =(Surface&& move)      = delete;

    Surface(const Surface& orig) = delete;
    Surface(Surface&& move)      = delete;


    explicit Surface(SDL_Surface* surface);

    Surface(const char* path, const Surface* const stretch = nullptr);

    virtual ~Surface();


    /**
     * @brief Return a wrapped SDL_Rect structure used to clip blits to the surface which can be set by SDLO::Surface::setClipRect().
     * @return SDLO::Rect
     */
    Rect getClipRect() const;

    /**
     * @brief Return the format of the pixels stored in the surface.
     * @return SDLO::PixelFormats
     */

    //PixelFormat getFormat() const;

    /**
     * @brief Return the length of a row of pixels in bytes.
     * @return int
     */
    int getPitch() const;

    /**
     * @brief Return the width and height in pixels of the surface.
     * @return std::pair<int>
     */
    std::pair<int, int> getSize() const;



    // other methods

    /**
     * @brief Use this method to perform a fast surface copy to a destination surface.
     * @param srcRect the area to be copied.
     * @param dst the surface destination.
     * @param dstRect the area to be paste on.
     * @return SDLO::Surface&
     * @throw SDLO::Error on failure.
     * @remark This method should not be called on a locked surface.
     * The width and height in srcRect determine the size of the copied rectangle.
     * Only the position is used in the destRect (the width and height are ignored).
     * Blits with negative dstRect coordinates will be clipped properly. The final
     * blit rectangle is saved in dstRect after all clipping is performed (srcRect
     * is not modified).
     */
    Surface& blit(const Rect& srcRect, Surface& dst, Rect& dstRect);

    /**
     * @brief Use this method to perform a total fast surface copy to a destination surface.
     * @param dst the surface destination
     * @param dstRect the are to be paste on.
     * @return SDLO::Surface&
     * @throw SDLO::Error on failure.
     */
    Surface& blit(Surface& dst, Rect& dstRect);

    Surface& blit(const Rect& srcRect, Surface& dst);

    Surface& blit(Surface& dst);


    /**
     * @brief Use this method to perfom a scaled surface copy to a destination surface.
     * @param srcRect
     * @param dst
     * @param dstRect
     * @return SDLO::Surface&
     * @throw SDLO::Error on failure.
     */
    Surface& blitScaled(const Rect& srcRect, Surface& dst, Rect& dstRect);

    Surface& blitScaled(Surface& dst, Rect& dstRect);

    Surface& blitScaled(const Rect& srcRect, Surface& dst);

    Surface& blitScaled(Surface& dst);

    /**
     * @brief Use this method to perform a fast fill of a rectangle with a
     * specified color.
     *
     * @param rect the rectangle to fill
     * @param color the color to fill with
     * @return SDLO::Surface&
     * @throw SDLO::Error on failure.
     */
    Surface& fillRect(const Rect& rect, Uint32 color);

    Surface& fillRect(Uint32 color);

    Surface& loadBMP(const char* path);

    /**
     * @brief Return the C pointer of the wrapped SDL_Surface.
     * @return SDL_Surface*
     * @warning Use with caution.
     */
    const SDL_Surface* toSDL() const;

    SDL_Surface* toSDL();


  protected:

    SDL_Surface* m_surface; // wrapped object

    void free();

  };

}

#endif // SURFACE_HPP
