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
        std::ostream& operator<<(std::ostream& stream, const vector2& vector)
        {
            stream << "vector2: [" << vector.x << ", " << vector.y << "]";
            return stream;
        }

        vector2& operator+(vector2& current, const vector2& other)
        {
            return current.add(other);
        }

    } // namespace math
        
} // namespace equinox
