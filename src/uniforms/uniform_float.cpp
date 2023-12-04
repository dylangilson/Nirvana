/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_float.hpp"

UniformFloat::UniformFloat(std::string name) : Uniform(name) {
    used = false;
}

void UniformFloat::load_float(float value) {
    if (!used || this->value != value) {
        glUniform1f(get_location(), value);

        this->value = value;
        used = true;
    }
}
