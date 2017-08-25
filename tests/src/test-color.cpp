#include "catch.hpp"
#include "Color.hpp"

SCENARIO( "Color class", "[Color]" )
{
  GIVEN( "A black Color named B and a white color named W" )
  {
    SDL::Color B;
    SDL::Color W(255, 255, 255, 255);

    REQUIRE( B.getRed() == 0 );
    REQUIRE( B.getGreen() == 0 );
    REQUIRE( B.getBlue() == 0 );
    REQUIRE( B.getAlpha() == 255 );
    REQUIRE( W.getRed() == 255);
    REQUIRE( W.getGreen() == 255);
    REQUIRE( W.getBlue() == 255);
    REQUIRE( W.getAlpha() == 255);

    WHEN( "Colors are compared" )
    {

      THEN( "B equal B, W equal W, but W doesn't equal B" )
      {
        REQUIRE( B == B );
        REQUIRE( W == W );
        REQUIRE( B != W );
      }
    }
    WHEN( "Color C is copied from Color W" )
    {
      SDL::Color C(W);

      THEN( "C equal W" )
      {
        REQUIRE( C == W );
      }
    }
    WHEN( "Color A is assigned Color W" )
    {
      SDL::Color A = W;

     THEN( "A equal W" )
      {
        REQUIRE( A == W );
      }
    }
    WHEN( "Color S is created from class Color static method 'fromRGBA' with same values as W" )
    {
      SDL::Color S = SDL::Color::fromRGBA(255, 255, 255, 255);

      THEN( "S equal W" )
      {
        REQUIRE( S == W );
      }
    }
  }
}
