/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_vector3f.hpp"

UniformVector3f::UniformVector3f() {
    
}

UniformVector3f::UniformVector3f(std::string name) : Uniform(name) {
    used = false;
}

void UniformVector3f::load_vector(Vector3f value) {
    if (!used) {
        glUniform3f(get_location(), value.x, value.y, value.z);

        this->value = value;
        used = true;
    }
}
