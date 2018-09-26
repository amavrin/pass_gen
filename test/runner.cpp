/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_PasgenTest_init = false;
#include "pasgen_test.h"

static PasgenTest suite_PasgenTest;

static CxxTest::List Tests_PasgenTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_PasgenTest( "pasgen_test.h", 6, "PasgenTest", suite_PasgenTest, Tests_PasgenTest );

static class TestDescription_suite_PasgenTest_testCanGetRandomChar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PasgenTest_testCanGetRandomChar() : CxxTest::RealTestDescription( Tests_PasgenTest, suiteDescription_PasgenTest, 10, "testCanGetRandomChar" ) {}
 void runTest() { suite_PasgenTest.testCanGetRandomChar(); }
} testDescription_suite_PasgenTest_testCanGetRandomChar;

static class TestDescription_suite_PasgenTest_testCanGetSomePassAndLenIsCorrect : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PasgenTest_testCanGetSomePassAndLenIsCorrect() : CxxTest::RealTestDescription( Tests_PasgenTest, suiteDescription_PasgenTest, 26, "testCanGetSomePassAndLenIsCorrect" ) {}
 void runTest() { suite_PasgenTest.testCanGetSomePassAndLenIsCorrect(); }
} testDescription_suite_PasgenTest_testCanGetSomePassAndLenIsCorrect;

static class TestDescription_suite_PasgenTest_testCorrentDictLen : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PasgenTest_testCorrentDictLen() : CxxTest::RealTestDescription( Tests_PasgenTest, suiteDescription_PasgenTest, 35, "testCorrentDictLen" ) {}
 void runTest() { suite_PasgenTest.testCorrentDictLen(); }
} testDescription_suite_PasgenTest_testCorrentDictLen;

static class TestDescription_suite_PasgenTest_testCanSetPassLen : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PasgenTest_testCanSetPassLen() : CxxTest::RealTestDescription( Tests_PasgenTest, suiteDescription_PasgenTest, 40, "testCanSetPassLen" ) {}
 void runTest() { suite_PasgenTest.testCanSetPassLen(); }
} testDescription_suite_PasgenTest_testCanSetPassLen;

static class TestDescription_suite_PasgenTest_testRandomIsQuiteRandom : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_PasgenTest_testRandomIsQuiteRandom() : CxxTest::RealTestDescription( Tests_PasgenTest, suiteDescription_PasgenTest, 50, "testRandomIsQuiteRandom" ) {}
 void runTest() { suite_PasgenTest.testRandomIsQuiteRandom(); }
} testDescription_suite_PasgenTest_testRandomIsQuiteRandom;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
