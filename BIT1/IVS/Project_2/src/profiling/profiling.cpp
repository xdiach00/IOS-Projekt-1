
#include <iostream>
#include "../MathLibrary.cpp"
#include "../MathLibraryP.cpp"

using namespace std;
using namespace MathLibrary;
using namespace MathLibraryP;

double add(double x, double y)
{
    return MathLibrary::Arithmetic::Add(x, y);
}

double sub(double x, double y)
{
    return MathLibrary::Arithmetic::Subtract(x, y);
}

double mul(double x, double y)
{
    return MathLibrary::Arithmetic::Multiply(x, y);
}

double divide(double x, double y)
{
    return MathLibrary::Arithmetic::Divide(x, y);
}

double sqrt(double x, double y)
{
    return MathLibraryP::Operations::Sqrt(x, y);
}

double power(double x, double y)
{
    return MathLibraryP::Operations::Involution(x, y);
}

int main()
{

    double f;
    double sum = 0;
    double sumsquare = 0;

    int count = 0;
    while (scanf("%lf", &f) == 1)
    {
        sum += f;
        sumsquare += power(f, 2);
        count++;
    }

    double average = mul(divide(1, count), sum);

    double deviation = sqrt((mul(divide(1, sub(count, 1)), sub(sumsquare, mul(count, power(average, 2))))), 2);

    printf("%lf", deviation);

    return 0;
}