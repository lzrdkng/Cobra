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

#include <vector>
#include <stdexcept>

namespace SDL
{
    
class Object
{
public:
    
    explicit Object() {m_parent = nullptr;}

    virtual ~Object()
    {

        quitParent();

        for (unsigned i=0; i<m_children.size(); ++i)
        {
            m_children[i]->quitParent();
        }
    }


private:

    std::vector<Object*> m_children;

    std::string m_name;

    Object* m_parent;

 
protected:

    virtual void paintEvent()
    {
        for (unsigned i=0; i<m_children.size(); ++i)
            m_children[i]->paintEvent();
    }

    virtual void quitParent()
    {

        if (m_parent != nullptr)
            m_parent->removeChild(this);

        m_parent = nullptr;
    }

    virtual void joinParent(Object& parent)
    {
        this->joinParent(&parent);
    }

    virtual void joinParent(Object* parent)
    {
        quitParent();
        m_parent = parent;
    }

public:

    virtual void addChild(Object& child)
    {
        m_children.push_back(&child);

        child.joinParent(this);
    }


    virtual void removeChild(Object& child)
    {
        this->removeChild(&child);
    }

    virtual void removeChild(Object* child)
    {
        for (unsigned i=0; i<m_children.size(); ++i)
        {
            if (m_children[i] == child)
            {
                m_children.erase(m_children.begin()+i);
                break;
            }
        }
    }
};
}

#endif /* OBJECT_HPP */

