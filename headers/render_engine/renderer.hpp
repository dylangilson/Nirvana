/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include "./models/raw_model.hpp"

class Renderer {
    public:
        void prepare();
        void render(RawModel *model);
};