/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 29, 2025
 */

#include "./textures/terrain_texture.hpp"

TerrainTexture::TerrainTexture(Texture *texture) {
    this->texture = texture;
}

TerrainTexture::~TerrainTexture() {
    delete texture;
}

Texture *TerrainTexture::get_texture() {
    return texture;
}

unsigned int TerrainTexture::get_id() {
    return texture->get_id();
}
