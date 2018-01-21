#ifndef SO_EVENT_HPP
#define SO_EVENT_HPP

#include <SDL2/SDL_events.h>
#include "Error.hpp"

namespace SO
{
  class CommonEvent : public SDL_CommonEvent {};  
  class WindowEvent : public SDL_WindowEvent{};  
  class KeyboardEvent : public SDL_KeyboardEvent {};  
  class TextEditingEvent : public SDL_TextEditingEvent {};  
  class TextInputEvent : public SDL_TextInputEvent {};  
  class MouseMotionEvent : public SDL_MouseMotionEvent {};
  class MouseButtonEvent : public SDL_MouseButtonEvent {};    
  class MouseWheelEvent : public SDL_MouseWheelEvent {};     
  class JoyAxisEvent : public SDL_JoyAxisEvent {};         
  class JoyBallEvent : public SDL_JoyBallEvent {};         
  class JoyHatEvent : public SDL_JoyHatEvent {};           
  class JoyButtonEvent : public SDL_JoyButtonEvent {};     
  class JoyDeviceEvent : public SDL_JoyDeviceEvent {};     
  class ControllerAxisEvent : public SDL_ControllerAxisEvent {};      
  class ControllerButtonEvent : public SDL_ControllerButtonEvent {};  
  class ControllerDeviceEvent : public SDL_ControllerDeviceEvent {};  
  class AudioDeviceEvent : public SDL_AudioDeviceEvent {};   
  class QuitEvent : public SDL_QuitEvent {};             
  class UserEvent : public SDL_UserEvent {};             
  class SysWMEvent : public SDL_SysWMEvent {};           
  class TouchFingerEvent : public SDL_TouchFingerEvent {};   
  class MultiGestureEvent : public SDL_MultiGestureEvent {}; 
  class DollarGestureEvent : public SDL_DollarGestureEvent {}; 
  class DropEvent : public SDL_DropEvent {};             

  typedef union Event
  {
    Uint32 type;                /**< Event type, shared with all events */
    CommonEvent common;         /**< Common event data */
    WindowEvent window;         /**< Window event data */
    KeyboardEvent key;          /**< Keyboard event data */
    TextEditingEvent edit;      /**< Text editing event data */
    TextInputEvent text;        /**< Text input event data */
    MouseMotionEvent motion;    /**< Mouse motion event data */
    MouseButtonEvent button;    /**< Mouse button event data */
    MouseWheelEvent wheel;      /**< Mouse wheel event data */
    JoyAxisEvent jaxis;         /**< Joystick axis event data */
    JoyBallEvent jball;         /**< Joystick ball event data */
    JoyHatEvent jhat;           /**< Joystick hat event data */
    JoyButtonEvent jbutton;     /**< Joystick button event data */
    JoyDeviceEvent jdevice;     /**< Joystick device change event data */
    ControllerAxisEvent caxis;      /**< Game Controller axis event data */
    ControllerButtonEvent cbutton;  /**< Game Controller button event data */
    ControllerDeviceEvent cdevice;  /**< Game Controller device event data */
    AudioDeviceEvent adevice;   /**< Audio device event data */
    QuitEvent quit;             /**< Quit request event data */
    UserEvent user;             /**< Custom event data */
    SysWMEvent syswm;           /**< System dependent window event data */
    TouchFingerEvent tfinger;   /**< Touch finger event data */
    MultiGestureEvent mgesture; /**< Gesture event data */
    DollarGestureEvent dgesture; /**< Gesture event data */
    DropEvent drop;             /**< Drag and drop event data */
  } Event;

  
  /**
   * @brief Use this function to poll for currently pending events.
   * @param event the SO::Event instance to be filled with the next event
   * from the queue.
   * @return True if there is a pending event or false if there are none
   * avaible.
   */
  inline bool PollEvent(Event& event)
  {
    return static_cast<bool>(SDL_PollEvent((SDL_Event*)(&event)));
  }

  /**
   * @brief Use this function to wait indefinitely for the next avaible event.
   * @param event the SO::Event instance to be filed in with the next event from the queue.
   * @throw SO::Error if there was an error while waiting for events.
   */
  inline void WaitEvent(Event& event)
  {
    if (SDL_WaitEvent((SDL_Event*)(&event)) == 0)
      throw SO::Error(SDL_GetError());
  }

  
}


#endif // _EVENT_HPP

