/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform.hpp"

Uniform::Uniform() {
    
}

Uniform::Uniform(std::string name) {
    this->name = name;
}

Uniform::~Uniform() {

}

void Uniform::store_uniform_location(unsigned int program_id) {
    location = glGetUniformLocation(program_id, name.c_str());
}

int Uniform::get_location() {
    return location;
}
