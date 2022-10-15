    /// @param wasSuccess je číslo datového typu int, ketré představuje počet úspěšných testu
int wasSuccess = 0;
    /// 
    /// @brief Tato isIntEqual funkce určuje jeslti se výsledek shoduje s očekávaným výsledkem.
    /// @param val1 je číslo datového typu double, které představuje výsledek
    /// @param val2 je číslo datového typu double, ketré představuje očekávaný výsledek
    /// @return zda rovnost platí nebo ne v booleanu
    ///
bool isIntEqual(double val1, double val2)
{
    if(val1 == val2)
        return true;

    return false;
}
    /// 
    /// @brief Tato isAlmostEqual funkce určuje jeslti se výsledek skoro shoduje s očekávaným výsledkem.
    /// @param val1 je číslo datového typu double, které představuje výsledek
    /// @param val2 je číslo datového typu double, ketré představuje očekávaný výsledek
    /// @param epsilon je číslo datového typu double, ketré představuje maximální možnou odchylku výsledků
    /// @return zda rovnost platí nebo ne v booleanu
    ///
bool isAlmostEqual(double val1, double val2, double epsilon = 0.000000001)
{
    return std::abs(val1 - val2) < epsilon;
}
    /// 
    /// @brief Tato isIntNotEqual funkce určuje jeslti se výsledek neshoduje s očekávaným výsledkem.
    /// @param val1 je číslo datového typu double, které představuje výsledek
    /// @param val2 je číslo datového typu double, ketré představuje očekávaný výsledek
    /// @return zda rovnost platí nebo ne v booleanu
    ///
bool isIntNotEqual(double val1, double val2)
{
    if(val1 != val2)
        return true;

    return false;
}
    /// 
    /// @brief Tato runTest funkce určuje jeslti test proběhl uspěšně.
    /// @param message je datového typu string, zpráva která se vypíše
    /// @param condition je datového typu boolean, ketrý udává zda byl test uspěšný nebo ne
    ///
void runTest(const std::string& message, bool condition)
{
    if(condition)
        std::cout << "\033[1;32mTEST SUCCESS:\033[0m ";
    else {
        wasSuccess++;
        std::cout << "\033[1;31mTEST FAILED:\033[0m ";
    }


    std::cout << "(" << message << ")\n";

}
