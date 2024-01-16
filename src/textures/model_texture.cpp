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

float ModelTexture::get_shine_damper() {
    return shine_damper;
}

void ModelTexture::set_shine_damper(float shine_damper) {
    this->shine_damper = shine_damper;
}

float ModelTexture::get_reflectivity() {
    return reflectivity;
}

void ModelTexture::set_reflectivity(float reflectivity) {
    this->reflectivity = reflectivity;
}
