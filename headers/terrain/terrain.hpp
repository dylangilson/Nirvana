/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * February 2, 2023
 */

#pragma once

#include <vector>

#include "./models/raw_model.hpp"
#include "./render_engine/loader.hpp"
#include "./textures/model_texture.hpp"

class Terrain {
    public:
        Terrain(int x_length, int z_length, Loader loader, ModelTexture *texture);
        ~Terrain();
        RawModel *generate_terrain(Loader loader);
        RawModel *get_model();
        ModelTexture *get_texture();
        float get_x();
        float get_z();

    private:
        static constexpr float SIZE = 800; // length == width == SIZE
        static const int VERTEX_COUNT = 128; // number of vertices on each edge of terrain

        RawModel *model;
        ModelTexture *texture;
        float x; // position in x-axis
        float z; // position in z-axis
};
