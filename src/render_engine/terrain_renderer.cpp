/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * February 3, 2023
 */

#include "./render_engine/terrain_renderer.hpp"

TerrainRenderer::TerrainRenderer(Matrix4f projection_matrix) {
    shader = new TerrainShader();

    shader->start();
    shader->load_projection_matrix(projection_matrix);
    shader->stop();
}

TerrainRenderer::~TerrainRenderer() {
    delete shader;
}

TerrainShader *TerrainRenderer::get_shader() {
    return shader;
}

void TerrainRenderer::load_model_matrix(Terrain *terrain) {
    Matrix4f transformation_matrix = CameraAlgebra::create_transformation_matrix(Vector3f(terrain->get_x(), 0.0f, terrain->get_z()), Vector3f(0.0f, 0.0f, 0.0f), 1.0f);
    shader->load_transformation_matrix(transformation_matrix);
}

void TerrainRenderer::prepare_terrain(Terrain *terrain) {
    RawModel *model = terrain->get_model();
    model->get_vao()->bind(std::vector<int>());

    glEnableVertexAttribArray(0); // 0 -> position
    glEnableVertexAttribArray(1); // 1 -> normal
    glEnableVertexAttribArray(2); // 2 -> texture coordinates

    ModelTexture *texture = terrain->get_texture();
    shader->load_specular_lighting(texture->get_shine_damper(), texture->get_reflectivity());

    texture->get_texture()->bind_to_unit(0);
}

void TerrainRenderer::unbind_textured_model(Terrain *terrain) {
    glDisableVertexAttribArray(0); // 0 -> position
    glDisableVertexAttribArray(1); // 1 -> normal
    glDisableVertexAttribArray(2); // 2 -> texture coordinates
    
    RawModel *model = terrain->get_model();
    model->get_vao()->unbind(std::vector<int>());
}

void TerrainRenderer::render(std::vector<Terrain *> terrains) {
    for (size_t i = 0; i < terrains.size(); i++) {
        Terrain *terrain = terrains.at(i);

        prepare_terrain(terrain);
        load_model_matrix(terrain);

        RawModel *model = terrain->get_model();

        glDrawElements(GL_TRIANGLES, model->get_indices().size(), GL_UNSIGNED_INT, model->get_indices().data());

        unbind_textured_model(terrain);
    }
}
