/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./render_engine/loader.hpp"

RawModel *Loader::load_raw_model(std::vector<float> positions, std::vector<int> indices) {
    VAO *vao = new VAO();
    vao->bind(std::vector<int>());

    vao->create_attribute(0, positions, 3);
    vao->create_ebo(indices);

    vao->unbind(std::vector<int>());

    return new RawModel(vao, indices);
}
