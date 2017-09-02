#include "catch.hpp"
#include "Object.hpp"

TEST_CASE("Test inheritance of object")
{

    SDL::Object root; // No parent

    SDL::Object* child = new SDL::Object(&root); //  Parent is root

    REQUIRE(root.getParent() == nullptr);
    REQUIRE(root.getNumberOfChild() == 1);
    REQUIRE(child->getParent() == &root);

    SDL::Object descandant(child);

    REQUIRE(child->getNumberOfChild() == 1);
    REQUIRE(descandant.getParent() == child);

    delete child;
    child = nullptr;

    REQUIRE(root.getNumberOfChild() == 0);
    REQUIRE(descandant.getParent() == nullptr);
}
