/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 21, 2023
 */

#include "./gl_objects/ebo.hpp"

EBO::EBO() {
    glGenBuffers(1, &id);
}

EBO::~EBO() {
    destroy();
}

unsigned int EBO::get_id() {
    return id;
}

void EBO::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::store_data(std::vector<unsigned int> data) {
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(int), data.data(), GL_STATIC_DRAW);
}

void EBO::destroy() {
    glDeleteBuffers(1, &id);

    id = 0;
}
