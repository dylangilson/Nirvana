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
    shader->connect_texture_units();

    shader->stop();
}

TerrainRenderer::~TerrainRenderer() {
    delete shader;
}

TerrainShader *TerrainRenderer::get_shader() {
    return shader;
}

void TerrainRenderer::render(std::vector<Terrain *> terrains) {
    for (size_t i = 0; i < terrains.size(); i++) {
        Terrain *terrain = terrains.at(i);

        prepare_terrain(terrain);
        load_model_matrix(terrain);

        RawModel *model = terrain->get_model();

        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(model->get_indices().size()), GL_UNSIGNED_INT, model->get_indices().data());

        unbind_textured_model(terrain);
    }
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

    bind_textures(terrain);

    shader->load_specular_lighting(1.0f, 0.0f);
}

void TerrainRenderer::unbind_textured_model(Terrain *terrain) {
    glDisableVertexAttribArray(0); // 0 -> position
    glDisableVertexAttribArray(1); // 1 -> normal
    glDisableVertexAttribArray(2); // 2 -> texture coordinates
    
    RawModel *model = terrain->get_model();
    model->get_vao()->unbind(std::vector<int>());
}

void TerrainRenderer::bind_textures(Terrain *terrain) {
    TerrainTexturePack *texture_pack = terrain->get_texture_pack();
    TerrainTexture *background_texture = texture_pack->get_background_texture();
    TerrainTexture *red_texture = texture_pack->get_red_texture();
    TerrainTexture *green_texture = texture_pack->get_green_texture();
    TerrainTexture *blue_texture = texture_pack->get_blue_texture();
    TerrainTexture *blend_map = terrain->get_blend_map();

    background_texture->get_texture()->bind_to_unit(0);
    background_texture->get_texture()->bind();

    red_texture->get_texture()->bind_to_unit(1);
    red_texture->get_texture()->bind();

    green_texture->get_texture()->bind_to_unit(2);
    green_texture->get_texture()->bind();

    blue_texture->get_texture()->bind_to_unit(3);
    blue_texture->get_texture()->bind();

    blend_map->get_texture()->bind_to_unit(4);
    blend_map->get_texture()->bind();
}
