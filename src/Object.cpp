#include "Object.hpp"

#include <stack>

#define ITERATE_SET(TYPE, BEGIN, END, DO) \
    for (std::unordered_set<TYPE>::const_iterator it=BEGIN; it!=END; ++it) \
    { DO }

#define DESCANDANT(DO) \
        ITERATE_SET(Object*, m_children.begin(), m_children.end(), DO)


using namespace SDL;

Object::Object(Object* parent) :  m_children(), m_parent(nullptr)
{
    joinParent(parent);
}


Object::~Object()
{
    while(!m_children.empty())
    {
        (*m_children.begin())->quitParent();
    }

    quitParent();
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
    /*
    std::stack<Object*> stack = {this};

    Object* node;

    while (!stack.empty())
    {
        node = stack.top();
        stack.pop();

        stack.push(node->children());


    }*/

    DESCANDANT((*it)->paintEvent();)
}


std::unordered_set<Object*> Object::children() const
{
    return m_children;
}

void Object::joinParent(Object* parent)
{
    Object* ancestor = parent;

    while (ancestor != nullptr)
    {
        if (ancestor == this)
            throw SDL::Error("No Respect Of Tree Hierarchy");

        ancestor = ancestor->m_parent;
    }

    quitParent();
    m_parent = parent;

    if (m_parent != nullptr)
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
