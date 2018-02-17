#ifndef COBRA_UTILS_HPP
#define COBRA_UTILS_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 

#include <complex>

#include "Point.hpp"
#include "Error.hpp"

namespace SO
{  
  typedef std::complex<double> Coord;

  template<typename T, typename U=T>
  using Pair = std::pair<T, U>;

  class Color;

/**
 * Allow to OR/AND enum class of type T casted to type S. Useful for
 * flags.
 */
#define __ENUM_CLASS_OR_OVERLOAD__(T, S) inline T operator|(T l, T r)	\
  {return static_cast<T>(static_cast<S>(l) | static_cast<S>(r));}
  
#define __ENUM_CLASS_AND_OVERLOAD__(T, S) inline T operator&(T l, T r)	\
{return static_cast<T>(static_cast<S>(l) & static_cast<S>(r));}

  enum class Init : Uint32
  {
    Null           = 0,
    Timer          = SDL_INIT_TIMER,          /**< Timer subsystem */
    Audio          = SDL_INIT_AUDIO,          /**< Audio subsystem */
    Video          = SDL_INIT_VIDEO,          /**< Video
						 subsystem. Automatically
						 initializes the vents
						 subsystem */
    Joystick       = SDL_INIT_JOYSTICK,       /**< Joystick
						 subsystem. Automatically
						 initializes the vents
						 subsystem */
    Haptic         = SDL_INIT_HAPTIC,         /**< Haptic (force feedback) subsystem */
    Gamecontroller = SDL_INIT_GAMECONTROLLER, /**< Controller
						 subsystem. Automatically
						 initializes the
						 joystick subsystem */
    Events         = SDL_INIT_EVENTS,         /**< Events subsystem */
    Everything     = SDL_INIT_EVERYTHING,     /**< All subsystems */
    Noparachute    = SDL_INIT_NOPARACHUTE     /** Compatibility. This flag is ignored */
  };

  __ENUM_CLASS_OR_OVERLOAD__(Init, Uint32)
  __ENUM_CLASS_AND_OVERLOAD__(Init, Uint32)

  /**< Flags to create renderer. */

  enum class TextureAccess : int
  {
    Null      = 0,
    Static    = SDL_TEXTUREACCESS_STATIC,
    Streaming = SDL_TEXTUREACCESS_STREAMING,
    Target    = SDL_TEXTUREACCESS_TARGET
  };


  enum class PixelFormats : Uint32
  {
    Unknown     = SDL_PIXELFORMAT_UNKNOWN,
    Index1LSB   = SDL_PIXELFORMAT_INDEX1LSB,
    Index1MSB   = SDL_PIXELFORMAT_INDEX1MSB,
    Index4LSB   = SDL_PIXELFORMAT_INDEX4LSB,
    Index4MSB   = SDL_PIXELFORMAT_INDEX4MSB,
    Index8      = SDL_PIXELFORMAT_INDEX8,
    RGB332      = SDL_PIXELFORMAT_RGB332,
    RGB444      = SDL_PIXELFORMAT_RGB444,
    RGB555      = SDL_PIXELFORMAT_RGB555,
    BGR555      = SDL_PIXELFORMAT_BGR555,
    ARGB4444    = SDL_PIXELFORMAT_ARGB4444,
    RGBA4444    = SDL_PIXELFORMAT_RGBA4444,
    ABGR4444    = SDL_PIXELFORMAT_ABGR4444,
    BGRA4444    = SDL_PIXELFORMAT_BGRA4444,
    ARGB1555    = SDL_PIXELFORMAT_ARGB1555,
    RGBA5551    = SDL_PIXELFORMAT_RGBA5551,
    ABGR1555    = SDL_PIXELFORMAT_ABGR1555,
    BGRA5551    = SDL_PIXELFORMAT_BGRA5551,
    RGB565      = SDL_PIXELFORMAT_RGB565,
    BGR565      = SDL_PIXELFORMAT_BGR565,
    RGB24       = SDL_PIXELFORMAT_RGB24,
    BGR24       = SDL_PIXELFORMAT_BGR24,
    RGB888      = SDL_PIXELFORMAT_RGB888,
    RGBX8888    = SDL_PIXELFORMAT_RGBX8888,
    BGR888      = SDL_PIXELFORMAT_BGR888,
    BGRX8888    = SDL_PIXELFORMAT_BGRX8888,
    ARGB8888    = SDL_PIXELFORMAT_ARGB8888,
    RGBA8888    = SDL_PIXELFORMAT_RGBA8888,
    ABGR8888    = SDL_PIXELFORMAT_ABGR8888,
    BGRA8888    = SDL_PIXELFORMAT_BGRA8888,
    ARGB2101010 = SDL_PIXELFORMAT_ARGB2101010,
    RGBA32      = SDL_PIXELFORMAT_RGBA32,
    ARGB32      = SDL_PIXELFORMAT_ARGB32,
    BGRA32      = SDL_PIXELFORMAT_BGRA32,
    ABGR32      = SDL_PIXELFORMAT_ABGR32,
    YV12        = SDL_PIXELFORMAT_YV12,
    IYUV        = SDL_PIXELFORMAT_IYUV,
    YUY2        = SDL_PIXELFORMAT_YUY2,
    UYVY        = SDL_PIXELFORMAT_UYVY,
    YVYU        = SDL_PIXELFORMAT_YVYU,
    NV12        = SDL_PIXELFORMAT_NV12,
    NV21        = SDL_PIXELFORMAT_NV21
  };


