/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>

#include "raw_model.hpp"
#include "vao.hpp"
#include "vbo.hpp"

class Loader {
    public:
        RawModel *load_to_vao(float *positions, int *indices, size_t data_length, size_t indices_length);

    private:
        std::vector<VAO *> vaos;
        std::vector<VBO *> vbos;
};
