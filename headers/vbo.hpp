/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>
#include <vector>

#include <GL/glew.h>

class VBO {
    public:
        VBO(unsigned int type);
        ~VBO();
        unsigned int get_vbo_id();
        unsigned int get_type();
        void bind();
        void unbind();
        void store_data(std::vector<float> data, size_t data_length);
        void store_data(std::vector<int> data, size_t data_length);

    private:
        unsigned int id;
        unsigned int type;
};
