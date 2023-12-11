/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"
#include "./mathematics/linear_algebra.hpp"

class UniformVector4f : public Uniform {
    public:
        UniformVector4f();
        UniformVector4f(std::string name);
        void load_vector(Vector4f value);

    private:
        Vector4f value;
        bool used;
};
