#include "gtest/gtest.h"
#include <Palindrome.hpp>

class PalindromeTest : public ::testing::Test
{
protected:
    Palindrome palindrome;

    virtual void SetUp(){}

    virtual void TearDown(){}
};

TEST_F(PalindromeTest, TestGetLastString_Empty)
{
    ASSERT_STREQ("", palindrome.getLastStringTested().c_str());
}

// TEST_F(PalindromeTest, TestGetLastString_NotEmpty)
// {}

// TEST_F(PalindromeTest, getNumberOfTestedString){}

// TEST_F(PalindromeTest, getAllPalindromeTestingString_Empty){}

// TEST_F(PalindromeTest, getAllPalindromeTestingString_NotEmpty){}

// TEST_F(PalindromeTest, getFailedPalindromeTestedString_Empty){}

// TEST_F(PalindromeTest, getFailedPalindromeTestedString_NotEmpty){}

// TEST_F(PalindromeTest, testString_OK){}

// TEST_F(PalindromeTest, testString_NOK){}
