#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "SDL.hpp"

namespace SDL
{

class Application
{
public:

    static void init(SDL::InitFlags flags);

    /**
     * @brief Pause the application for a specified number of milliseconds.
     * @param ms the number of milliseconds to delay
     * @remark This method waits a specified number of milliseconds before
     * returning. It waits a least the specified time, but possible longer
     * due to OS scheduling.
     * @sa https://wiki.libsdl.org/SDL_Delay
     */
    static void delay(Uint32 ms);

    Application(const Application& orig)             = delete;
    Application(Application&& move)                  = delete;
    Application& operator =(const Application& orig) = delete;
    Application& operator =(Application&& move)      = delete;

    virtual ~Application();

private:

    explicit Application() {}

};

}


#endif // APPLICATION_HPP
