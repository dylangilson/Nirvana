/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>

#include <GL/glew.h>

class VBO {
    public:
        VBO(unsigned int type);
        ~VBO();
        unsigned int get_vbo_id();
        unsigned int get_type();
        void bind();
        void unbind();
        void store_data(float *data, size_t data_length);
        void store_data(int *data, size_t data_length);

    private:
        unsigned int id;
        unsigned int type;
};
