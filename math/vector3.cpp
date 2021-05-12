#include "vector3.h"

namespace equinox
{
    namespace math
    {
        // Default Constructor
        vector3::vector3()
        {
            x = 0.0f;
            y = 0.0f;
            z = 0.0f;
        }

        // Constructor
        vector3::vector3(const float& x, const float& y, const float& z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        // Operations
        // Note - current setup of this section may interfere with
        // intended functionality of vector3 references. 
        // Refactor if needed. 
        vector3& vector3::add(const vector3& other_vector)
        {
            x += other_vector.x;
            y += other_vector.y;
            z += other_vector.z;

            return *this;
        }

        vector3& vector3::subtract(const vector3& other_vector)
        {
            x -= other_vector.x;
            y -= other_vector.y;
            z -= other_vector.z;

            return *this;
        }

        vector3& vector3::multiply(const vector3& other_vector)
        {
            x *= other_vector.x;
            y *= other_vector.y;
            z *= other_vector.z;

            return *this;
        }

        vector3& vector3::divide(const vector3& other_vector)
        {
            x /= other_vector.x;
            y /= other_vector.y;
            z /= other_vector.z;

            return *this;
        }

        // Overloads
        // ostream
        std::ostream& operator<<(std::ostream& stream, const vector3& vector)
        {
            stream << "vector3: [" << vector.x << ", " << vector.y << ", " << vector.z << "]";
            return stream;
        }

        // Basic math operators
        vector3 operator+(vector3 current, const vector3& other)
        {
            return current.add(other);
        }

        vector3 operator-(vector3 current, const vector3& other)
        {
            return current.subtract(other);
        }

        vector3 operator*(vector3 current, const vector3& other)
        {
            return current.multiply(other);
        }

        vector3 operator/(vector3 current, const vector3& other)
        {
            return current.divide(other);
        }

        // Math assignment operators
        vector3& vector3::operator+=(const vector3& other)
        {
            *this = *this + other;
            return *this;
        }

        vector3& vector3::operator-=(const vector3& other)
        {
            *this = *this - other;
            return *this;
        }

        vector3& vector3::operator*=(const vector3& other)
        {
            *this = *this * other;
            return *this;
        }

        vector3& vector3::operator/=(const vector3& other)
        {
            *this = *this / other;
            return *this;
        }

        // Equivalence and Comparisons
        bool vector3::operator==(const vector3& other)
        {
            bool truth = (x == other.x && y == other.y && z == other.z);
            return truth;
        }

        bool vector3::operator!=(const vector3& other)
        {
            // Reuse operator == overload --> adjust if necessary
            bool truth = !(*this == other);
            return truth;
        }

    } // namespace math
        
} // namespace equinox
