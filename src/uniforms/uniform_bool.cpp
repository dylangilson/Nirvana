/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_bool.hpp"

UniformBool::UniformBool() {
    
}

UniformBool::UniformBool(std::string name) : Uniform(name) {
    used = false;
}

void UniformBool::load_bool(bool value) {
    if (!used || this->value != value) {
        glUniform1f(get_location(), value ? 1.0f : 0.0f);

        this->value = value;
        used = true;
    }
}
