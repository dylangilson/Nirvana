/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./textures/model_texture.hpp"

ModelTexture::ModelTexture(Texture *texture) {
    this->texture = texture;
}

ModelTexture::~ModelTexture() {
    delete texture;
}

Texture *ModelTexture::get_texture() {
    return texture;
}

unsigned int ModelTexture::get_id() {
    return texture->get_id();
}
