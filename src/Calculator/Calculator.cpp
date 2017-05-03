#include "Calculator.hpp"

#include <iostream>

namespace Calculator
{

Calculator::Calculator()
{
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}

Calculator::~Calculator()
{
        std::cout << __PRETTY_FUNCTION__ << std::endl;
}

int Calculator::add(int arg1, int arg2)
{
    return arg1 + arg2;
}

int Calculator::subtract(int arg1, int arg2)
{
    return arg1 - arg2;
}

int Calculator::multiply(int arg1, int arg2)
{
    return arg1 * arg2;
}

int Calculator::divide(int arg1, int arg2)
{
    return arg1 / arg2;
}

}   //namespace Calculator
