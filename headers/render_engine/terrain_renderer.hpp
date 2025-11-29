/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * February 3, 2023
 */

#pragma once

#include <vector>

#include "./entities/entity.hpp"
#include "./mathematics/camera_algebra.hpp"
#include "./mathematics/linear_algebra.hpp"
#include "./models/raw_model.hpp"
#include "./models/textured_model.hpp"
#include "./shaders/terrain_shader.hpp"
#include "./terrain/terrain.hpp"
#include "./textures/terrain_texture_pack.hpp"

class TerrainRenderer {
    public:
        TerrainRenderer(Matrix4f projection_matrix);
        ~TerrainRenderer();
        TerrainShader *get_shader();
        void render(std::vector<Terrain *> terrains);

    private:
        TerrainShader *shader;

        void load_model_matrix(Terrain *terrain);
        void prepare_terrain(Terrain *terrain);
        void unbind_textured_model(Terrain *terrain);
        void bind_textures(Terrain *terrain);
};
