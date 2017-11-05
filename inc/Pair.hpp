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
    

    Pair(const T& lValue, const U& rValue);
    
    Pair(const Pair<T, U>& orig);
    Pair(Pair<T, U>&& move);

    Pair<T, U>& operator =(const Pair<T, U>& orig);
    Pair<T, U>& operator =(Pair<T, U>&& move);

    
    virtual ~Pair() {}
    
    // get methods
    
    T getFirst()  const;
    U getSecond() const;
    
    // set methods
    
    Pair<T, U>& setFirst(const T& value);
    Pair<T, U>& setSecond(const U& value);
    Pair<T, U>& setValues(const T& firstValue, const U& secondValue);
    
    // operator method
    bool operator==(const Pair<T, U>& comp);
    bool operator!=(const Pair<T, U>& comp);
    
    
private:
    
    T m_first;
    U m_second;

};

template <typename T, typename U>
Pair<T, U>::Pair(const T& lValue, const U& rValue)
: m_first {lValue}, m_second {rValue}
{
}

template <typename T, typename U>
Pair<T, U>::Pair(const Pair<T, U>& orig)
: m_first {orig.getFirst()}, m_second {orig.getSecond()}
{

}

template <typename T, typename U>
Pair<T, U>::Pair(Pair<T, U>&& move)
: m_first {move.getFirst()}, m_second {move.getSecond()}
{

}

template<typename T, typename U>
T Pair<T, U>::getFirst() const
{
    return m_first;
}

template<typename T, typename U>
U Pair<T, U>::getSecond() const
{
    return m_second;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::setFirst(const T& value)
{
    m_first= value;
    return *this;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::setSecond(const U& value)
{
    m_second = value;
    return *this;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::setValues(const T& lValue, const U& rValue)
{
    m_first  = lValue;
    m_second = rValue;
    return *this;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::operator=(const Pair<T,U>& orig)
{
    m_first  = orig.getFirst();
    m_second = orig.getSecond();
    return *this;
}

template<typename T, typename U>
Pair<T, U>& Pair<T, U>::operator =(Pair<T,U>&& move)
{
    m_first  = move.getFirst();
    m_second = move.getSecond();
    return *this;
}

template<typename T, typename U>
bool Pair<T, U>::operator==(const Pair<T,U>& comp)
{
    return m_first == comp.getFirst() && m_second == comp.getSecond();
}

template<typename T, typename U>
bool Pair<T, U>::operator!=(const Pair<T,U>& comp)
{
    return !(*this == comp);
}

}

#endif /* PAIR_HPP */

