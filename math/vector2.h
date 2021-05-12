#pragma once
#include <iostream>

namespace equinox
{
    namespace math
    {
        struct vector2
        {
            float x, y;

            vector2();
            vector2(const float& x, const float& y);

            vector2& add(const vector2& other_vector);
            vector2& subtract(const vector2& other_vector);
            vector2& multiply(const vector2& other_vector);
            vector2& divide(const vector2& other_vector);

            friend std::ostream& operator<<(std::ostream& stream, const vector2& vector);
            
            friend vector2& operator+(vector2& current, const vector2& other);
            friend vector2& operator-(vector2& current, const vector2& other);
            friend vector2& operator*(vector2& current, const vector2& other);
            friend vector2& operator/(vector2& current, const vector2& other);

            vector2& operator+=(const vector2& other);
            vector2& operator-=(const vector2& other);
            vector2& operator*=(const vector2& other);
            vector2& operator/=(const vector2& other);

            bool operator==(const vector2& other);
            bool operator!=(const vector2& other);
        };
        
    } // namespace math
} // namespace equinox
