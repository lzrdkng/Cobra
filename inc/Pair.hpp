/*
 * The MIT License
 *
 * Copyright 2017 olivier.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/* 
 * File:   Pair.hpp
 * Author: olivier
 *
 * Created on August 13, 2017, 3:56 PM
 */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace Cobra
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

