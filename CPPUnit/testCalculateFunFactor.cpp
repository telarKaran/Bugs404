#include <bits/stdc++.h>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include <iostream>
#include <string>
#include "Graph.h"

 
using namespace std;
using namespace CppUnit;


class TestcalculateFunFactor : public CppUnit :: TestFixture {
    CPPUNIT_TEST_SUITE(TestcalculateFunFactor);
    CPPUNIT_TEST(calculateFunFactor);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void TestcalculateFunFactor(void);

private:
    Bookings *mTestObj;
};

void TestcalculateFunFactor::calculateFunFactor(void) {
    //Sunny Test Cases
    CPPUNIT_ASSERT(5 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(7 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(9 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(4 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(1 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    //Rainy Test Cases
    CPPUNIT_ASSERT(-1 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
    CPPUNIT_ASSERT(-1 == mTestObj->calculateFunFactor((int path[],int& path_index, int day, vector< vector<string> > &v, vector< vector<string> > &v2));
}

void TestcalculateFunFactor::setUp(void) {
    mTestObj =  new  Graph(int V);
}

void TestcalculateFunFactor::tearDown(void) {
    delete mTestObj;
}



//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestcalculateFunFactor );

int main(int argc, char* argv[]) {

    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppDateResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

