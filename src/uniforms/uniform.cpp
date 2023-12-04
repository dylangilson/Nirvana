/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform.hpp"

Uniform::Uniform(std::string name) {
    this->name = name;
}

void Uniform::store_uniform_location(unsigned int program_id) {
    location = glGetUniformLocation(program_id, name.c_str());
}

unsigned int Uniform::get_location() {
    return location;
}
