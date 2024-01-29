/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#include "./shaders/entity_shader.hpp"

std::string EntityShader::VERTEX_SHADER_FILE = "entity_vertex_shader";
std::string EntityShader::FRAGMENT_SHADER_FILE = "entity_fragment_shader";

EntityShader::EntityShader() : ShaderProgram(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE) {
    transformation_matrix = new UniformMatrix4f("transformation_matrix");
    projection_matrix = new UniformMatrix4f("projection_matrix");
    view_matrix = new UniformMatrix4f("view_matrix");
    light_position = new UniformVector3f("light_position");
    light_colour = new UniformVector3f("light_colour");
    shine_damper = new UniformFloat("shine_damper");
    reflectivity = new UniformFloat("reflectivity");

    store_all_uniform_locations(std::vector<Uniform *> {
        transformation_matrix, projection_matrix, view_matrix, light_position, light_colour, shine_damper, reflectivity
    });
}

EntityShader::~EntityShader() {
    delete transformation_matrix;
    delete projection_matrix;
    delete view_matrix;
    delete light_position;
    delete light_colour;
    delete shine_damper;
    delete reflectivity;
}

void EntityShader::bind_attributes() {
    bind_attribute(0, "in_position"); // 0 -> position
    bind_attribute(1, "in_normal"); // 1 -> normal
    bind_attribute(2, "in_texture_coordinates"); // 2 -> texture coordinates
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

void EntityShader::load_light(Light light) {
    light_position->load_vector(light.get_position());
    light_colour->load_vector(light.get_colour());
}

void EntityShader::load_specular_lighting(float shine_damper, float reflectivity) {
    this->shine_damper->load_float(shine_damper);
    this->reflectivity->load_float(reflectivity);
}
