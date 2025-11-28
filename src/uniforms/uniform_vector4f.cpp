/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_vector4f.hpp"

UniformVector4f::UniformVector4f() {
    
}

UniformVector4f::UniformVector4f(std::string name) : Uniform(name) {
    used = false;
}

void UniformVector4f::load_vector(Vector4f value) {
    if (!used) {
        glUniform4f(get_location(), value.x, value.y, value.z, value.w);

        this->buffer = value;
        used = true;
    }
}
