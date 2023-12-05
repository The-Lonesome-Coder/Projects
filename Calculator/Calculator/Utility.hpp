#pragma once

#include <iostream>


namespace utility
{
    // Print result
    template <typename T>
    [[nodiscard]] void print(const T& result) noexcept
    {
        std::cout << result << std::endl;
    }


    // Continue?
    [[nodiscard]] void proceed(char& flag) noexcept
    {
        std::cout << "Do you want to continue (Enter y or n): ";
        std::cin >> flag;
    }


    // End
    [[nodiscard]] void thanks() noexcept
    {
        std::cout << "Thank you so much for using the program." << std::endl;
    }
}