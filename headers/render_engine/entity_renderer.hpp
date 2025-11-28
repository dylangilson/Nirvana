/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#pragma once

#include <iterator>
#include <map>
#include <vector>

#include "./entities/entity.hpp"
#include "./mathematics/camera_algebra.hpp"
#include "./mathematics/linear_algebra.hpp"
#include "./models/raw_model.hpp"
#include "./models/textured_model.hpp"
#include "./shaders/entity_shader.hpp"

class EntityRenderer {
    public:
        EntityRenderer(Matrix4f projection_matrix);
        ~EntityRenderer();
        EntityShader *get_shader();
        void prepare_instance(Entity *entity);
        void prepare_textured_model(TexturedModel *textured_model);
        void unbind_textured_model(TexturedModel *textured_model);
        void render(std::map<TexturedModel *, std::vector<Entity *>> entities);

    private:
        EntityShader *shader;
};
