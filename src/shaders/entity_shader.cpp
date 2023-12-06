/*
 * Dylan Gilson
 * dylan.gilson@outlook.com
 * November 8, 2023
 */

#include "./shaders/entity_shader.hpp"

std::string EntityShader::VERTEX_SHADER_FILE = "./shaders/vertex_shader.glsl";
std::string EntityShader::FRAGMENT_SHADER_FILE = "./shaders/fragment_shader.glsl";

EntityShader::EntityShader() : ShaderProgram(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE) {
    
}

EntityShader::~EntityShader() {
    
}

void ShaderProgram::bind_attributes() {
    bind_attribute(0, "in_position"); // 0 -> position
    bind_attribute(1, "in_texture_coordinates"); // 1 -> texture coordinates
}
