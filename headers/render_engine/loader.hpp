/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>

#include "./models/raw_model.hpp"
#include "./gl_objects/vao.hpp"
#include "./gl_objects/vbo.hpp"

class Loader {
    public:
        RawModel *load_raw_model(std::vector<float> positions, std::vector<int> indices);
};
