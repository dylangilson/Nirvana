/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./models/raw_model.hpp"

RawModel::RawModel(VAO *vao, std::vector<unsigned int> indices) {
    this->vao = vao;
    this->indices = indices;
}

RawModel::~RawModel() {
    delete vao;
}

VAO *RawModel::get_vao() {
    return vao;
}

std::vector<unsigned int> RawModel::get_indices() {
    return indices;
}
