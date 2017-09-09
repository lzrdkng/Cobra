        #ifndef COBRA_HPP
    #define COBRA_HPP

    #include <SDL2/SDL.h>

    #define OPERATOR_OR(TYPE, CAST) \
        inline TYPE operator |(TYPE x, TYPE y) { return static_cast<TYPE>(static_cast<CAST>(x) | static_cast<CAST>(y));}


    namespace SDL
    {

    /** @namespace SDL*/


        enum InitFlags
        {
            InitNull           = 0,                       /**< Equivalent to NULL */
            InitTimer          = SDL_INIT_TIMER,          /**< Timer subsystem */
            InitAudio          = SDL_INIT_AUDIO,          /**< Audio subsystem */
            InitVideo          = SDL_INIT_VIDEO,          /**< Video subsystem. Automatically initializes the vents subsystem */
            InitJoystick       = SDL_INIT_JOYSTICK,       /**< Joystick subsystem. Automatically initializes the vents subsystem */
            InitHaptic         = SDL_INIT_HAPTIC,         /**< Haptic (force feedback) subsystem */
            InitGamecontroller = SDL_INIT_GAMECONTROLLER, /**< Controller subsystem. Automatically initializes the joystick subsystem */
            InitEvents         = SDL_INIT_EVENTS,         /**< Events subsystem */
            InitEverything     = SDL_INIT_EVERYTHING,     /**< All subsystems */
            InitNoparachute    = SDL_INIT_NOPARACHUTE     /** Compatibility. This flag is ignored */
        };

        /**< Flags to initialize subsytems. */


        OPERATOR_OR(InitFlags, Uint32)

        enum WindowFlags
        {
            WindowNull              = 0,
            WindowFullscreen        = SDL_WINDOW_FULLSCREEN,
            WindowFullscreenDesktop = SDL_WINDOW_FULLSCREEN_DESKTOP,
            WindowOpenGL            = SDL_WINDOW_OPENGL,
            WindowShown             = SDL_WINDOW_SHOWN,
            WindowHidden            = SDL_WINDOW_HIDDEN,
            WindowBorderless        = SDL_WINDOW_BORDERLESS,
            WindowResizable         = SDL_WINDOW_RESIZABLE,
            WindowMinimized         = SDL_WINDOW_MINIMIZED,
            WindowMaximized         = SDL_WINDOW_MAXIMIZED,
            WindowInputGrabbed      = SDL_WINDOW_INPUT_GRABBED,
            WindowInputFocus        = SDL_WINDOW_INPUT_FOCUS,
            WindowForeign           = SDL_WINDOW_FOREIGN,
            WindowAllowHighDPI      = SDL_WINDOW_ALLOW_HIGHDPI,
            WindowMouseCapture      = SDL_WINDOW_MOUSE_CAPTURE,
            WindowAlwaysOnTop       = SDL_WINDOW_ALWAYS_ON_TOP,
            WindowSkipTaskbar       = SDL_WINDOW_SKIP_TASKBAR,
            WindowUtility           = SDL_WINDOW_UTILITY,
            WindowTooltip           = SDL_WINDOW_TOOLTIP,
            WindowPopupMenu         = SDL_WINDOW_POPUP_MENU
        };

        OPERATOR_OR(WindowFlags, Uint32)


        enum RendererFlags
        {
            RendererNull          = 0,                          /**< Equivalent to NULL */
            RendererSoftware      = SDL_RENDERER_SOFTWARE,      /**< The renderer is a software fallback */
            RendererAccelerated   = SDL_RENDERER_ACCELERATED,   /**< The renderer uses hardware acceleration */
            RendererPresentVSync  = SDL_RENDERER_PRESENTVSYNC,  /**< Present is synchronized with the refresh rate */
            RendererTargetTexture = SDL_RENDERER_TARGETTEXTURE  /**< The renderer supports rendering texture */

        };

        /**< Flags to create renderer. */

        //OPERATOR_OR(RendererFlags, )

        enum TextureAccess
        {
            TextureAccessNull      = 0,
            TextureAccessStatic    = SDL_TEXTUREACCESS_STATIC,
            TextureAccessStreaming = SDL_TEXTUREACCESS_STREAMING,
            TextureAccessTarget    = SDL_TEXTUREACCESS_TARGET
        };


        enum PixelFormats
        {
            PixelFormatUnknown          = SDL_PIXELFORMAT_UNKNOWN,
            PixelFormatIndex1LSB        = SDL_PIXELFORMAT_INDEX1LSB,
            PixelFormatIndex1MSB        = SDL_PIXELFORMAT_INDEX1MSB,
            PixelFormatIndex4LSB        = SDL_PIXELFORMAT_INDEX4LSB,
            PixelFormatIndex4MSB        = SDL_PIXELFORMAT_INDEX4MSB,
            PixelFormatIndex8           = SDL_PIXELFORMAT_INDEX8,
            PixelFormatIndexRGB332      = SDL_PIXELFORMAT_RGB332,
            PixelFormatIndexRGB444      = SDL_PIXELFORMAT_RGB444,
            PixelFormatIndexRGB555      = SDL_PIXELFORMAT_RGB555,
            PixelFormatIndexBGR555      = SDL_PIXELFORMAT_BGR555,
            PixelFormatIndexARGB4444    = SDL_PIXELFORMAT_ARGB4444,
            PixelFormatIndexRGBA4444    = SDL_PIXELFORMAT_RGBA4444,
            PixelFormatIndexABGR4444    = SDL_PIXELFORMAT_ABGR4444,
            PixelFormatIndexBGRA4444    = SDL_PIXELFORMAT_BGRA4444,
            PixelFormatIndexARGB1555    = SDL_PIXELFORMAT_ARGB1555,
            PixelFormatIndexRGBA5551    = SDL_PIXELFORMAT_RGBA5551,
            PixelFormatIndexABGR1555    = SDL_PIXELFORMAT_ABGR1555,
            PixelFormatIndexBGRA5551    = SDL_PIXELFORMAT_BGRA5551,
            PixelFormatIndexRGB565      = SDL_PIXELFORMAT_RGB565,
            PixelFormatIndexBGR565      = SDL_PIXELFORMAT_BGR565,
            PixelFormatIndexRGB24       = SDL_PIXELFORMAT_RGB24,
            PixelFormatIndexBGR24       = SDL_PIXELFORMAT_BGR24,
            PixelFormatIndexRGB888      = SDL_PIXELFORMAT_RGB888,
            PixelFormatIndexRGBX8888    = SDL_PIXELFORMAT_RGBX8888,
            PixelFormatIndexBGR888      = SDL_PIXELFORMAT_BGR888,
            PixelFormatIndexBGRX8888    = SDL_PIXELFORMAT_BGRX8888,
            PixelFormatIndexARGB8888    = SDL_PIXELFORMAT_ARGB8888,
            PixelFormatIndexRGBA8888    = SDL_PIXELFORMAT_RGBA8888,
            PixelFormatIndexABGR8888    = SDL_PIXELFORMAT_ABGR8888,
            PixelFormatIndexBGRA8888    = SDL_PIXELFORMAT_BGRA8888,
            PixelFormatIndexARGB2101010 = SDL_PIXELFORMAT_ARGB2101010,
            PixelFormatIndexRGBA32      = SDL_PIXELFORMAT_RGBA32,
            PixelFormatIndexARGB32      = SDL_PIXELFORMAT_ARGB32,
            PixelFormatIndexBGRA32      = SDL_PIXELFORMAT_BGRA32,
            PixelFormatIndexABGR32      = SDL_PIXELFORMAT_ABGR32,
            PixelFormatIndexYV12        = SDL_PIXELFORMAT_YV12,
            PixelFormatIndexIYUV        = SDL_PIXELFORMAT_IYUV,
            PixelFormatIndexYUY2        = SDL_PIXELFORMAT_YUY2,
            PixelFormatIndexUYVY        = SDL_PIXELFORMAT_UYVY,
            PixelFormatIndexYVYU        = SDL_PIXELFORMAT_YVYU,
            PixelFormatIndexNV12        = SDL_PIXELFORMAT_NV12,
            PixelFormatIndexNV21        = SDL_PIXELFORMAT_NV21

        };


        enum WindowPositions
        {
            WindowPositionCentered  = SDL_WINDOWPOS_CENTERED,
            WindowPositionUndefined = SDL_WINDOWPOS_UNDEFINED
        };

        enum BlendModes
        {
            BlendModeNone  = SDL_BLENDMODE_NONE,
            /**< No blending. <br>
             * dstRGBA = srcRGBA
             */
            BlendModeBlend = SDL_BLENDMODE_BLEND,
            /**< Alpha blending. <br>
             * dstRGB = (srcRGB * srcA) + (dstRGB * (1-srcA)) <br>
             * dstA = srcA + (dstA * (1-srcA))
             */
            BlendModeAdd   = SDL_BLENDMODE_ADD,
            /**< Additive blending. <br>
             *  dstRGB = (srcRGB * srcA) + dstRGB <br>
             *  dstA = dstA
             */
            BlendModeMod   = SDL_BLENDMODE_MOD,
            /**< Color modulate. <br>
             * dstRGB = srcRGB * dstRGB <br>
             * dstA = dstA
             */
        };
    }

    #endif // SDL_HPP

