/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#include "./shaders/entity_shader.hpp"

std::string EntityShader::VERTEX_SHADER_FILE = "./shaders/entity_vertex_shader.glsl";
std::string EntityShader::FRAGMENT_SHADER_FILE = "./shaders/entity_fragment_shader.glsl";

EntityShader::EntityShader() : ShaderProgram(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE) {
    transformation_matrix = new UniformMatrix4f("transformation_matrix");
    projection_matrix = new UniformMatrix4f("projection_matrix");
    view_matrix = new UniformMatrix4f("view_matrix");

    store_all_uniform_locations(std::vector<Uniform *> {
        transformation_matrix, projection_matrix, view_matrix
    });
}

EntityShader::~EntityShader() {
    delete transformation_matrix;
    delete projection_matrix;
    delete view_matrix;
}

void EntityShader::bind_attributes() {
    bind_attribute(0, "in_position"); // 0 -> position
    bind_attribute(1, "in_texture_coordinates"); // 1 -> texture coordinates
}

void EntityShader::load_transformation_matrix(Matrix4f matrix) {
    transformation_matrix->load_matrix(matrix);
}

void EntityShader::load_projection_matrix(Matrix4f matrix) {
    projection_matrix->load_matrix(matrix);
}

void EntityShader::load_view_matrix(Camera camera) {
    Matrix4f matrix = CameraAlgebra::create_view_matrix(camera);

    view_matrix->load_matrix(matrix);
}
