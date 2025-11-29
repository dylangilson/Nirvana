/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 29, 2025
 */

#pragma once

#include "terrain_texture.hpp"

class TerrainTexturePack {
    public:
        TerrainTexturePack(TerrainTexture *background, TerrainTexture *red, TerrainTexture *green, TerrainTexture *blue);
        ~TerrainTexturePack();
        TerrainTexture *get_background_texture();
        TerrainTexture *get_red_texture();
        TerrainTexture *get_green_texture();
        TerrainTexture *get_blue_texture();

    private:
        TerrainTexture *background_texture;
        TerrainTexture *red_texture;
        TerrainTexture *green_texture;
        TerrainTexture *blue_texture;
};
