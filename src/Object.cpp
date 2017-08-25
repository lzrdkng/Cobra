#include "Object.hpp"

#include <iostream>
#include <stack>

#define ITERATE_SET(TYPE, BEGIN, END, DO) \
    for (std::unordered_set<TYPE>::const_iterator it=BEGIN; it!=END; ++it) \
    { DO }

#define ITERATE_CHILD(DO) \
        ITERATE_SET(Object*, m_children.begin(), m_children.end(), DO)


using namespace SDL;

Object::Object(Object* parent)
{
    m_parent = parent;
}


Object::~Object()
{
    quitParent();

    while (!m_children.empty())
    {
        delete *(m_children.begin());
    }
}


int Object::getNumberOfChild() const
{
    return m_children.size();
}

const Object* Object::getParent() const
{
    return m_parent;
}


void Object::paintEvent()
{
    ITERATE_CHILD((*it)->paintEvent();)
}


void Object::joinParent(Object* parent)
{

    Object* ancestor = parent;

    while (ancestor != nullptr)
    {
        if (ancestor == this)
            throw std::runtime_error("NO RESPECT OF FAMILY HIERARCHY");
        ancestor = ancestor->m_parent;
    }

    quitParent();
    m_parent = parent;
    m_parent->addChild(this);
}


void Object::quitParent()
{

    if (m_parent != nullptr)
    {
        m_parent->removeChild(this);
        m_parent = nullptr;
    }
}

void Object::addChild(Object *child)
{
    m_children.insert(child);
}

void Object::removeChild(Object *child)
{
    m_children.erase(child);
}
