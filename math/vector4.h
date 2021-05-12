#pragma once
#include <iostream>

namespace equinox
{
    namespace math
    {
        struct vector4
        {
            float x, y, z, w;

            vector4();
            vector4(const float& x, const float& y, const float& z, const float& w);

            vector4& add(const vector4& other_vector);
            vector4& subtract(const vector4& other_vector);
            vector4& multiply(const vector4& other_vector);
            vector4& divide(const vector4& other_vector);

            friend std::ostream& operator<<(std::ostream& stream, const vector4& vector);
            
            friend vector4 operator+(vector4& current, const vector4& other);
            friend vector4 operator-(vector4& current, const vector4& other);
            friend vector4 operator*(vector4& current, const vector4& other);
            friend vector4 operator/(vector4& current, const vector4& other);

            vector4& operator+=(const vector4& other);
            vector4& operator-=(const vector4& other);
            vector4& operator*=(const vector4& other);
            vector4& operator/=(const vector4& other);

            bool operator==(const vector4& other);
            bool operator!=(const vector4& other);
        };
        
    } // namespace math
} // namespace equinox
