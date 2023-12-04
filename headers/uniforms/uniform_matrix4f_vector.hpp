/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include <vector>

#include "uniform.hpp"
#include "uniform_matrix4f.hpp"
#include "./mathematics/linear_algebra.hpp"

class UniformMatrix4fVector : public Uniform {
    public:
        UniformMatrix4fVector(std::string name, size_t count);
        void load_matrix4f_vector(std::vector<Matrix4f> value);
        void store_uniform_location(unsigned int program_id) override {
            for (size_t i = 0; i < count; i++) {
                value.at(i).store_uniform_location(program_id);
            }
        }

    private:
        std::vector<UniformMatrix4f> value;
        size_t count;
};
