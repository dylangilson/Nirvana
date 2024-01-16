/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./render_engine/renderer.hpp"

Renderer::Renderer() {
    shader = new EntityShader();

    create_projection_matrix();
    
    shader->start();
    shader->load_projection_matrix(projection_matrix);
    shader->stop();
}

Renderer::~Renderer() {
    delete shader;
}

EntityShader *Renderer::get_shader() {
    return shader;
}

void Renderer::prepare() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(Entity *entity) {
    TexturedModel *textured_model = entity->get_model();
    RawModel *model = textured_model->get_raw_model();
    model->get_vao()->bind(std::vector<int>());

    glEnableVertexAttribArray(0); // 0 -> position
    glEnableVertexAttribArray(1); // 1 -> texture coordinates
    glEnableVertexAttribArray(2); // 2 -> normal

    Matrix4f transformation_matrix = CameraAlgebra::create_transformation_matrix(entity->get_position(), entity->get_rotation(), entity->get_scale());
    shader->load_transformation_matrix(transformation_matrix);

    ModelTexture *texture = textured_model->get_model_texture();
    shader->load_specular_lighting(texture->get_shine_damper(), texture->get_reflectivity());

    textured_model->get_model_texture()->get_texture()->bind_to_unit(0);

    glDrawElements(GL_TRIANGLES, model->get_indices().size(), GL_UNSIGNED_INT, model->get_indices().data());

    glDisableVertexAttribArray(0); // 0 -> position
    glDisableVertexAttribArray(1); // 1 -> texture coordinates
    glDisableVertexAttribArray(2); // 2 -> normal
    
    model->get_vao()->unbind(std::vector<int>());
}

void Renderer::create_projection_matrix() {
    float aspect_ratio = (float)Display::WIDTH / (float)Display::HEIGHT;
    float y_scale = (1.0f / tan(FOV * PI / 180.0f / 2.0f)) * aspect_ratio;
    float x_scale = y_scale / aspect_ratio;
    float frustrum_length = FAR_PLANE - NEAR_PLANE;

    projection_matrix = ZERO_MATRIX;
    projection_matrix.m[0] = x_scale;
    projection_matrix.m[5] = y_scale;
    projection_matrix.m[10] = -((FAR_PLANE + NEAR_PLANE) / frustrum_length);
    projection_matrix.m[11] = -1.0f;
    projection_matrix.m[14] = -((2.0f * NEAR_PLANE * FAR_PLANE) / frustrum_length);
}
