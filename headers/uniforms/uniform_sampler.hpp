/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"

class UniformSampler : public Uniform {
    public:
        UniformSampler();
        UniformSampler(std::string name);
        void load_texture_unit(int value);

    private:
        int value;
        bool used;
};
