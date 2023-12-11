/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "uniform.hpp"

class UniformInt : public Uniform {
    public:
        UniformInt();
        UniformInt(std::string name);
        void load_int(int value);

    private:
        int value;
        bool used;
};
