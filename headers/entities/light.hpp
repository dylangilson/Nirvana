/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 15, 2024
 */

#pragma once

#include "../mathematics/linear_algebra.hpp"

class Light {
    public:
        Light(Vector3f position, Vector3f colour);
        Vector3f get_position();
        void set_position(Vector3f position);
        Vector3f get_colour();
        void set_colour(Vector3f colour);

    private:
        Vector3f position;
        Vector3f colour;
};
