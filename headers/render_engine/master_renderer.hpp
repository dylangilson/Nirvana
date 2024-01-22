/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * January 15, 2024
 */

#pragma once

#include <unordered_map>
#include <vector>

#include "entity_renderer.hpp"
#include "outlining_renderer.hpp"
#include "./entities/entity.hpp"
#include "./entities/light.hpp"
#include "./entities/camera.hpp"
#include "./models/textured_model.hpp"
#include "./shaders/entity_shader.hpp"

class MasterRenderer {
    public:
        MasterRenderer();
        ~MasterRenderer();
        EntityRenderer *get_entity_renderer();
        OutliningRenderer *get_outlining_renderer();

        void prepare();
        void render(Light sun, Camera camera);
        void process_entity(Entity *entity);

    private:
        static constexpr float FOV = 70.0f;
        static constexpr float NEAR_PLANE = 0.1f; // nearest visible point of view
        static constexpr float FAR_PLANE = 1000.0f; // furthest visible point of view
        Matrix4f projection_matrix;
        EntityRenderer *entity_renderer;
        OutliningRenderer *outlining_renderer;
        std::unordered_map<TexturedModel *, std::vector<Entity *>> entities;
        
        void create_projection_matrix();
};
