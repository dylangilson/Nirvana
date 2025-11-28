/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 15, 2024
 */

#pragma once

#include <map>
#include <vector>

#include "entity_renderer.hpp"
#include "outlining_renderer.hpp"
#include "terrain_renderer.hpp"
#include "./entities/entity.hpp"
#include "./entities/light.hpp"
#include "./entities/camera.hpp"
#include "./models/textured_model.hpp"
#include "./shaders/entity_shader.hpp"
#include "./terrain/terrain.hpp"

class MasterRenderer {
    public:
        MasterRenderer();
        ~MasterRenderer();
        EntityRenderer *get_entity_renderer();
        OutliningRenderer *get_outlining_renderer();
        TerrainRenderer *get_terrain_renderer();

        void prepare();
        void render(Light sun, Camera camera);
        static void enable_culling();
        static void disable_culling();
        void process_entity(Entity *entity);
        void process_terrain(Terrain *terrain);

    private:
        static constexpr float FOV = 70.0f;
        static constexpr float NEAR_PLANE = 0.1f; // nearest visible point of view
        static constexpr float FAR_PLANE = 1000.0f; // furthest visible point of view
        static constexpr float RED = 0.0f;
        static constexpr float GREEN = 0.0f;
        static constexpr float BLUE = 0.0f;
        Matrix4f projection_matrix;
        EntityRenderer *entity_renderer;
        OutliningRenderer *outlining_renderer;
        TerrainRenderer *terrain_renderer;
        std::map<TexturedModel *, std::vector<Entity *>> entities;
        std::vector<Terrain *> terrains;
        
        void create_projection_matrix();
};
