#pragma once
namespace MathLibraryP
{
    class Operations
    {
    public:
        // Returns a!
        static double Factorial(double a);

        // Returns sqrt^b(a)
        static double Sqrt(double a, double b);

        // Returns a^b
        static double Involution(double a, double b);

        // Returns %a
        static double Percentage(double a);

        //Returns ln(a)
        static double Logarithm(double a);

        //Returns abs(a)
        static double Mabs(double a);
    };
}