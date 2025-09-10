#include<iostream>
#include<gtest/gtest.h>

using namespace std;

long long fibonacci(int val){
    if (val <1){
        return val;
    }

    long long a = 0;
    long long b = 1;
    for (int i=2;i<=val;i++){
        long long temp = a+b;
        a=b;
        b=temp;
    }
    return b;
}

struct FibonacciTestParams{
    int input;
    long long output;
};

class FibonacciTest : public ::testing::TestWithParam<FibonacciTestParams>
{}; 
TEST_P (FibonacciTest, CorrectlyComputes)
{
    const auto& params = GetParam();
    EXPECT_EQ(fibonacci(params.input),params.output);
}

INSTANTIATE_TEST_SUITE_P(FibonacciTests, FibonacciTest, 
    ::testing::Values(FibonacciTestParams{0,0},
                    FibonacciTestParams{1,1},
                    FibonacciTestParams{2,1},
                    FibonacciTestParams{3,2},
                    FibonacciTestParams{10,55})
);