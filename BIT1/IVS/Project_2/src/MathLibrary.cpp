#include "MathLibrary.h"
#include <iostream>

namespace MathLibrary
{
    double Arithmetic::Add(double a, double b)
    {
        return a + b;
    }

    double Arithmetic::Subtract(double a, double b)
    {
        return a - b;
    }

    double Arithmetic::Multiply(double a, double b)
    {
        return a * b;
    }

    double Arithmetic::Divide(double a, double b)
    {
        if (b == 0) {
            throw std::invalid_argument("Cant divide with zero.");
        }

        return a / b;
    }
}