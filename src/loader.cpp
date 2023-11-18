/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "loader.hpp"

RawModel *Loader::load_to_vao(float *positions, int *indices, size_t positions_length, size_t indices_length) {
    VAO *vao = new VAO();
    vao->bind(NULL);
    vaos.push_back(vao);

    vao->create_attribute(0, positions, positions_length, 3);
    vao->create_index_buffer(indices, indices_length);

    vao->unbind(NULL);

    return new RawModel(vao, indices, indices_length);
}
