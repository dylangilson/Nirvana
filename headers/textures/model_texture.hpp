/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "texture.hpp"

class ModelTexture {
    public:
        ModelTexture(Texture *texture);
        ~ModelTexture();
        Texture *get_texture();
        unsigned int get_id();

    private:
        Texture *texture;
};
