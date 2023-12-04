/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_int.hpp"

UniformInt::UniformInt(std::string name) : Uniform(name) {
    used = false;
}

void UniformInt::load_int(int value) {
    if (!used || this->value != value) {
        glUniform1i(get_location(), value);

        this->value = value;
        used = true;
    }
}
