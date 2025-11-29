/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * February 2, 2023
 */

#pragma once

#include <vector>

#include "./models/raw_model.hpp"
#include "./render_engine/loader.hpp"
#include "./textures/terrain_texture.hpp"
#include "./textures/terrain_texture_pack.hpp"

class Terrain {
    public:
        Terrain(int x_length, int z_length, Loader loader, TerrainTexturePack *texture_pack, TerrainTexture *blend_map);
        ~Terrain();
        RawModel *generate_terrain(Loader loader);
        RawModel *get_model();
        TerrainTexturePack *get_texture_pack();
        TerrainTexture *get_blend_map();
        float get_x();
        float get_z();

    private:
        static constexpr float SIZE = 800.0; // length == width == SIZE
        static const int VERTEX_COUNT = 128; // number of vertices on each edge of terrain

        RawModel *model;
        TerrainTexturePack *texture_pack;
        TerrainTexture *blend_map;
        float x; // position in x-axis
        float z; // position in z-axis
};
