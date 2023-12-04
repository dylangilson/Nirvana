/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * December 3, 2023
 */

#include "./models/textured_model.hpp"

TexturedModel::TexturedModel(RawModel *model, ModelTexture *texture) {
    this->model = model;
    this->texture = texture;
}

TexturedModel::~TexturedModel() {
    delete model;
    delete texture;
}

RawModel *TexturedModel::get_raw_model() {
    return model;
}

ModelTexture *TexturedModel::get_model_texture() {
    return texture;
}
