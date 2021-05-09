#pragma once
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

            
        };
        
    } // namespace math
} // namespace equinox
