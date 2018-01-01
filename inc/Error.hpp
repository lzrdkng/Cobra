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
 * File:   Error.hpp
 * Author: olivier
 *
 * Created on August 28, 2017, 9:41 AM
 *
 */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>

namespace SO
{

  class Error : public std::runtime_error
  {

  public:

    Error(const char* message) : std::runtime_error(message) {}

    virtual ~Error() {}

  };

}

#endif // EXCEPTION_HPP
