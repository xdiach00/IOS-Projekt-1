#include "MathLibraryP.h"
#include <iostream>
#include <cmath>

using namespace std;

namespace MathLibraryP
{
    double Operations::Factorial(double a)
    {
        if (a < 0.0 || std::fmod(a, 1) != 0.0)
        {
            throw std::invalid_argument("Cannot read the factorial from a negative or decimal number");
        }
        int c = 1;
        for (int i = 1; i <= a; i++)
        {
            c *= i;
        };
        return c;
    }

    double Operations::Sqrt(double a, double b)
    {
        if (a < 0 || b <= 0 || std::fmod(b, 1) != 0.0)
        {
            throw std::invalid_argument("Cannot extract the root of a negative number.");
        }

        return ceil(std::pow(a, 1 / b) * 100.0) / 100.0;
    }

    double Operations::Involution(double a, double b)
    {
        if (b < 0 || std::fmod(b, 1) != 0.0)
        {
            throw std::invalid_argument("Cannot take with the negative degree");
        }
        double c = 1;
        for (int i = 0; i < b; i++)
        {
            c = c * a;
        };
        return c;
    }

    double Operations::Percentage(double a)
    {
        return ceil((a / 100.0) * 1000.0) / 1000.0;
    }

    double Operations::Logarithm(double a)
    {
        if (a <= 0)
        {
            throw std::invalid_argument("Cannot calculate the ln of a non-positive number");
        }
        return ceil(log(a) * 100000.0) / 100000.0;
    }
}