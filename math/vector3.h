#pragma once
#include <iostream>

namespace equinox
{
    namespace math
    {
        struct vector3
        {
            float x, y, z;

            vector3();
            vector3(const float& x, const float& y, const float& z);

            vector3& add(const vector3& other_vector);
            vector3& subtract(const vector3& other_vector);
            vector3& multiply(const vector3& other_vector);
            vector3& divide(const vector3& other_vector);

            friend std::ostream& operator<<(std::ostream& stream, const vector3& vector);
            
            friend vector3 operator+(vector3 current, const vector3& other);
            friend vector3 operator-(vector3 current, const vector3& other);
            friend vector3 operator*(vector3 current, const vector3& other);
            friend vector3 operator/(vector3 current, const vector3& other);

            vector3& operator+=(const vector3& other);
            vector3& operator-=(const vector3& other);
            vector3& operator*=(const vector3& other);
            vector3& operator/=(const vector3& other);

            bool operator==(const vector3& other);
            bool operator!=(const vector3& other);
        };
        
    } // namespace math
} // namespace equinox
