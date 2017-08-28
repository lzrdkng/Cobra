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
 * File:   test-color.cpp
 * Author: olivier
 *
 * Created on August 2017
 */


#include "catch.hpp"
#include "Color.hpp"

SCENARIO( "class SDL::Color", "[Color]" )
{
  GIVEN( "A black Color named B and a white color named W" )
  {
    SDL::Color B;
    SDL::Color W(255, 255, 255, 255);

    // get methods
    REQUIRE( B.getRed() == 0 );
    REQUIRE( B.getGreen() == 0 );
    REQUIRE( B.getBlue() == 0 );
    REQUIRE( B.getAlpha() == 255 );

    WHEN( "Colors are compared" ) // operators == !=
    {

      THEN( "B equal B, W equal W, but W doesn't equal B" )
      {
        REQUIRE( B == B );
        REQUIRE( W == W );
        REQUIRE( B != W );
      }
    }
    WHEN( "Color C is copied from Color W" ) // copy constructor
    {
      SDL::Color C(W);

      THEN( "C equal W" )
      {
        REQUIRE( C == W );
      }
    }
    WHEN( "Color A is assigned Color W" ) // operator =
    {
      SDL::Color A = W;

     THEN( "A equal W" )
      {
        REQUIRE( A == W );
      }
    }
    WHEN( "Color S is created from class Color static method 'fromRGB' with same values as W" ) // static methods fromRGB fromRGBA
    {
      SDL::Color S = SDL::Color::fromRGB(255, 255, 255);

      THEN( "S equal W" )
      {
        REQUIRE( S == W );
      }
    }
    WHEN("Color B is set with values (255, 255, 255 ,255)") // set methods
    {
        B.setRGB(255, 255, 255);

        THEN("B == W")
        {
            REQUIRE(B == W);
        }
    }
  }
}
