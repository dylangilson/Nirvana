/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"
#include "./mathematics/linear_algebra.hpp"

class UniformVector2f : public Uniform {
    public:
        UniformVector2f(std::string name);
        void load_vector(Vector2f value);

    private:
        Vector2f value;
        bool used;
};
