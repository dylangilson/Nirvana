/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "vao.hpp"

#include <algorithm>

VAO::VAO() {
    glGenVertexArrays(1, &id);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &id);

    size_t vbos_count = vbos.size();

    for (size_t i = 0; i < vbos_count; i++) {
        delete vbos.at(i);
    }
}

unsigned int VAO::get_vao_id() {
    return id;
}

int VAO::get_index_count() {
    return index_count;
}

VBO *VAO::get_index_vbo() {
    return index_vbo;
}

void VAO::bind(int *attributes) {
    bind();

    if (attributes != NULL) {
        for (size_t i = 0; i < sizeof(attributes) / sizeof(int); i++) {
            glEnableVertexAttribArray(attributes[i]);
        }
    }
}

void VAO::unbind(int *attributes) {
    if (attributes != NULL) {
        for (size_t i = 0; i < sizeof(attributes) / sizeof(int); i++) {
            glDisableVertexAttribArray(attributes[i]);
        }
    }

    unbind();
}

void VAO::create_index_buffer(int *indices, size_t indices_length) {
    index_vbo = new VBO(GL_ELEMENT_ARRAY_BUFFER);
    index_vbo->bind();
    vbos.push_back(index_vbo);

    index_vbo->store_data(indices, indices_length);
    index_count = indices_length;

    index_vbo->unbind();
}

void VAO::create_attribute(unsigned int attribute_id, float *data, size_t data_length, size_t attribute_size) {
    VBO *vbo = new VBO(GL_ARRAY_BUFFER);
    vbo->bind();
    vbos.push_back(vbo);  

    vbo->store_data(data, data_length * sizeof(float));
    glVertexAttribPointer(attribute_id, attribute_size, GL_FLOAT, false, attribute_size * sizeof(float), (void *)0);

    vbo->unbind();
}

void VAO::create_attribute(unsigned int attribute_id, int *data, size_t data_length, size_t attribute_size) {
    VBO *vbo = new VBO(GL_ARRAY_BUFFER);
    vbo->bind();
    vbos.push_back(vbo);

    vbo->store_data(data, data_length * sizeof(int));
    glVertexAttribIPointer(attribute_id, attribute_size, GL_INT, attribute_size * sizeof(int), (void *)0);

    vbo->unbind();
}

void VAO::bind() {
    glBindVertexArray(id);
}

void VAO::unbind() {
    glBindVertexArray(0);
}
