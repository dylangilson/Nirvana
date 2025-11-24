/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <vector>

#include "./gl_objects/vao.hpp"

class RawModel {
    public:
        RawModel(VAO *vao, std::vector<unsigned int> indices);
        ~RawModel();
        VAO *get_vao();
        std::vector<unsigned int> get_indices();   

    private:
        VAO *vao;
        std::vector<unsigned int> indices;
};
