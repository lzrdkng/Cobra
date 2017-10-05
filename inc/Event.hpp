#ifndef EVENT_HPP
#define EVENT_HPP

#include "SDL.hpp"

namespace SDL
{

class Event
{
public:

    explicit Event();

    Event(const Event& orig);

    Event& operator =(const Event& orig);

    Event(Event&& move)             = delete;
    Event& operator =(Event&& move) = delete;

    virtual ~Event();




private:

    SDL_Event m_event;
};

}

#endif // EVENT_HPP
