/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#pragma once

#include "./entities/entity.hpp"
#include "./models/textured_model.hpp"
#include "./mathematics/linear_algebra.hpp"
#include "./shaders/outlining_shader.hpp"

class OutliningRenderer {
    public:
        OutliningRenderer(Matrix4f projection_matrix);
        ~OutliningRenderer();
        OutliningShader *get_shader();
        void prepare_instance(Entity *entity);
        void prepare_textured_model(TexturedModel *textured_model);
        void unbind_textured_model(TexturedModel *textured_model);
        void render(Entity *entity);

    private:
        OutliningShader *shader;
};
