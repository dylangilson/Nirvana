/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * Novmeber 3, 2023
 */

#include "./shaders/outlining_shader.hpp"

std::string OutliningShader::VERTEX_SHADER_FILE = "outlining_vertex_shader";
std::string OutliningShader::FRAGMENT_SHADER_FILE = "outlining_fragment_shader";

OutliningShader::OutliningShader() : ShaderProgram(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE) {
    transformation_matrix = new UniformMatrix4f("transformation_matrix");
    projection_matrix = new UniformMatrix4f("projection_matrix");
    view_matrix = new UniformMatrix4f("view_matrix");
    thickness = new UniformFloat("thickness");

    store_all_uniform_locations(std::vector<Uniform *> {
        transformation_matrix, projection_matrix, view_matrix, thickness
    });
}

OutliningShader::~OutliningShader() {
    delete transformation_matrix;
    delete projection_matrix;
    delete view_matrix;
    delete thickness;
}

void OutliningShader::bind_attributes() {
    bind_attribute(0, "in_position"); // 0 -> position
    bind_attribute(1, "in_normal"); // 1 -> normal
}

void OutliningShader::load_transformation_matrix(Matrix4f matrix) {
    transformation_matrix->load_matrix(matrix);
}

void OutliningShader::load_projection_matrix(Matrix4f matrix) {
    projection_matrix->load_matrix(matrix);
}

void OutliningShader::load_view_matrix(Camera camera) {
    Matrix4f matrix = CameraAlgebra::create_view_matrix(camera);

    view_matrix->load_matrix(matrix);
}
