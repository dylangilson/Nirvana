/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./render_engine/entity_renderer.hpp"
#include "./render_engine/master_renderer.hpp"

EntityRenderer::EntityRenderer(Matrix4f projection_matrix) {
    shader = new EntityShader();
    
    shader->start();
    shader->load_projection_matrix(projection_matrix);
    shader->stop();
}

EntityRenderer::~EntityRenderer() {
    delete shader;
}

EntityShader *EntityRenderer::get_shader() {
    return shader;
}

void EntityRenderer::prepare_instance(Entity *entity) {
    Matrix4f transformation_matrix = CameraAlgebra::create_transformation_matrix(entity->get_position(), entity->get_rotation(), entity->get_scale());
    shader->load_transformation_matrix(transformation_matrix);
}

void EntityRenderer::prepare_textured_model(TexturedModel *textured_model) {
    RawModel *model = textured_model->get_raw_model();
    model->get_vao()->bind(std::vector<int>());

    glEnableVertexAttribArray(0); // 0 -> position
    glEnableVertexAttribArray(1); // 1 -> normal
    glEnableVertexAttribArray(2); // 2 -> texture coordinates

    ModelTexture *texture = textured_model->get_model_texture();
    if (texture->get_transparency()) {
        MasterRenderer::disable_culling();
    }

    shader->load_transparency(texture->get_transparency());
    shader->load_fake_lighting(texture->get_use_fake_lighting());
    shader->load_specular_lighting(texture->get_shine_damper(), texture->get_reflectivity());

    textured_model->get_model_texture()->get_texture()->bind_to_unit(0);
}

void EntityRenderer::unbind_textured_model(TexturedModel *textured_model) {
    MasterRenderer::enable_culling();

    glDisableVertexAttribArray(0); // 0 -> position
    glDisableVertexAttribArray(1); // 1 -> normal
    glDisableVertexAttribArray(2); // 2 -> texture coordinates
    
    textured_model->get_raw_model()->get_vao()->unbind(std::vector<int>());
}

void EntityRenderer::render(std::map<TexturedModel *, std::vector<Entity *>> entities) {
    std::map<TexturedModel *, std::vector<Entity *>>::iterator iter;

    for (iter = entities.begin(); iter != entities.end(); iter++) {
        TexturedModel *textured_model = iter->first;

        prepare_textured_model(textured_model);

        std::vector<Entity *> batch = entities[textured_model];
        for (size_t i = 0; i < batch.size(); i++) {
            Entity *entity = batch.at(i);
            prepare_instance(entity);

            glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(textured_model->get_raw_model()->get_indices().size()), GL_UNSIGNED_INT, textured_model->get_raw_model()->get_indices().data());
        }

        unbind_textured_model(textured_model);
    }
}
