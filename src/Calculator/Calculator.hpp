#pragma once

#include <iostream>

namespace Calculator
{

class Calculator
{
public:
    Calculator();
    ~Calculator();

    int add(int arg1, int arg2);
    int subtract(int arg1, int arg2);
    int multiply(int arg1, int arg2);
    int divide(int arg1, int arg2);
};

}   //namespace Calculator
