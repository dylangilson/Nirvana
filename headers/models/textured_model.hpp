/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#pragma once

#include "raw_model.hpp"
#include "./textures/model_texture.hpp"

class TexturedModel {
    public:
        TexturedModel(RawModel *model, ModelTexture *texture);
        ~TexturedModel();
        RawModel *get_raw_model();
        ModelTexture *get_model_texture();

    private:
        RawModel *model;
        ModelTexture *texture;
};