#include<iostream>
#include<gtest/gtest.h>

using namespace std;

int is_prime(int val){
    if(val <= 0) {
        return false;
    }
    else if (val%2==0){
        return true;
    }
    return false;
}

class PrimeTest : public ::testing::Test
{

};

TEST_F(PrimeTest, HandlesPrime){
    ASSERT_TRUE(is_prime(2));
}

TEST_F(PrimeTest, HandlesNonPrime){
    ASSERT_FALSE(is_prime(25));
}

TEST_F(PrimeTest, HandlesEdgeCases){
    ASSERT_FALSE(is_prime(0));
}