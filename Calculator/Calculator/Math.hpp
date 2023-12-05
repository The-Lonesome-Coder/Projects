#pragma once


namespace math
{
    // Check validity
    template <typename T>
    [[nodiscard]] bool divisorCheck(const T& num1, const T& num2) noexcept
    {
        if (num1 == 0 || num2 == 0 || num1 == 0.0 || num2 == 0.0)
        {
            return true;
        }

        return false;
    }


    // Addition
    template <typename T>
    [[nodiscard]] T add(const T& lhs, const T& rhs) noexcept
    {
        return lhs + rhs;
    }


    // Subtraction
    template <typename T>
    [[nodiscard]] T subtract(const T& lhs, const T& rhs) noexcept
    {
        return lhs - rhs;
    }


    // Multiplication
    template <typename T>
    [[nodiscard]] T multiply(const T& lhs, const T& rhs) noexcept
    {
        return lhs * rhs;
    }


    // Division
    template <typename T>
    [[nodiscard]] T divide(const T& lhs, const T& rhs) noexcept
    {
        return lhs / rhs;
    }

    // Calculation
    template <typename T>
    [[nodiscard]] T calculate(const T& num1, const T& num2, const char op) noexcept
    {
        switch (op)
        {
        case '+':
            return add(num1, num2);

        case '-':
            return subtract(num1, num2);

        case '*':
            return multiply(num1, num2);

        case '/':
            return divide(num1, num2);
        }
    }
}

