/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./mathematics/camera_algebra.hpp"
#include "./render_engine/outlining_renderer.hpp"

OutliningRenderer::OutliningRenderer(Matrix4f projection_matrix) {
    shader = new OutliningShader();
    
    shader->start();
    shader->load_projection_matrix(projection_matrix);
    shader->stop();
}

OutliningRenderer::~OutliningRenderer() {
    delete shader;
}

OutliningShader *OutliningRenderer::get_shader() {
    return shader;
}

void OutliningRenderer::prepare_instance(Entity *entity) {
    Matrix4f transformation_matrix = CameraAlgebra::create_transformation_matrix(entity->get_position(), entity->get_rotation(), entity->get_scale() * 1.015);
    shader->load_transformation_matrix(transformation_matrix);
}

void OutliningRenderer::prepare_textured_model(TexturedModel *textured_model) {
    RawModel *model = textured_model->get_raw_model();
    model->get_vao()->bind(std::vector<int>());

    glEnableVertexAttribArray(0); // 0 -> position

    textured_model->get_model_texture()->get_texture()->bind_to_unit(0);
}

void OutliningRenderer::unbind_textured_model(TexturedModel *textured_model) {
    glDisableVertexAttribArray(0); // 0 -> position
    
    textured_model->get_raw_model()->get_vao()->unbind(std::vector<int>());
}

void OutliningRenderer::render(Entity *entity) {
    TexturedModel *textured_model = entity->get_model();

    prepare_textured_model(textured_model);
    prepare_instance(entity);

    glDrawElements(GL_TRIANGLES, textured_model->get_raw_model()->get_indices().size(), GL_UNSIGNED_INT, textured_model->get_raw_model()->get_indices().data());

    unbind_textured_model(textured_model);
}
