#include <iostream>
#include "test_global_funcs.h"
#include "../MathLibrary.cpp"
#include "../MathLibraryP.cpp"

using namespace std;

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

double factorial(double x)
{
    return MathLibraryP::Operations::Factorial(x);
}

double sqrt(double x, double y)
{
    return MathLibraryP::Operations::Sqrt(x, y);
}

double power(double x, double y)
{
    return MathLibraryP::Operations::Involution(x, y);
}

double percentage(double x)
{
    return MathLibraryP::Operations::Percentage(x);
}

double ln(double x)
{
    return MathLibraryP::Operations::Logarithm(x);
}

int main(void)
{

    int exc = false;

    // ADD TESTS

    runTest("Add test equal | normal numbers", isIntEqual(add(2, 3), 5));

    runTest("Add test equal | high numbers", isIntEqual(add(20000000, 30000000), 50000000));

    runTest("Add test equal | negative normal numbers", isIntEqual(add(-2, -3), -5));

    runTest("Add test equal | negative high numbers", isIntEqual(add(-20000000, -30000000), -50000000));

    runTest("Add test equal | decimal normal numbers", isIntEqual(add(2.2, 3.3), 5.5));

    runTest("Add test equal | decimal high numbers", isIntEqual(add(20000000.222, 30000000.333), 50000000.555));

    runTest("Add test equal | negative decimal normal numbers", isIntEqual(add(-2.2, -3.3), -5.5));

    runTest("Add test equal | negative decimal high numbers", isIntEqual(add(-20000000.222, -30000000.333), -50000000.555));

    runTest("Add test not equal | normal numbers", isIntNotEqual(add(2, 3), 8));

    runTest("Add test not equal | negative normal numbers", isIntNotEqual(add(-2, -3), -8));

    runTest("Add test not equal | decimal normal numbers", isIntNotEqual(add(2.2, 3.3), 8.8));

    runTest("Add test not equal | negative decimal normal numbers", isIntNotEqual(add(-2.2, -3.3), -8.8));

    // SUB TESTS

    runTest("Subtract test equal | normal numbers", isIntEqual(sub(9, 3), 6));

    runTest("Subtract test equal | high numbers", isIntEqual(sub(90000000, 30000000), 60000000));

    runTest("Subtract test equal | negative normal numbers", isIntEqual(sub(-9, -3), -6));

    runTest("Subtract test equal | negative high numbers", isIntEqual(sub(-90000000, -30000000), -60000000));

    runTest("Subtract test equal | decimal normal numbers", isAlmostEqual(sub(9.9, 3.3), 6.6));

    runTest("Subtract test equal | decimal high numbers", isAlmostEqual(sub(90000000.999, 30000000.333), 60000000.666, 0.00000001));

    runTest("Subtract test equal | negative decimal normal numbers", isAlmostEqual(sub(-9.9, -3.3), -6.6));

    runTest("Subtract test equal | negative decimal high numbers", isAlmostEqual(sub(-90000000.999, -30000000.333), -60000000.666, 0.00000001));

    runTest("Subtract test not equal | normal numbers", isIntNotEqual(sub(6, 6), 10));

    runTest("Subtract test not equal | negative normal numbers", isIntNotEqual(sub(-6, -6), 10));

    runTest("Subtract test not equal | decimal normal numbers", isIntNotEqual(sub(6.6, 6.6), 10));

    runTest("Subtract test not equal | negative decimal normal numbers", isIntNotEqual(sub(-6.6, -6.6), 10));

    // MUL TESTS

    runTest("Multiply test equal | normal numbers", isIntEqual(mul(2, 4), 8));

    runTest("Multiply test equal | high numbers", isIntEqual(mul(2, 40000000), 80000000));

    runTest("Multiply test equal | negative normal numbers", isIntEqual(mul(-2, 4), -8));

    runTest("Multiply test equal | negative high numbers", isIntEqual(mul(-20000000, 4), -80000000));

    runTest("Multiply test equal | decimal normal numbers", isIntEqual(mul(2.2, 4), 8.8));

    runTest("Multiply test equal | decimal high numbers", isIntEqual(mul(20000000.2, 4), 80000000.8));

    runTest("Multiply test equal | negative decimal normal numbers", isIntEqual(mul(2, -4.4), -8.8));

    runTest("Multiply test equal | negative decimal high numbers", isIntEqual(mul(-2, 40000000.4), -80000000.8));

    runTest("Multiply test not equal | normal numbers", isIntNotEqual(mul(3, 5), 0));

    runTest("Multiply test not equal | negative normal numbers", isIntNotEqual(mul(-3, -5), 0));

    runTest("Multiply test not equal | decimal normal numbers", isIntNotEqual(mul(3.5, 5.3), 0));

    runTest("Multiply test not equal | negative decimal normal numbers", isIntNotEqual(mul(-3.5, -5.3), 0));

    // DIV TESTS

    runTest("Divide test equal | normal numbers", isIntEqual(divide(18, 2), 9));

    runTest("Divide test equal | high numbers", isIntEqual(divide(80000000, 40000000), 2));

    runTest("Divide test equal | negative normal numbers", isIntEqual(divide(-18, 2), -9));

    runTest("Divide test equal | negative high numbers", isIntEqual(divide(-80000000, 40000000), -2));

    runTest("Divide test equal | decimal normal numbers", isIntEqual(divide(22.5, 2.5), 9));

    runTest("Divide test equal | decimal high numbers", isIntEqual(divide(100000000, 40000000), 2.5));

    runTest("Divide test equal | negative decimal normal numbers", isIntEqual(divide(-22.5, 2.5), -9));

    runTest("Divide test equal | negative decimal high numbers", isIntEqual(divide(-100000000, 40000000), -2.5));

    runTest("Divide test not equal | normal numbers", isIntNotEqual(divide(10, 5), 0));

    runTest("Divide test not equal | negative normal numbers", isIntNotEqual(divide(-10, 5), 0));

    runTest("Divide test not equal | decimal normal numbers", isIntNotEqual(divide(10.1, 5.2), 0));

    runTest("Divide test not equal | negative decimal normal numbers", isIntNotEqual(divide(-10.1, -5.2), 0));

    try
    {

        exc = false; // prevent from being set from previous function
        divide(10, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Divide test throw error | normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        divide(100000000, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Divide test throw error | high number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        divide(-10, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Divide test throw error | negative number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        divide(-10.5, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Divide test throw error | decimal number", exc);

    // FACTORIAL

    runTest("Factorial test equal | normal numbers", isIntEqual(factorial(5), 120));

    runTest("Factorial test equal | high numbers", isIntEqual(factorial(10), 3628800));

    runTest("Factorial test not equal | normal numbers", isIntNotEqual(factorial(5), 0));

    runTest("Factorial test not equal | high numbers", isIntNotEqual(factorial(10), 0));

    try
    {

        exc = false; // prevent from being set from previous function
        factorial(-5);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Factorial test throw error | negative number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        factorial(5.5);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Factorial test throw error | decimal number", exc);

    // SQRT

    runTest("Root test equal | square root zero", isIntEqual(sqrt(0, 2), 0));

    runTest("Root test equal | square root normal numbers", isIntEqual(sqrt(9, 2), 3));

    runTest("Root test equal | square root high numbers", isIntEqual(sqrt(2500000000, 2), 50000));

    runTest("Root test equal | cube root normal numbers", isIntEqual(sqrt(27, 3), 3));

    runTest("Root test equal | cube root high numbers", isIntEqual(sqrt(1000000000, 3), 1000));

    runTest("Root test equal | fourth root normal numbers", isIntEqual(sqrt(81, 4), 3));

    runTest("Root test equal | fourth root high numbers", isIntEqual(sqrt(100000000, 4), 100));

    runTest("Root test equal | square root decimal normal numbers", isIntEqual(sqrt(9.9, 2), 3.15));

    runTest("Root test equal | square root decimal high numbers", isIntEqual(sqrt(2500030000.09, 2), 50000.30));

    runTest("Root test equal | cube root decimal normal numbers", isIntEqual(sqrt(27.3, 3), 3.02));

    runTest("Root test equal | cube root decimal high numbers", isIntEqual(sqrt(1001500750.1, 3), 1000.5));

    runTest("Root test equal | fourth root decimal normal numbers", isIntEqual(sqrt(81.8, 4), 3.01));

    runTest("Root test equal | fourth root decimal high numbers", isIntEqual(sqrt(102015050.1, 4), 100.51));

    runTest("Root test not equal | square root normal numbers", isIntNotEqual(sqrt(10, 2), 0));

    runTest("Root test not equal | cube root normal numbers", isIntNotEqual(sqrt(10, 3), 0));

    runTest("Root test not equal | fourth root normal numbers", isIntNotEqual(sqrt(10, 4), 0));

    runTest("Root test not equal | square root decimal normal numbers", isIntNotEqual(sqrt(10.5, 2), 0));

    runTest("Root test not equal | cube root decimal normal numbers", isIntNotEqual(sqrt(10.5, 3), 0));

    runTest("Root test not equal | fourth root decimal normal numbers", isIntNotEqual(sqrt(10.5, 4), 0));

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(9, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | zero root normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-9, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | zero root negative normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(9.9, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | zero root decimal normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-9.9, 0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | zero root negative decimal normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(9, -5);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | negative root normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-9, -5);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | negative root negative normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(9.9, -5);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | negative root decimal normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-9.9, -5);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | negative root negative decimal normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-9, 2);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | square root negative number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-27, 3);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | cube root negative number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-9.9, 2);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | square root negative number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        sqrt(-27.3, 3);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Root test throw error | cube root negative decimal number", exc);

    // POWER

    runTest("Power test equal | zero power", isIntEqual(power(0, 0), 1));

    runTest("Power test equal | square power normal numbers", isIntEqual(power(5, 2), 25));

    runTest("Power test equal | square power high numbers", isIntEqual(power(50000, 2), 2500000000));

    runTest("Power test equal | square power negative normal numbers", isIntEqual(power(-5, 2), 25));

    runTest("Power test equal | square power negative high numbers", isIntEqual(power(-50000, 2), 2500000000));

    runTest("Power test equal | square power decimal normal numbers", isIntEqual(power(5.5, 2), 30.25));

    runTest("Power test equal | square power decimal high numbers", isIntEqual(power(50000.5, 2), 2500050000.25));

    runTest("Power test equal | square power negative decimal normal numbers", isIntEqual(power(-5.5, 2), 30.25));

    runTest("Power test equal | square power negative decimal high numbers", isIntEqual(power(-50000.5, 2), 2500050000.25));

    runTest("Power test equal | 9th power normal numbers", isIntEqual(power(5, 9), 1953125));

    runTest("Power test equal | 9th power negative normal numbers", isIntEqual(power(-5, 9), -1953125));

    runTest("Power test equal | 9th power decimal normal numbers", isIntEqual(power(5.5, 9), 4605366.583984375));

    runTest("Power test equal | 9th power negative decimal normal numbers", isIntEqual(power(-5.5, 9), -4605366.583984375));

    runTest("Power test not equal | square power normal numbers", isIntNotEqual(power(10, 2), 0));

    runTest("Power test not equal | square power decimal normal numbers", isIntNotEqual(power(10.5, 9), 0));

    runTest("Power test not equal | 9th power normal numbers", isIntNotEqual(power(10, 2), 0));

    runTest("Power test not equal | 9th power decimal normal numbers", isIntNotEqual(power(10.5, 9), 0));

    try
    {

        exc = false; // prevent from being set from previous function
        power(5, -2);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Power test throw error | negative exponent", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        power(5, 2.2);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Power test throw error | decimal exponent", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        power(5, -2.2);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Power test throw error | negative decimal exponent", exc);

    // PERCENTAGE

    runTest("Percentage test equal | normal number", isIntEqual(percentage(50), 0.5));

    runTest("Percentage test equal | high number", isIntEqual(percentage(500000000000), 5000000000));

    runTest("Percentage test equal | negative number", isIntEqual(percentage(-50), -0.5));

    runTest("Percentage test equal | negative high number", isIntEqual(percentage(-500000000000), -5000000000));

    runTest("Percentage test equal | decimal number", isIntEqual(percentage(50.5), 0.505));

    runTest("Percentage test equal | decimal high number", isAlmostEqual(percentage(50000000.88), 500000.009));

    runTest("Percentage test equal | negative decimal number", isIntEqual(percentage(-50.5), -0.505));

    runTest("Percentage test equal | negative decimal high number", isAlmostEqual(percentage(-50000000.88), -500000.008));

    runTest("Percentage test not equal | normal number", isIntNotEqual(percentage(50), 0));

    runTest("Percentage test not equal | high number", isIntNotEqual(percentage(500000000000), 0));

    runTest("Percentage test not equal | negative number", isIntNotEqual(percentage(-50), 0));

    runTest("Percentage test not equal | negative high number", isIntNotEqual(percentage(-500000000000), 0));

    runTest("Percentage test not equal | decimal number", isIntNotEqual(percentage(50.5), 0));

    runTest("Percentage test not equal | decimal high number", isIntNotEqual(percentage(500000000000.55), 0));

    runTest("Percentage test not equal | negative decimal number", isIntNotEqual(percentage(-50.5), 0));

    runTest("Percentage test not equal | negative decimal high number", isIntNotEqual(percentage(-500000000000.55), 0));

    // LN

    runTest("Ln test equal | normal number", isIntEqual(ln(5), 1.60944));

    runTest("Ln test equal | high number", isIntEqual(ln(5000), 8.51720));

    runTest("Ln test equal | decimal normal number", isIntEqual(ln(5.8), 1.75786));

    runTest("Ln test equal | decimal high number", isIntEqual(ln(5000.8), 8.51736));

    runTest("Ln test not equal | normal number", isIntNotEqual(ln(5), 0));

    runTest("Ln test not equal | high number", isIntNotEqual(ln(5000), 0));

    runTest("Ln test not equal | decimal normal number", isIntNotEqual(ln(5.8), 0));

    runTest("Ln test not equal | decimal high number", isIntNotEqual(ln(5000.8), 0));

    try
    {

        exc = false; // prevent from being set from previous function
        ln(0);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Ln test throw error | zero", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        ln(-5);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Ln test throw error | negative normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        ln(-5000);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Ln test throw error | negative high number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        ln(-5.8);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Ln test throw error | decimal negative normal number", exc);

    try
    {

        exc = false; // prevent from being set from previous function
        ln(-5000.8);
    }
    catch (const std::invalid_argument &e)
    {
        exc = true;
    }

    runTest("Ln test throw error | decimal negative high number", exc);

    return wasSuccess;
}