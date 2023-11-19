/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "raw_model.hpp"

RawModel::RawModel(VAO *vao, std::vector<int> indices) {
    this->vao = vao;
    this->indices = indices;
}

// TODO: re-enable delete indices once theyre dynamically allocated from obj files
RawModel::~RawModel() {
    delete vao;
    // delete[] indices;
}

VAO *RawModel::get_vao() {
    return vao;
}

std::vector<int> RawModel::get_indices() {
    return indices;
}
