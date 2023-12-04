/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"

class UniformBool : public Uniform {
    public:
        UniformBool(std::string name);
        void load_bool(bool value);

    private:
        bool value;
        bool used;
};
