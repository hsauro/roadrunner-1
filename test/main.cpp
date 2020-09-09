#include "gtest/gtest.h"


std::string     gRRTestDir= "";
std::string     gRROutputDir = "";


int main(int argc, char** argv)
{
    //Setup googletest
    ::testing::InitGoogleTest(&argc, argv);

    //Setup the global test directory:
    char* testdir = getenv("testdir");
    if (testdir) {
        gRRTestDir = testdir;
    }
    if (gRRTestDir.empty()) {
        std::cerr << "Please set the 'testdir' environment variable before running tests.  This should be the 'test/' directory of the roadrunner root directory." << std::endl;
        return 1;
    }
    gRRTestDir += "/";

    //Setup the output directory (will be the relative directory "output/" by default)
    char* outdir = getenv("outdir");
    if (outdir) {
        gRROutputDir = outdir;
    }
    if (gRROutputDir.empty()) {
        gRROutputDir = "output";
    }
    gRROutputDir += "/";

    //Run the tests.
    int ret = RUN_ALL_TESTS();
    return ret;
}