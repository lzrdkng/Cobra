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
 * File:   test-point.cpp
 * Author: olivier
 *
 * Created on August 2017
 */

#include "catch.hpp"
#include "Point.hpp"


SCENARIO("class SDL::Point", "[Point]")
{
    GIVEN("A point Z with values (0,0) and a point U with values (1,1)")
    {
        SDL::Point Z(0,0);
        SDL::Point U(1,1);

        REQUIRE((Z.getX() == 0 && Z.getY() == 0)); // get methods

        WHEN("When Z is compared to U") // operators == !=
        {
            THEN("Z == U return false")
            {
                REQUIRE(Z == Z);
                REQUIRE(U == U);
                REQUIRE(Z != U);
            }
        }
        WHEN("When a new point C is copied from U") // copy constructor
        {
            SDL::Point C(U);

            THEN("C == U return true")
            {
                REQUIRE(C == U);
            }
        }
        WHEN("When a point S is created from static method fromInt with values (1,1)") // static method fromInt
        {
            SDL::Point S = SDL::Point::fromInt(1,1);

            THEN("S == U return true")
            {
                REQUIRE(S == U);
            }
        }
        WHEN("When a point S is created from static method fromSDL with value SDL_Point {1,1}") // static method fromSDL
        {
            SDL_Point point {1,1};
            SDL::Point S = SDL::Point::fromSDL(point);

            THEN("S == U return true")
            {
                REQUIRE(S == U);
            }
        }
        WHEN("When x values of Z are set to (1,1)") // set methods
        {
            Z.setValues(1, 1);

            THEN("Z == U")
            {
                REQUIRE(Z == U);
            }
        }
    }
}

