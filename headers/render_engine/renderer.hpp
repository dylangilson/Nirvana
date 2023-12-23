/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include "display.hpp"
#include "./mathematics/camera_algebra.hpp"
#include "./mathematics/linear_algebra.hpp"
#include "./entities/entity.hpp"
#include "./shaders/entity_shader.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();
        EntityShader *get_shader();
        void prepare();
        void render(Entity *entity);

    private:
        static constexpr float FOV = 70.0f;
        static constexpr float NEAR_PLANE = 0.1f; // nearest visible point of view
        static constexpr float FAR_PLANE = 1000.0f; // furthest visible point of view
        EntityShader *shader;
        Matrix4f projection_matrix;

        void create_projection_matrix();
};
