/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <stdlib.h>

#include "raw_model.hpp"
#include "vao.hpp"
#include "vbo.hpp"

class Loader {
    public:
        RawModel *load_to_vao(std::vector<float> positions, std::vector<int> indices);
};
