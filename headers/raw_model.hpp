/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>

#include "vao.hpp"

class RawModel {
    public:
        RawModel(VAO *vao, int *indices, size_t vertex_count);
        ~RawModel();
        VAO *get_vao();
        int *get_indices();
        size_t get_vertex_count();    

    private:
        VAO *vao;
        int *indices;
        size_t vertex_count;
};
