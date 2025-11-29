/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 29, 2025
 */

#pragma once

#include "texture.hpp"

class TerrainTexture {
    public:
        TerrainTexture(Texture *texture);
        ~TerrainTexture();
        Texture *get_texture();
        unsigned int get_id();

    private:
        Texture *texture;
};
