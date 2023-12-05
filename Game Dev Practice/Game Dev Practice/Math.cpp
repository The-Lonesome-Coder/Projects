#include "Math.hpp"

Vector2f::Vector2f(double x, double y)
    : m_x { x }, m_y { y } { }


void Vector2f::print() const
{
    std::cout << m_x << ", " << m_y << std::endl;
}