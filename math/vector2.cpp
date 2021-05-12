#include "vector2.h"

namespace equinox
{
    namespace math
    {
        // Default Constructor
        vector2::vector2()
        {
            x = 0.0f;
            y = 0.0f;
        }

        // Constructor
        vector2::vector2(const float& x, const float& y)
        {
            this->x = x;
            this->y = y;
        }

        // Operations
        // Note - current setup of this section may interfere with
        // intended functionality of vector2 references. 
        // Refactor if needed. 
        vector2& vector2::add(const vector2& other_vector)
        {
            x += other_vector.x;
            y += other_vector.y;

            return *this;
        }

        vector2& vector2::subtract(const vector2& other_vector)
        {
            x -= other_vector.x;
            y -= other_vector.y;

            return *this;
        }

        vector2& vector2::multiply(const vector2& other_vector)
        {
            x *= other_vector.x;
            y *= other_vector.y;

            return *this;
        }

        vector2& vector2::divide(const vector2& other_vector)
        {
            x /= other_vector.x;
            y /= other_vector.y;

            return *this;
        }

        // Overloads
        // ostream
        std::ostream& operator<<(std::ostream& stream, const vector2& vector)
        {
            stream << "vector2: [" << vector.x << ", " << vector.y << "]";
            return stream;
        }

        // Basic math operators
        vector2& operator+(vector2& current, const vector2& other)
        {
            return current.add(other);
        }

        vector2& operator-(vector2& current, const vector2& other)
        {
            return current.subtract(other);
        }

        vector2& operator*(vector2& current, const vector2& other)
        {
            return current.multiply(other);
        }

        vector2& operator/(vector2& current, const vector2& other)
        {
            return current.divide(other);
        }

        // Math assignment operators
        vector2& vector2::operator+=(const vector2& other)
        {
            *this = *this + other;
            return *this;
        }

        vector2& vector2::operator-=(const vector2& other)
        {
            *this = *this - other;
            return *this;
        }

        vector2& vector2::operator*=(const vector2& other)
        {
            *this = *this * other;
            return *this;
        }

        vector2& vector2::operator/=(const vector2& other)
        {
            *this = *this / other;
            return *this;
        }

        // Equivalence and Comparisons
        bool vector2::operator==(const vector2& other)
        {
            bool truth = (x == other.x && y == other.y);
            return truth;
        }

        bool vector2::operator!=(const vector2& other)
        {
            // Reuse operator == overload --> adjust if necessary
            bool truth = !(*this == other);
            return truth;
        }

    } // namespace math
        
} // namespace equinox
