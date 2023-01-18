#include "../Example.hpp"
#include <gtest/gtest.h>

struct ExampleTests 
    : public::testing::Test
{
    int* x;

    int getX(){
        return *x;
    }

    virtual void SetUp() override {
        x = new int(42);
    }

    virtual void TearDown() override {
        delete x;
    }

};

TEST_F(ExampleTests, MAC){
    // int x = 42;
    int y = 16; 
    int sum = 100;
    int oldSum = sum;
    int expectedSum = oldSum + getX() * y;

    EXPECT_EQ(
        expectedSum,
        MAC(getX(), y, sum)
    );

    EXPECT_EQ(
        expectedSum,
        sum
    );

};

TEST_F(ExampleTests, Square){
    int expectedSquare = getX() * getX();
    EXPECT_EQ(
        expectedSquare,
        Square(getX())
    );
};