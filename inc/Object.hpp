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
 * File:   Object.hpp
 * Author: olivier
 *
 * Created on August 19, 2017, 6:06 PM
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <unordered_set>

#include "Error.hpp"

namespace SDL
{

/**
 * @brief Common interface for SDL wrapper class.
 *
 * Every wrapper class from Cobra lib is derived from SDL::Object.
 * It is use as a common interace for the wrapper. *e.g*
 * the class propose by default a virtual method for paintEvent.
 * This combine with the fact that SDL::Object are organize as a tree,
 * you simply have to call paintEvent method on root, and every descendant
 * of root will call paintEvent also. Further more, just like Qt framework,
 * SDL::Object as the ability to manage memory for you. *i.e* on delete of
 * an SDL::Object instance, every descendant will be delete also.
 * For example, when you create a SDL::Renderer, the instance is automatically
 * linked to the SDL::Window pass in argument. This mean that when the instance
 * of SDL::Window is destroyed, the renderer will also be destroyed. Finally,
 * the tree is control by two method that are protected. The **joinParent**
 * and **quitParent** methods. Method to *abandon children* are **private**.
 *
 * @note If you don't want your instance to be linked automatically to another
 * instance (for example the renderer with the window), you can subclass the
 * class, and simply call **quitParent** in the constructor. This will ensure
 * that your instance will be un-linked to its parent.
 *
 * @warning Always use on **heap** instance. If you use on **stack** instance,
 * make sure to subclass and un-linked to the parent first. This is because
 * it's not possible to distinguish between on heap and on stack instance,
 * during runtime and compile time. Therefore, if a stack instance as a parent,
 * and this parent is deleted (wheter by scope range or explicitly by delete)
 * before the stack instance child go out of scope, the behavior is
 * undefined. **Always use on heap object** or **subclass base class, un-linked
 * to parent in constructor, and create on stack**.
 */
    
class Object
{


public:

    Object() : m_children(), m_parent(nullptr) { }

    explicit Object(Object* parent);

    virtual ~Object();

    virtual void paintEvent();

    int getNumberOfChild() const;

    const Object* getParent() const;


protected:

    std::unordered_set<Object*> children() const;

    void joinParent(Object* parent);

    void quitParent();


private:

    std::unordered_set<Object*> m_children;

    Object* m_parent;


    void addChild(Object* child);

    void removeChild(Object* child);
};

}

#endif /* OBJECT_HPP */

