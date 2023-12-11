/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_vector2f.hpp"

UniformVector2f::UniformVector2f() {
    
}

UniformVector2f::UniformVector2f(std::string name) : Uniform(name) {
    used = false;
}

void UniformVector2f::load_vector(Vector2f value) {
    if (!used) {
        glUniform2f(get_location(), value.x, value.y);

        this->value = value;
        used = true;
    }
}
