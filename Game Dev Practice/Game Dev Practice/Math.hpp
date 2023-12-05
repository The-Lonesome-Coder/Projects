#pragma once

#ifndef _MATH_HPP_
#define _MATH_HPP_

#include <iostream>


class Vector2f
{
    public:
        Vector2f(double x = 0.0, double y = 0.0);

        void print() const;

        double m_x, m_y;
};


#endif