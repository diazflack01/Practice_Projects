#include <iostream>

#include <Calculator.hpp>
#include "gtest/gtest.h"
//#include "gmock/gmock.h"

TEST(DummyTest, FirstTest)
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
