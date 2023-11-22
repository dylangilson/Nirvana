/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./gl_objects/vbo.hpp"

VBO::VBO() {
    glGenBuffers(1, &id);
}

VBO::~VBO() {
    destroy();
}

unsigned int VBO::get_id() {
    return id;
}

void VBO::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::store_data(std::vector<float> data) {
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
}

void VBO::store_data(std::vector<int> data) {
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(int), data.data(), GL_STATIC_DRAW);
}

void VBO::destroy() {
    glDeleteBuffers(1, &id);

    id = 0;
}
