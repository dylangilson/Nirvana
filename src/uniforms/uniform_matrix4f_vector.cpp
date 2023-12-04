/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_matrix4f_vector.hpp"

UniformMatrix4fVector::UniformMatrix4fVector(std::string name, size_t count) : Uniform(name) {
    this->count = count;

    for (size_t i = 0; i < count; i++) {
        value.push_back(UniformMatrix4f(name + "[" + std::to_string(i) + "]"));
    }
}

void UniformMatrix4fVector::load_matrix4f_vector(std::vector<Matrix4f> matrices) {
    for (size_t i = 0; i < count; i++) {
        value.at(i).load_matrix(matrices.at(i));
    }
}
