#include <cppunit/ui/text/TestRunner.h>
#include "TestPair.hpp"


int main()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(CPairTest::suite());
    runner.run();
    return 0;
}