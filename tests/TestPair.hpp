#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../inc/CPair.hpp"

class CPairTest : public CppUnit::TestFixture
{

private:
    CPair<int, float> *m_pair1, *m_pair2, *m_pair3;
          
public:
   
    static CppUnit::Test* suite()
    {
        CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("CPairTest");
        suiteOfTests->addTest(new CppUnit::TestCaller<CPairTest>("testEquality",
                                                                 &CPairTest::testEquality));
        suiteOfTests->addTest(new CppUnit::TestCaller<CPairTest>("testConstructorCopy",
                                                                 &CPairTest::testConstructorCopy));
        
        return suiteOfTests;
    }
    
    void setUp()
    {
        m_pair1 = new CPair<int, float>(1, 1.0);
        m_pair2 = new CPair<int, float>(*m_pair1);
        m_pair3 = new CPair<int, float>(1, 0.0);
    }
    
    void tearDown()
    {
        delete m_pair1;
        delete m_pair2;
        delete m_pair3;
    }
    
    void testEquality()
    {
        CPPUNIT_ASSERT(*m_pair1 != *m_pair3);
    }
    
    void testConstructorCopy()
    {
        CPPUNIT_ASSERT(*m_pair1 == *m_pair2);
    }
   
};
