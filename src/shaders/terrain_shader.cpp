/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * February 3, 2023
 */

#include "./shaders/terrain_shader.hpp"

std::string TerrainShader::VERTEX_SHADER_FILE = "terrain_vertex_shader";
std::string TerrainShader::FRAGMENT_SHADER_FILE = "terrain_fragment_shader";

TerrainShader::TerrainShader() : ShaderProgram(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE) {
    transformation_matrix = new UniformMatrix4f("transformation_matrix");
    projection_matrix = new UniformMatrix4f("projection_matrix");
    view_matrix = new UniformMatrix4f("view_matrix");
    light_position = new UniformVector3f("light_position");
    light_colour = new UniformVector3f("light_colour");
    shine_damper = new UniformFloat("shine_damper");
    reflectivity = new UniformFloat("reflectivity");
    sky_colour = new UniformVector3f("sky_colour");

    store_all_uniform_locations(std::vector<Uniform *> {
        transformation_matrix, projection_matrix, view_matrix, light_position, light_colour, shine_damper, reflectivity, sky_colour
    });
}

TerrainShader::~TerrainShader() {
    delete transformation_matrix;
    delete projection_matrix;
    delete view_matrix;
    delete light_position;
    delete light_colour;
    delete shine_damper;
    delete reflectivity;
    delete sky_colour;
}

void TerrainShader::bind_attributes() {
    bind_attribute(0, "in_position"); // 0 -> position
    bind_attribute(1, "in_normal"); // 1 -> normal
    bind_attribute(2, "in_texture_coordinates"); // 2 -> texture coordinates
}

void TerrainShader::load_transformation_matrix(Matrix4f matrix) {
    transformation_matrix->load_matrix(matrix);
}

void TerrainShader::load_projection_matrix(Matrix4f matrix) {
    projection_matrix->load_matrix(matrix);
}

void TerrainShader::load_view_matrix(Camera camera) {
    Matrix4f matrix = CameraAlgebra::create_view_matrix(camera);

    view_matrix->load_matrix(matrix);
}

void TerrainShader::load_light(Light light) {
    light_position->load_vector(light.get_position());
    light_colour->load_vector(light.get_colour());
}

void TerrainShader::load_specular_lighting(float shine_damper, float reflectivity) {
    this->shine_damper->load_float(shine_damper);
    this->reflectivity->load_float(reflectivity);
}

void TerrainShader::load_sky_colour(Vector3f sky_colour) {
    this->sky_colour->load_vector(sky_colour);
}

