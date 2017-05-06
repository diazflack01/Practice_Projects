#include "gtest/gtest.h"
#include <Calculator.hpp>

class CalculatorTest : public ::testing::Test
{
protected:
    Calculator::Calculator* myCalcu;

    virtual void SetUp()
    {
        myCalcu = new Calculator::Calculator();
    }

    virtual void TearDown()
    {
        delete myCalcu;
    }
};

TEST_F(CalculatorTest, Add)
{
    ASSERT_EQ(myCalcu->add(1,1), 2);
    EXPECT_EQ(myCalcu->add(2,1), 1);
    ASSERT_EQ(myCalcu->add(3,1), 4);
    EXPECT_EQ(myCalcu->add(2,1), 3);
}

TEST_F(CalculatorTest, Subtract)
{
    ASSERT_EQ(myCalcu->subtract(1,1), 0);
    EXPECT_EQ(myCalcu->subtract(2,1), 1);
    ASSERT_EQ(myCalcu->subtract(3,1), 2);
    EXPECT_EQ(myCalcu->subtract(2,1), 1);
}

TEST_F(CalculatorTest, Multiply)
{
    ASSERT_EQ(myCalcu->multiply(1,1), 1);
    EXPECT_EQ(myCalcu->multiply(2,1), 2);
    ASSERT_EQ(myCalcu->multiply(3,1), 3);
    EXPECT_EQ(myCalcu->multiply(2,1), 2);
}

TEST_F(CalculatorTest, Divide)
{
    ASSERT_EQ(myCalcu->divide(1,1), 1);
    EXPECT_EQ(myCalcu->divide(2,1), 2);
    ASSERT_EQ(myCalcu->divide(3,1), 3);
    EXPECT_EQ(myCalcu->divide(2,1), 2);
}