  enum class WindowPositions : int
  {
    Centered  = SDL_WINDOWPOS_CENTERED,
    Undefined = SDL_WINDOWPOS_UNDEFINED
  };

  enum class BlendModes : int
  {
    Null  = SDL_BLENDMODE_NONE,         /**< No blending. <br>
					   dstRGBA = srcRGBA */
    Blend = SDL_BLENDMODE_BLEND,        /**< Alpha blending. <br>
					   dstRGB = (srcRGB * srcA)
					   + (dstRGB * (1-srcA))
					   <br> dstA = srcA + (dstA
					   * (1-srcA)) */
    Add   = SDL_BLENDMODE_ADD,          /**< Additive
					   blending. <br> dstRGB =
					   (srcRGB srcA) + dstRGB
					   <br> dstA = dstA */
    Mod   = SDL_BLENDMODE_MOD,         /**< Color modulate. <br>
					  dstRGB = srcRGB * dstRGB
					  <br> dstA = dstA */

  };

#ifdef _SDL_IMAGE_H
  enum class ImageInit : int
  {
    Null = 0,
    JPG  = IMG_INIT_JPG,
    PNG  = IMG_INIT_PNG,
    TIF  = IMG_INIT_TIF
  };
  
  __ENUM_CLASS_OR_OVERLOAD__(ImageInit, Uint32)
  __ENUM_CLASS_AND_OVERLOAD__(ImageInit, Uint32)
#endif

  enum class Flip : int
  {
    Null       = SDL_FLIP_NONE,
    Horizontal = SDL_FLIP_HORIZONTAL,
    Vertical   = SDL_FLIP_VERTICAL
  };

  void init(Init flags);

  /**
   * @brief Return a mask of the specified subsystems initialized.
   * @param flags
   * @return If flags is SO::InitNull it returns a mask of all initiliazed
   * subsystems, otherwise it returns the initialization status of the
   * specified subsystems. The return value does not include
   * SO::InitNoparachute
   * @sa SO::Init
   */
  inline Uint32 wasInit(Init flags)
  {
    return SDL_WasInit(static_cast<Uint32>(flags));
  }

  /**
   * @brief Clean up all initialized subsystems.
   */
  void quit();

#ifdef _SDL_IMAGE_H
  void initImage(ImageInit flags);

  void quitImage();
#endif

  /**
   * @brief Pause the application for a specified number of milliseconds.
   * @param ms the number of milliseconds to delay
   * @remark This method waits a specified number of milliseconds before
   * returning. It waits a least the specified time, but possible longer
   * due to OS scheduling.
   * @sa https://wiki.libsdl.org/SDL_Delay
   */
  inline void delay(Uint32 ms) { SDL_Delay(ms); }

  /**
   * @brief Use this function to set a hint with normal priority.
   * @param name the hint to set; see the list of hints
   * @return True on success, false otherwise.
   * @remark Hints will not be set if there is an existing override
   * hint or environment variable that takes precedence. You can use
   * SO::setHintWithPriority to set the hint with override priority
   * instead.
   */
  inline bool setHint(const char* name, const char* value)
  {
    return static_cast<bool>(SDL_SetHint(name, value));
  }

  inline Coord screenToCartesian(const Point& screenCoord,
				 uint width,
				 uint height,
				 double scale = 1.0,
				 const Coord& offset = {0.0, 0.0})
  {
    
    double x = (screenCoord.getX() - width/2.0)/scale + std::real(offset);
    double y = (height/2.0 - screenCoord.getY())/scale - std::imag(offset);

    return {x, y};
  }

  inline Point cartesianToScreen(const Coord& cartesianCoord,
				 uint width,
				 uint height,
				 double scale = 1.0,
				 const Coord& offset = {0.0, 0.0})
  {
    
    Coord screenCoord {std::real(cartesianCoord), -std::imag(cartesianCoord)};

    double x = scale*(std::real(cartesianCoord) - std::real(offset)) + width/2.0;
    double y = -scale*(std::imag(cartesianCoord) + std::imag(offset)) + height/2.0;
    
    return {static_cast<int>(std::round(x)), static_cast<int>(std::round(y))};	
  }

}


#endif // COBRA_UTILS_HPP
