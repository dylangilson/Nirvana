/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./gl_objects/vao.hpp"

VAO::VAO() {
    glGenVertexArrays(1, &id);
    bind();
}

VAO::~VAO() {
    destroy();
}

unsigned int VAO::get_id() {
    return id;
}

EBO *VAO::get_ebo() {
    return ebo;
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

void VAO::create_ebo(std::vector<int> indices) {
    ebo = new EBO();
    ebo->bind();

    ebo->store_data(indices);

    ebo->unbind();
}

void VAO::create_attribute(unsigned int attribute_id, size_t attribute_size, std::vector<float> data) {
    VBO *vbo = new VBO();
    vbo->bind();
    
    vbos.push_back(vbo);  

    vbo->store_data(data);
    glVertexAttribPointer(attribute_id, attribute_size, GL_FLOAT, false, attribute_size * sizeof(float), (void *)0);

    vbo->unbind();
}

void VAO::create_attribute(unsigned int attribute_id, size_t attribute_size, std::vector<int> data) {
    VBO *vbo = new VBO();
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

void VAO::destroy() {
    glDeleteVertexArrays(1, &id);

    size_t vbos_count = vbos.size();

    for (size_t i = 0; i < vbos_count; i++) {
        delete vbos.at(i);
    }

    delete ebo;

    id = 0;
}
