#include "catch.hpp"
#include "Point.hpp"


SCENARIO("class SDL::Point")
{
    GIVEN("A point Z with values (0,0) and a point U with values (1,1)")
    {
        SDL::Point Z(0,0);
        SDL::Point U(1,1);


        REQUIRE((Z.getX() == 0 && Z.getY() == 0));
        REQUIRE((U.getX() == 1 && U.getY() == 1));

        WHEN("When Z is compared to U")
        {
            THEN("Z == U return false")
            {
                REQUIRE(Z == Z);
                REQUIRE(U == U);
                REQUIRE(Z != U);
            }
        }
        WHEN("When a new point C is copied from U")
        {
            SDL::Point C(U);

            THEN("C == U return true")
            {
                REQUIRE(C == U);
            }
        }
        WHEN("When a point S is created from static method fromInt with values (1,1)")
        {
            SDL::Point S = SDL::Point::fromInt(1,1);

            THEN("S == U return true")
            {
                REQUIRE(S == U);
            }
        }
        WHEN("When a point S is created from static method fromSDL with value SDL_Point {1,1}")
        {
            SDL_Point point {1,1};
            SDL::Point S = SDL::Point::fromSDL(point);

            THEN("S == U return true")
            {
                REQUIRE(S == U);
            }
        }
    }
}

