/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"
#include "./mathematics/linear_algebra.hpp"

class UniformMatrix4f : public Uniform {
    public:
        UniformMatrix4f();
        UniformMatrix4f(std::string name);
        void load_matrix(Matrix4f value);

    private:
        Matrix4f buffer;
};
