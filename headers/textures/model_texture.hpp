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
        float get_shine_damper();
        void set_shine_damper(float shine_damper);
        float get_reflectivity();
        void set_reflectivity(float reflectivity);

    private:
        Texture *texture;
        float shine_damper = 1.0f;
        float reflectivity = 0.0f;
};
