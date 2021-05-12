#include "vector4.h"

namespace equinox
{
    namespace math
    {
        // Default Constructor
        vector4::vector4()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
            w = 0.0f;
        }

        // Constructor
        vector4::vector4(const float& x, const float& y, const float& z, const float& w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        // Operations
        // Note - current setup of this section may interfere with
        // intended functionality of vector4 references. 
        // Refactor if needed. 
        vector4& vector4::add(const vector4& other_vector)
        {
            x += other_vector.x;
            y += other_vector.y;
            z += other_vector.z;
            w += other_vector.w;

            return *this;
        }

        vector4& vector4::subtract(const vector4& other_vector)
        {
            x -= other_vector.x;
            y -= other_vector.y;
            z -= other_vector.z;
            w -= other_vector.w;

            return *this;
        }

        vector4& vector4::multiply(const vector4& other_vector)
        {
            x *= other_vector.x;
            y *= other_vector.y;
            z *= other_vector.z;
            w *= other_vector.w;

            return *this;
        }

        vector4& vector4::divide(const vector4& other_vector)
        {
            x /= other_vector.x;
            y /= other_vector.y;
            z /= other_vector.z;
            w /= other_vector.w;

            return *this;
        }

        // Overloads
        // ostream
        std::ostream& operator<<(std::ostream& stream, const vector4& vector)
        {
            stream << "vector4: [" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << "]";
            return stream;
        }

        // Basic math operators
        vector4 operator+(vector4& current, const vector4& other)
        {
            return current.add(other);
        }

        vector4 operator-(vector4& current, const vector4& other)
        {
            return current.subtract(other);
        }

        vector4 operator*(vector4& current, const vector4& other)
        {
            return current.multiply(other);
        }

        vector4 operator/(vector4& current, const vector4& other)
        {
            return current.divide(other);
        }

        // Math assignment operators
        vector4& vector4::operator+=(const vector4& other)
        {
            *this = *this + other;
            return *this;
        }

        vector4& vector4::operator-=(const vector4& other)
        {
            *this = *this - other;
            return *this;
        }

        vector4& vector4::operator*=(const vector4& other)
        {
            *this = *this * other;
            return *this;
        }

        vector4& vector4::operator/=(const vector4& other)
        {
            *this = *this / other;
            return *this;
        }

        // Equivalence and Comparisons
        bool vector4::operator==(const vector4& other)
        {
            bool truth = (x == other.x && y == other.y && z == other.z && other.w);
            return truth;
        }

        bool vector4::operator!=(const vector4& other)
        {
            // Reuse operator == overload --> adjust if necessary
            bool truth = !(*this == other);
            return truth;
        }

    } // namespace math
        
} // namespace equinox
