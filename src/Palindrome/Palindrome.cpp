#include "Palindrome.hpp"


std::string Palindrome::getLastStringTested() const
{
    return mLastStringTested;
}

uint16_t Palindrome::getNumberOfTestedString() const
{
    return mNumberOfTestedString;
}

std::vector<std::string> Palindrome::getAllPalindromeTestingString() const
{
    return mPalindromeString;
}

std::vector<std::string> Palindrome::getFailedPalindromeTestedString() const
{
    return mFailedPalindromeString;
}

bool Palindrome::testString(const std::string text)
{
    mLastStringTested = text;
    ++mNumberOfTestedString;
    // Using no STL
    unsigned i = 0;
    unsigned j = text.length() - 1;
    while (i < j)
    {
        if(text.at(i) != text.at(j))
        {
            mFailedPalindromeString.emplace_back(text);
            return false;
        }
        ++i;
        --j;
    }
    mPalindromeString.emplace_back(text);
    return true;
}
