/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include "./engine/glad.hpp"

#include <string>
#include <vector>

#include "./models/raw_model.hpp"
#include "./textures/texture.hpp"
#include "./gl_objects/vao.hpp"
#include "./gl_objects/vbo.hpp"

class Loader {
    public:
        RawModel *load_raw_model(std::vector<float> positions, std::vector<unsigned int> indices, std::vector<float> normals, std::vector<float> texture_coordinates);
        Texture *load_texture(std::string filename);
};
