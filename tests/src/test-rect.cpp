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
 *  1.The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 *  2.Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 *  3.This notice may not be removed or altered from any source distribution.
 */

/*
 * File:   test-rect.cpp
 * Author: olivier
 *
 * Created on August 28, 2017, 12:03 PM
 */


#include "catch.hpp"
#include "Rect.hpp"


SCENARIO("clas SDL::Rect", "[Rect]")
{
    GIVEN("A Rect instance N with values (0, 0, 0, 0) and a Rect"
          "instance U with values (0, 0, 1, 1)")
    {
        SDL::Rect N;
        SDL::Rect U(0, 0, 1, 1);

        // get methods
        REQUIRE((
                 U.getX()      == 0 &&
                 U.getY()      == 0 &&
                 U.getWidth()  == 1 &&
                 U.getHeight() == 1
               ));

        // operators == !=
        WHEN("N is compared to U")
        {
            THEN("N == U return false")
            {
                REQUIRE(N == N);
                REQUIRE(N != U);
            }
        }

        // operator =
        WHEN("A is asigned U")
        {
            SDL::Rect A = U;

            THEN("A == U")
            {
                REQUIRE(A == U);
            }
        }

        // copy constructor
        WHEN("C is copied from U")
        {
            SDL::Rect C(U);

            THEN("C == U")
            {
                REQUIRE(C == U);
            }
        }

        // implicit constructor / static method fromSDL
        WHEN("SC is implicility construct from SDL_Rect (0, 0, 1, 1)")
        {
            SDL_Rect rect {0, 0, 1, 1};
            SDL::Rect SC(rect);

            THEN("SC == U")
            {
                REQUIRE(SC == U);
            }
        }

        // set methods
        WHEN("U values are set to (0, 0, 0, 0)")
        {
            U.setValues(0, 0, 0, 0);

            THEN("U == N")
            {
                REQUIRE(U == N);
            }
        }

        // static method fromInt
        WHEN("S is created from static method fromInt with values (0, 0, 1, 1)")
        {
            SDL::Rect S = SDL::Rect::fromInt(0, 0, 1, 1);

            THEN("S == U")
            {
                REQUIRE(S == U);
            }
        }
    }
}
