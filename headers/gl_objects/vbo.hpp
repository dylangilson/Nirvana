/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>
#include <vector>

#include "./engine/glad.hpp"

class VBO {
    public:
        VBO(unsigned int type);
        ~VBO();
        unsigned int get_vbo_id();
        unsigned int get_type();
        void bind();
        void unbind();
        void store_data(std::vector<float> data);
        void store_data(std::vector<int> data);

    private:
        unsigned int id;
        unsigned int type;
};
