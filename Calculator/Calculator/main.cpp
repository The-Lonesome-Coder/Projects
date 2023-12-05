#include <cctype>
#include <iostream>

#include "Math.hpp"
#include "Utility.hpp"


int main()
{
    char flag { 'Y' };

    // Store result for chain operation
    double result { 0.0 };

    // Calculator
    while (std::tolower(flag) == 'y')
    {
        double num1 { 0.0 }, num2 { 0.0 };
        char op { '+' };

        // Ask for input
        std::cout << "Please enter an operation: ";
        std::cin >> num1 >> op >> num2;

        // Check input validity
        if (std::cin.fail())
        {
            std::cout << "Input must be a valid operation." << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            continue;
        }

        // Check divisor is 0
        if (op == '/' && math::divisorCheck(num1, num2))
        {
            std::cout << "Divisor cannot be 0." << std::endl;
            continue;
        }

        // Get the result
        result = math::calculate(num1, num2, op);

        // Print the result
        utility::print(result);

        // Continue?
        utility::proceed(flag);
    }

    utility::thanks();

    return 0;
}