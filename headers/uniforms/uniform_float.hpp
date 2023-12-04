/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"

class UniformFloat : public Uniform {
    public:
        UniformFloat(std::string name);
        void load_float(float value);

    private:
        float value;
        bool used;
};
