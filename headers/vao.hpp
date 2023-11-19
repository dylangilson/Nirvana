/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>
#include <vector>

#include "vbo.hpp"

class VAO {
    public:
        VAO();
        ~VAO();
        unsigned int get_vao_id();
        int get_index_count();
        VBO *get_index_vbo();
        void bind(std::vector<int> attributes);
        void unbind(std::vector<int> attributes);
        void create_index_buffer(std::vector<int> indices);
        void create_attribute(unsigned int attribute_id, std::vector<float> data, size_t attribute_size);
        void create_attribute(unsigned int attribute_id, std::vector<int> data, size_t attribute_size);

    private:
        std::vector<VBO *> vbos;
        unsigned int id;
        VBO *index_vbo;
        size_t index_count;

        void bind();
        void unbind();
};
