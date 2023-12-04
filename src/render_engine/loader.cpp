/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./render_engine/loader.hpp"

RawModel *Loader::load_raw_model(std::vector<float> positions, std::vector<int> indices, std::vector<float> texture_coordinates) {
    VAO *vao = new VAO();
    vao->bind(std::vector<int>());

    vao->create_attribute(0, positions, 3);
    vao->create_ebo(indices);
    vao->create_attribute(1, texture_coordinates, 2);

    vao->unbind(std::vector<int>());

    return new RawModel(vao, indices);
}

Texture *Loader::load_texture(std::string file_name) {
    Texture *texture = new Texture();
    texture->bind();
    texture->set_parameters();

    std::string file_path = "../res/textures/" + file_name + ".png";
    texture->load_data(file_path);
    
    texture->unbind();

    return texture;
}
