#include "gtest/gtest.h"
#include <Palindrome.hpp>

class PalindromeTest : public ::testing::Test
{
protected:
    Palindrome* palindrome;

    virtual void SetUp(){ palindrome = new Palindrome(); }

    virtual void TearDown(){ delete palindrome; }
};

TEST_F(PalindromeTest, TestGetLastString_Empty)
{
    ASSERT_STREQ("", palindrome->getLastStringTested().c_str());
}

TEST_F(PalindromeTest, TestGetLastString_NotEmpty)
{
    const std::string TEST_STR1 = "Hello";
    palindrome->testString(TEST_STR1);
    ASSERT_STREQ(TEST_STR1.c_str(), palindrome->getLastStringTested().c_str());
}

TEST_F(PalindromeTest, getNumberOfTestedString)
{
    const std::string TEST_STR1 = "Hello";
    const unsigned TEST_TIMES = 10;
    for(auto testIdx = 0u; testIdx < TEST_TIMES; ++testIdx)
    {
        palindrome->testString(TEST_STR1);
    }
    ASSERT_EQ(TEST_TIMES, palindrome->getNumberOfTestedString());
}

TEST_F(PalindromeTest, getAllPalindromeTestingString_Empty)
{
    const auto cnt = static_cast<uint16_t>(palindrome->getAllPalindromeTestingString().size());
    ASSERT_EQ(0, cnt);
}

TEST_F(PalindromeTest, getAllPalindromeTestingString_NotEmpty)
{
    const std::vector<std::string> TEST_DATA = {"Hello", "1001", "BooB", "Django"};
    for(auto idx = 0u; idx < TEST_DATA.size(); ++idx)
    {
        palindrome->testString(TEST_DATA.at(idx));
    }
    const auto cnt = static_cast<uint16_t>(palindrome->getAllPalindromeTestingString().size());
    ASSERT_EQ(2, cnt);
}

TEST_F(PalindromeTest, getFailedPalindromeTestedString_Empty)
{
    const auto cnt = static_cast<uint16_t>(palindrome->getFailedPalindromeTestedString().size());
    ASSERT_EQ(0, cnt);
}

TEST_F(PalindromeTest, getFailedPalindromeTestedString_NotEmpty)
{
    const std::vector<std::string> TEST_DATA = {"Hello", "1001", "BooB", "Django", "3312dsa", "dsdasdasdas"};
    for(auto idx = 0u; idx < TEST_DATA.size(); ++idx)
    {
        palindrome->testString(TEST_DATA.at(idx));
    }
    const auto cnt = static_cast<uint16_t>(palindrome->getFailedPalindromeTestedString().size());
    ASSERT_EQ(4, cnt);
}

TEST_F(PalindromeTest, testString_OK)
{
    const std::vector<std::string> TEST_DATA = {"1001", "BooB", "JooJ", "d"};
    for(auto idx = 0u; idx < TEST_DATA.size(); ++idx)
    {
        ASSERT_TRUE(palindrome->testString(TEST_DATA.at(idx)));
    }
}

TEST_F(PalindromeTest, testString_NOK)
{
    const std::vector<std::string> TEST_DATA = {"10dsa01", "Bo321312_oB", "Joc_dasdoJ", "dsa_dasd"};
    for(auto idx = 0u; idx < TEST_DATA.size(); ++idx)
    {
        ASSERT_FALSE(palindrome->testString(TEST_DATA.at(idx)));
    }
}
