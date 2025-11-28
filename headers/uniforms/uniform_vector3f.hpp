/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"
#include "./mathematics/linear_algebra.hpp"

class UniformVector3f : public Uniform {
    public:
        UniformVector3f();
        UniformVector3f(std::string name);
        void load_vector(Vector3f value);

    private:
        Vector3f buffer;
        bool used;
};
