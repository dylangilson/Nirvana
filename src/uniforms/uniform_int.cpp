/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_int.hpp"

UniformInt::UniformInt() {
    
}

UniformInt::UniformInt(std::string name) : Uniform(name) {
    used = false;
}

void UniformInt::load_int(int value) {
    if (!used || this->buffer != value) {
        glUniform1i(get_location(), value);

        this->buffer = value;
        used = true;
    }
}
