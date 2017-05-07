#pragma once

#include <cstdint>
#include <vector>
#include <string>

class Palindrome
{
public:
    Palindrome() = default;
    Palindrome(const Palindrome&) = default;
    std::string getLastStringTested() const;
    uint16_t getNumberOfTestedString() const;
    std::vector<std::string> getAllPalindromeTestingString() const;
    std::vector<std::string> getFailedPalindromeTestedString() const;
    bool testString(const std::string);

private:
    std::string mLastStringTested;
    uint16_t mNumberOfTestedString;
    std::vector<std::string> mPalindromeString;
    std::vector<std::string> mFailedPalindromeString;
};
