/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>
#include <vector>

#include "./gl_objects/vao.hpp"

class RawModel {
    public:
        RawModel(VAO *vao, std::vector<int> indices);
        ~RawModel();
        VAO *get_vao();
        std::vector<int> get_indices();   

    private:
        VAO *vao;
        std::vector<int> indices;
};
