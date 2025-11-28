/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./uniforms/uniform_sampler.hpp"

UniformSampler::UniformSampler() {
    
}

UniformSampler::UniformSampler(std::string name) : Uniform(name) {
    used = false;
}

void UniformSampler::load_texture_unit(int value) {
    if (!used || this->buffer != value) {
        glUniform1i(get_location(), value);

        this->buffer = value;
        used = true;
    }
}
