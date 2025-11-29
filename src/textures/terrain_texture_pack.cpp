/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 29, 2025
 */

#include "./textures/terrain_texture_pack.hpp"

TerrainTexturePack::TerrainTexturePack(TerrainTexture *background, TerrainTexture *red, TerrainTexture *green, TerrainTexture *blue) {
    this->background_texture = background;
    this->red_texture = red;
    this->green_texture = green;
    this->blue_texture = blue;
}

TerrainTexturePack::~TerrainTexturePack() {
    delete background_texture;
    delete red_texture;
    delete green_texture;
    delete blue_texture;
}

TerrainTexture *TerrainTexturePack::get_background_texture() {
    return background_texture;
}

TerrainTexture *TerrainTexturePack::get_red_texture() {
    return red_texture;
}

TerrainTexture *TerrainTexturePack::get_green_texture() {
    return green_texture;
}

TerrainTexture *TerrainTexturePack::get_blue_texture() {
    return blue_texture;
}
