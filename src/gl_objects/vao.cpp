/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./gl_objects/vao.hpp"

VAO::VAO() {
    glGenVertexArrays(1, &id);
    bind(std::vector<int>());
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &id);

    size_t vbos_count = vbos.size();

    for (size_t i = 0; i < vbos_count; i++) {
        delete vbos.at(i);
    }

    delete index_vbo;
}

unsigned int VAO::get_vao_id() {
    return id;
}

VBO *VAO::get_index_vbo() {
    return index_vbo;
}

void VAO::bind(std::vector<int> attributes) {
    bind();

    if (attributes.size() != 0) {
        for (size_t i = 0; i < attributes.size(); i++) {
            glEnableVertexAttribArray(attributes.at(i));
        }
    }
}

void VAO::unbind(std::vector<int> attributes) {
    if (attributes.size() != 0) {
        for (size_t i = 0; i < attributes.size(); i++) {
            glDisableVertexAttribArray(attributes.at(i));
        }
    }

    unbind();
}

void VAO::create_index_buffer(std::vector<int> indices) {
    index_vbo = new VBO(GL_ELEMENT_ARRAY_BUFFER);
    index_vbo->bind();

    index_vbo->store_data(indices);

    index_vbo->unbind();
}

void VAO::create_attribute(unsigned int attribute_id, std::vector<float> data, size_t attribute_size) {
    VBO *vbo = new VBO(GL_ARRAY_BUFFER);
    vbo->bind();
    vbos.push_back(vbo);  

    vbo->store_data(data);
    glVertexAttribPointer(attribute_id, attribute_size, GL_FLOAT, false, attribute_size * sizeof(float), (void *)0);

    vbo->unbind();
}

void VAO::create_attribute(unsigned int attribute_id, std::vector<int> data, size_t attribute_size) {
    VBO *vbo = new VBO(GL_ARRAY_BUFFER);
    vbo->bind();
    vbos.push_back(vbo);

    vbo->store_data(data);
    glVertexAttribIPointer(attribute_id, attribute_size, GL_INT, attribute_size * sizeof(int), (void *)0);

    vbo->unbind();
}

void VAO::bind() {
    glBindVertexArray(id);
}

void VAO::unbind() {
    glBindVertexArray(0);
}
