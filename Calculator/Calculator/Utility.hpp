#pragma once

#include <iostream>


namespace utility
{
    // Print result
    template <typename T>
    void print(const T& result) noexcept
    {
        std::cout << result << std::endl;
    }


    // Continue?
    void proceed(char& flag) noexcept
    {
        std::cout << "Do you want to continue (Enter y or n): ";
        std::cin >> flag;
    }


    // End
    void thanks() noexcept
    {
        std::cout << "Thank you so much for using the program." << std::endl;
    }
}