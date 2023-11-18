/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "raw_model.hpp"

RawModel::RawModel(VAO *vao, int *indices, size_t vertex_count) {
    this->vao = vao;
    this->indices = indices;
    this->vertex_count = vertex_count;
}

// TODO: re-enable delete indices once theyre dynamically allocated from obj files
RawModel::~RawModel() {
    delete vao;
    // delete[] indices;
}

VAO *RawModel::get_vao() {
    return vao;
}

int *RawModel::get_indices() {
    return indices;
}

size_t RawModel::get_vertex_count() {
    return vertex_count;
}
