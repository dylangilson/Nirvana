/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "vbo.hpp"

VBO::VBO(unsigned int type) {
    this->type = type;
    glGenBuffers(1, &id);
}

VBO::~VBO() {
    glDeleteBuffers(1, &id);
}

unsigned int VBO::get_vbo_id() {
    return id;
}

unsigned int VBO::get_type() {
    return type;
}

void VBO::bind() {
    glBindBuffer(type, id);
}

void VBO::unbind() {
    glBindBuffer(type, 0);
}

void VBO::store_data(float *data, size_t data_length) {
    glBufferData(type, data_length, data, GL_STATIC_DRAW);
}

void VBO::store_data(int *data, size_t data_length) {
    glBufferData(type, data_length, data, GL_STATIC_DRAW);
}
