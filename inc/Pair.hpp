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
 * File:   Pair.hpp
 * Author: olivier
 *
 * Created on August 13, 2017, 3:56 PM
 */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace SDL
{

template<typename T, typename U = T>
class Pair {
    
public:
    

    explicit Pair(const T& lValue, const U& rValue);
    
    Pair(const Pair<T, U>& orig);
    
    virtual ~Pair() {}
    
    // get methods
    
    T getLeftValue()  const;
    U getRightValue() const;
    
    // set methods
    
    Pair<T, U>& setLeftValue(const T& value);
    Pair<T, U>& setRightValue(const U& value);
    Pair<T, U>& setValues(const T& lValue, const U& rValue);
    
    // operator method
    
    void operator=(const Pair<T, U>& orig);
    bool operator==(const Pair<T, U>& comp);
    bool operator!=(const Pair<T, U>& comp);
    
    
private:
    
    T m_lValue;
    U m_rValue;

};

template <typename T, typename U>
Pair<T, U>::Pair(const T& lValue, const U& rValue)
{
    m_lValue = lValue;
    m_rValue = rValue;
}

template <typename T, typename U>
Pair<T, U>::Pair(const Pair<T, U>& orig)
{
    this->setLeftValue(orig.getLeftValue());
    this->setRightValue(orig.getRightValue());
}

template<typename T, typename U>
T Pair<T, U>::getLeftValue() const
{
    return m_lValue;
}

template<typename T, typename U>
U Pair<T, U>::getRightValue() const
{
    return m_rValue;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::setLeftValue(const T& value)
{
    m_lValue= value;
    return *this;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::setRightValue(const U& value)
{
    m_rValue = value;
    return *this;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::setValues(const T& lValue, const U& rValue)
{
    m_lValue = lValue;
    m_rValue = rValue;
    return *this;
}

template<typename T, typename U>
void Pair<T, U>::operator=(const Pair<T,U>& orig)
{
    m_lValue = orig.getLeftValue();
    m_rValue = orig.getRightValue();
}

template<typename T, typename U>
bool Pair<T, U>::operator==(const Pair<T,U>& comp)
{
    return m_lValue == comp.getLeftValue() && m_rValue == comp.getRightValue();
}

template<typename T, typename U>
bool Pair<T, U>::operator!=(const Pair<T,U>& comp)
{
    return !(this->operator ==(comp));
}

}

#endif /* PAIR_HPP */

